CC = gcc

CFLAGS = -Wall -Wextra -Werror

ENDFLAGS = -framework OpenGL -framework AppKit

NAME = fractol

SRCS = main.c key_stuff.c gradient.c \
	 arithmetic.c julia.c \

OBJ = $(SRCS:.c=.o)

LIBS = ./minilibx_macos/libmlx.a ./libft/libft.a

.PHONY: all comp clean fclean re

all: $(NAME)

$(OBJ): $(SRCS)
	$(CC) -c $(CFLAGS) $(SRCS)

$(LIBS): 
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx_macos

$(NAME): $(OBJ) $(LIBS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIBS) $(ENDFLAGS)

clean:
	@rm -f $(OBJ)
	$(MAKE) -C ./libft/ clean
	$(MAKE) -C ./minilibx_macos/ clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C ./libft/ fclean
	$(MAKE) -C ./minilibx_macos/ clean


re: fclean all
