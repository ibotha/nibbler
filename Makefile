CC = gcc
CPPC = g++

NAME = nibbler

CFLAGSOG = 
CPPFLAGSOG = -std=c++17

FLAGS = -Wall -Werror -Wextra -I glfw/include -I glad/include

CFLAGS = $(CFLAGSOG) $(FLAGS)
CPPFLAGS = $(CPPFLAGSOG) $(FLAGS)

FILES = main.cpp

COMPILEDHPP = nibblerpch.hpp

ODIR = obj
SDIR = src

IDIR = inc

DEPS = 

OBJ := $(patsubst %.cpp, $(ODIR)/%.o, $(FILES))
OBJ := $(patsubst %.c, $(ODIR)/%.o, $(OBJ))
SRC := $(patsubst %, $(SDIR)/%, $(FILES))
DEPS := $(patsubst %, $(IDIR)/%, $(DEPS))
PCH := $(patsubst %, %.gch, $(COMPILEDHPP))
COMPILEDHPP := $(patsubst %, %, $(COMPILEDHPP))

BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
END=\033[0m

all: GLFW $(NAME)

GLFW:
	@echo "$(CYAN)Making\t\t$(GREEN)GLFW$(END)";
	@cmake glfw
	@-make -s -C glfw

$(NAME): $(ODIR) $(ODIR)/glad.o $(PCH) $(OBJ)
	@echo "$(CYAN)Linking\t\t$(GREEN)$(NAME)$(END)";
	@$(CPPC) -o $(NAME) $(OBJ) $(CPPFLAGS) -I $(IDIR) $(ODIR)/glad.o glfw/src/libglfw3.a -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

%.hpp.gch: %.hpp
	@echo "$(YELLOW)Compiling\t$(GREEN)$@$(END)";
	$(CPPC) -o $@ $< $(CPPFLAGS) -I $(IDIR)


$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS) $(COMPILEDHPP)
	@echo "$(CYAN)Compiling\t$(GREEN)$@$(END)";
	@$(CPPC) -c -o $@ $< $(CPPFLAGS) -I $(IDIR) -I . -include $(COMPILEDHPP)

$(ODIR)/glad.o: glad/src/glad.c $(DEPS) $(COMPILEDHPP)
	@echo "$(CYAN)Compiling\t$(GREEN)$@$(END)";
	@$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR):
	@echo "$(CYAN)Creating\t$(GREEN)$(ODIR)$(END)";
	@cd $(SDIR) && \
	find . -type d > ../hold.txtAVM && \
	cd .. && \
	mkdir -p $(ODIR) && \
	cd $(ODIR) && \
	xargs mkdir -p < ../hold.txtAVM;
	@rm hold.txtAVM;

clean:
	@echo "$(RED)Cleaning\t$(END)";
	@rm -rf $(ODIR)
	@rm -rf $(PCH)

fclean: clean
	@echo "$(RED)Removing\t$(GREEN)$(NAME)$(END)";
	@rm -rf $(NAME)
	@make clean -C glfw

re: fclean all

shallowre: clean all

.PHONY: re clean all fclean GLFW