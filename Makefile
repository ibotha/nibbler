CC = gcc
CPPC = g++

NAME = nibbler

CFLAGSOG =
CPPFLAGSOG = -std=c++17

FLAGS = -Wall -Werror -Wextra -I glfw/include -I glad/include -I SDL2/include -I includes -I SFML/include -I SFML/lib

SFMLTAR='SFML-clang.tar.gz'
SFML_DIR='SFML-2.5.0-macOS-clang'
DWNLD=sh -c '$$(curl -Lo $(SFMLTAR) --progress-bar https://www.sfml-dev.org/files/SFML-2.5.0-macOS-clang.tar.gz)'
UNTAR=sh -c '$$(tar -xzf $(SFMLTAR) && rm -rf $(SFMLTAR))'
CR_MV=sh -c '$$(mv $(SFML_DIR) ./SFML && cp -rf ./SFML/extlibs/* ./SFML/Frameworks/.)'

CFLAGS = $(CFLAGSOG) $(FLAGS)
CPPFLAGS = $(CPPFLAGSOG) $(FLAGS)

RPATH = -Wl,-rpath,$(PWD)/SFML/Frameworks

OPENGLCDEP = $(ODIR)/glad.o glfw/src/libglfw3.a -framework GLUT -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
SDLCDEP = SDL2/build/libSDL2main.a SDL2/build/libSDL2.a -framework AudioToolbox -framework CoreVideo -framework Carbon -framework ForceFeedback -framework IOKit -framework Cocoa -framework CoreAudio -liconv -lm  -Wl,-current_version,10.0.0 -Wl,-compatibility_version,1.0.0 -Wl,-undefined,error
SFMLCDEP = -F SFML/Frameworks $(RPATH) -framework sfml-graphics -framework sfml-audio -framework sfml-network -framework sfml-window -framework sfml-system

FILES = main.cpp Game.cpp Snoekie.cpp Food.cpp

OPENGLSRC = Renderers/OpenGLRenderer.cpp
SDLSRC = Renderers/SDLRenderer.cpp
SFMLSRC = Renderers/SFMLRenderer.cpp

OPENGLLIB = libOpengl.so
SDLLIB = libSDL.so
SFMLLIB = libSFML.so

OPENGLLIBDEP = Renderers/OpenGLRenderer.hpp
SDLLIBDEP = Renderers/SDLRenderer.hpp
SFMLLIBDEP = Renderers/SFMLRenderer.hpp

COMPILEDHPP = nibblerpch.hpp

ODIR = obj
SDIR = src
LDIR = lib

IDIR = inc

DEPS = IRenderer.hpp Game.hpp Snoekie.hpp IEntity.hpp Vec.hpp Food.hpp

OPENGLOBJ := $(patsubst %.cpp, $(ODIR)/%.o, $(OPENGLSRC))
SDLOBJ := $(patsubst %.cpp, $(ODIR)/%.o, $(SDLSRC))
SFMLOBJ := $(patsubst %.cpp, $(ODIR)/%.o, $(SFMLSRC))

OPENGLLIBDEP := $(patsubst %, $(IDIR)/%, $(OPENGLLIBDEP))
SDLLIBDEP := $(patsubst %, $(IDIR)/%, $(SDLLIBDEP))
SFMLLIBDEP := $(patsubst %, $(IDIR)/%, $(SFMLLIBDEP))

OPENGLLIB := $(patsubst %, $(LDIR)/%, $(OPENGLLIB))
SDLLIB := $(patsubst %, $(LDIR)/%, $(SDLLIB))
SFMLLIB := $(patsubst %, $(LDIR)/%, $(SFMLLIB))

OPENGLSRC := $(patsubst %, $(SDIR)/%, $(OPENGLSRC))
SDLSRC := $(patsubst %, $(SDIR)/%, $(SDLSRC))
SFMLSRC := $(patsubst %, $(SDIR)/%, $(SFMLSRC))

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

all: $(ODIR) $(LDIR) $(PCH) $(SDLLIB) $(SFMLLIB) $(OPENGLLIB) $(NAME)

GLFW:
	@echo "$(CYAN)Making\t\t$(GREEN)GLFW$(END)";
	@cd glfw && cmake .
	@make -C glfw

SDL2: SDL2.tar.gz
	mkdir -p SDL2
	mkdir -p SDL2/build
	tar -xf SDL2.tar.gz -C SDL2 --strip-components 1
	cd SDL2/build && cmake .. && make

SDL2.tar.gz:
	curl -o SDL2.tar.gz https://www.libsdl.org/release/SDL2-2.0.9.tar.gz

SFML: SFMLTAR

SFMLTAR:
	mkdir -p $(SFML_DIR)
	$(DWNLD)
	$(UNTAR)
	$(CR_MV)
# FREETYPE: freetype.tar.gz
# 	mkdir -p FREETYPE
# 	mkdir -p FREETYPE/build
# 	tar -xf freetype.tar.gz -C FREETYPE --strip-components 1
# 	cd FREETYPE/build && cmake .. && make

# freetype.tar.gz:
# 	curl -o freetype.tar.gz https://tenet.dl.sourceforge.net/project/freetype/freetype2/2.10.1/freetype-2.10.1.tar.gz

$(OPENGLLIB): GLFW $(ODIR)/glad.o $(OPENGLOBJ) $(OPENGLLIBDEP)
	@echo "$(CYAN)Compiling\t$(GREEN)$(OPENGLLIB)$(END)"
	$(CPPC) -shared $(OPENGLOBJ) -o $@ $(CPPFLAGS) $(OPENGLCDEP)

$(SFMLLIB): GLFW $(ODIR)/glad.o $(SFMLOBJ) $(SFMLLIBDEP)
	@echo "$(CYAN)Compiling\t$(GREEN)$(SFMLLIB)$(END)"
	@$(CPPC) -shared $(SFMLOBJ) -o $@ $(CPPFLAGS) $(SFMLCDEP)

$(SDLLIB): SDL2 $(SDLOBJ) $(SDLLIBDEP)
	@echo "$(CYAN)Compiling\t$(GREEN)$(SDLLIB)$(END)"
	@$(CPPC) -shared $(SDLOBJ) -o $@ $(CPPFLAGS) $(SDLCDEP)

$(NAME): $(ODIR) $(OBJ)
	@echo "$(CYAN)Linking\t\t$(GREEN)$(NAME)$(END)";
	$(CPPC) -o $(NAME) $(OBJ) $(CPPFLAGS) -I $(IDIR) -L$(LDIR)

%.hpp.gch: %.hpp
	@echo "$(YELLOW)Compiling\t$(GREEN)$@$(END)";
	$(CPPC) -o $@ $< $(CPPFLAGS) -I $(IDIR)

$(ODIR)/glad.o: glad/src/glad.c $(DEPS) $(COMPILEDHPP)
	@echo "$(CYAN)Compiling\t$(GREEN)$@$(END)";
	@$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS) $(COMPILEDHPP)
	@echo "$(CYAN)Compiling\t$(GREEN)$@$(END)";
	@$(CPPC) -c -o $@ $< $(CPPFLAGS) -I $(IDIR) -I . -include $(COMPILEDHPP)

$(LDIR):
	mkdir -p $(LDIR)

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
	@rm -rf $(OPENGLLIB)
	@rm -rf $(SDLLIB)
	@rm -rf $(SFMLLIB)
	@make clean -C glfw
	@rm -rf SDL2
	@rm -rf SDL2.tar.gz

re: fclean all

shallowre: clean all

.PHONY: re clean all fclean GLUT GLFW $(ODIR) SDL2 FREETYPE
