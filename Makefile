NAME = RayMarch
FLAGS =

MT_FILES = 		\
		MT_vec	\
		MT		\

SDLX_FILES = 		\
		SDLX_init	\
		SDLX_utils	\
		SDLX		\

INCLUDES = -I incl/ -I ~/.brew/
LIB = -L ~/.brew/lib -l SDL2 -l sdl2_image


SRC_DIR = srcs/
BIN_DIR = bin/

FILENAMES = 							\
	$(addprefix MT/, $(MT_FILES))		\
	$(addprefix SDLX/, $(SDLX_FILES))	\
	dist_funcs							\
	main								\
	render								\
			

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILENAMES)))
OBJS = $(addprefix $(BIN_DIR), $(addsuffix .o, $(FILENAMES)))


all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(SRCS) $(LIB)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)%.o: %.c
	mkdir -p $(BIN_DIR)$(dir $<)
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

run: re
	./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
