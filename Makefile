NAME= fdf

SRCS= main.c\
	  parsing.c\
	  key_press.c\
	  data_man.c\

OBJ= $(SRCS:.c=.o)

LIBDIR= libft

LIBA = $(LIBDIR)/libft.a
#LIBA += minilibx/libmlx.a
LIBA += minilibx_macos/libmlx.a

CFLAGS= -Wall -Werror -Wextra
#CFLAGS += -g3 -fsanitize=address -fno-omit-frame-pointer

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIBDIR)
	@#gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBA) -lXext -lX11
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBA) -framework OpenGL -framework AppKit 
	@echo "fdf build complete"

%.o : %.c
	@gcc -I $(LIBDIR) $(CFLAGS) -o $@ -c $<

clean:
		@rm -rf $(OBJ)
		@echo "fdf objects cleaned"
		@make clean -C $(LIBDIR)

fclean:
		@make fclean -s -C $(LIBDIR)
		@rm -f $(NAME)
		@rm -rf $(OBJ)
		@echo "fdf objects cleaned"
		@echo "fdf project cleaned"

re: fclean all

.PHONY: all clean fclean re
