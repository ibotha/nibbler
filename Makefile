CC = g++

NAME = nibbler

FLAGS = -Wall -Werror -Wextra -std=c++17

FILES = main.cpp

COMPILEDHPP = nibblerpch.hpp

ODIR = obj
SDIR = src

IDIR = inc

DEPS = 

OBJ := $(patsubst %.cpp, $(ODIR)/%.o, $(FILES))
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

all: $(NAME)

$(NAME): $(ODIR) $(PCH) $(OBJ)
	@echo "$(CYAN)Linking\t\t$(GREEN)$(NAME)$(END)";
	@$(CC) -o $(NAME) $(OBJ) $(FLAGS) -I $(IDIR)

%.hpp.gch: %.hpp
	@echo "$(YELLOW)Compiling\t$(GREEN)$@$(END)";
	@$(CC) -o $@ $< $(FLAGS) -I $(IDIR)


$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS) $(COMPILEDHPP)
	@echo "$(CYAN)Compiling\t$(GREEN)$@$(END)";
	@$(CC) -c -o $@ $< $(FLAGS) -I $(IDIR) -I . -include $(COMPILEDHPP)

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

re: fclean all

.PHONY: re clean all fclean