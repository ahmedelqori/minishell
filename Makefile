NAME = minishell
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

SRC = ./src/minishell.c\
	  ./src/parsing/ft_get_current_path.c\
	  ./src/handle/cd_command.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(SRC) ./libft.a -o $(NAME) -lreadline

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all