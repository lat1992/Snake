##
## Makefile for  in /home/tsai_g/tsai/nibbler
## 
## Made by tsai guillaume
## Login   <tsai_g@epitech.net>
## 
## Started on  Mon Mar 17 14:01:14 2014 tsai guillaume
## Last update Sun Apr  6 18:33:56 2014 mauhoi wu
##

NAME		=	nibbler

CC		=	g++

RM		=	rm -rf

CXXFLAGS	+=	-Iinclude -fPIC

LDFLAGS		=	-W -Wall -Werror -Wextra -ldl -rdynamic

SRCS		=	src/main.cpp		\
			src/config.cpp		\
			src/game.cpp		\
			src/player.cpp		\
			src/snake.cpp		\
			src/body.cpp		\
			src/point.cpp		\
			src/exception.cpp

OBJS		=	$(SRCS:.cpp=.o)

SDL		=	lib_nibbler_sdl.so

SRC_SDL		=	sdl/sdl_core.cpp

OBJ_SDL		=	$(SRC_SDL:.cpp=.o)

SDLFLAGS	=	-shared -lSDL -lm -lSDL_image -lpthread -fPIC

OPENGL		=	lib_nibbler_opengl.so

SRC_OPENGL	=	opengl/opengl_core.cpp

OBJ_OPENGL	=	$(SRC_OPENGL:.cpp=.o)

OPENGLFLAGS	=	-shared -lX11 -lXi -lXmu -lglut -lGL -lGLU -lSDL -lm -fPIC

ALL		=	lib_nibbler_allegro.so

SRC_ALL		=	allegro/graphic.cpp

OBJ_ALL		=	$(SRC_ALL:.cpp=.o)

ALLFLAGS	=	-shared -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -fPIC

$(NAME)		:	$(OBJS) $(OBJ_SDL) $(OBJ_OPENGL) $(OBJ_ALL)
			$(CC) -o $(NAME) $(OBJS)  $(LDFLAGS)
			$(CC) -o $(SDL) $(OBJ_SDL) $(SDLFLAGS)
			$(CC) -o $(OPENGL) $(OBJ_OPENGL) $(OPENGLFLAGS)
			$(CC) -o $(ALL) $(OBJ_ALL) $(ALLFLAGS)

all		:	$(NAME)

clean		:
			$(RM) $(OBJS) $(OBJ_SDL) $(OBJ_ALL) $(OBJ_OPENGL)

fclean		:	clean
			$(RM) $(NAME) $(SDL) $(ALL) $(OPENGL)

re		:	fclean all

.PHONY		:	all clean make re fclean
