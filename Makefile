NAME = run

SRC =	main.c				ft_parse.c		ft_errors.c		ft_free_utils.c		\
		ft_general_utils.c	ft_draw.c		ft_keyhook.c	ft_keyhook2.c		\
		ft_params.c			ft_mouse.c		ft_math_utils.c	ft_color_utils.c	\
		ft_colors.c			ft_valid.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -O0 -g

RM = rm -rf

LIB = libft/libft.a
LHDR = libft/libft.h

MHDR = fdf.h

MAKE = Makefile

all: $(LIB) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@


$(LIB): $(LHDR) $(MAKE)
	make -C ./libft/

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


$(OBJ): $(MHDR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all