LOG_CLEAR		= \033[2K
LOG_UP 			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

.PHONY: clean $(NAME) re fclean all
.SILENT:

# comp
NAME = fdf
CC = clang
LIBCC = make -C ../libft
CCFLAGS = -Wall -Wextra -Werror #-fsanitize=adress -g


# dir
D_SRC = srcs
D_INC = includes
D_LIB = ../libft
D_MLX = minilibx

# flags
F_LIB = -lft 
F_MLX = -framework OpenGL -framework AppKit -lmlx

# sources
SRC =\
     main.c \
     screen.c \
     write_image.c \
     mlx_init_render.c \
     get_file.c \
     get_fdf.c \
     put_fdf.c \
     errors.c \
	 utils.c \

INC = $(addprefix -I,$(D_INC))
LIB_INC = $(addprefix -I,$(addprefix $(D_LIB)/,$(D_INC)))
MLX_INC = $(addprefix -I,$(D_MLX))
SRCS = $(addprefix $(D_SRC)/,$(SRC))

# special chars
all: $(NAME)

libft: 
	$(MAKE) -C ../libft

$(NAME): libft comp

comp: 
	$(CC) -o $(NAME) $(SRCS) $(INC) $(LIB_INC) $(MLX_INC) -L$(D_LIB) -L$(D_MLX) $(F_LIB) $(F_MLX)



clean:
	rm -Rf $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
