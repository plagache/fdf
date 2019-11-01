NAME= fdf

SRCS= main.c\
	  parsing.c\
	  key_press.c\
	  data_man.c\
	  tracer.c\
	  rotate.c\
	  line.c\
	  clean.c\

OBJ= $(SRCS:.c=.o)

LIBDIR= libft

MINILIB = minilibx_macos
LIBA = $(LIBDIR)/libft.a
LIBA += $(MINILIB)/libmlx.a

CFLAGS= -Wall -Werror -Wextra
LFLAGS= -framework OpenGL -framework AppKit 

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	@make -C $(MINILIB) &> /dev/null
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBA) $(LFLAGS) 
	@echo "fdf build complete"

%.o : %.c
	@gcc -I $(LIBDIR) $(CFLAGS) -o $@ -c $<

clean:
		@rm -rf $(OBJ)
		@echo "fdf objects cleaned"
		@make clean -C $(LIBDIR)
		@make clean -C $(MINILIB)

fclean:
		@make fclean -s -C $(LIBDIR)
		@make clean -C $(MINILIB)
		@rm -f $(NAME)
		@rm -rf $(OBJ)
		@echo "fdf objects cleaned"
		@echo "fdf project cleaned"

re: fclean all

.PHONY: all clean fclean re
