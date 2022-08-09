NAME = fractol

SRC = main.c draw.c fractals.c 

OBJ = ${SRC:%.c=%.o}

FLAGS =  -Wall -Wextra -Werror 

COPILATION =  -I /usr/local/include  -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

%.o:%.c
		cc $(FLAGS)  -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) $(COPILATION) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ) 

fclean : 
	rm -rf  $(NAME) 
re : fclean all