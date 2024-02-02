# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 09:23:13 by ael-qori          #+#    #+#              #
#    Updated: 2024/02/02 12:47:50 by ael-qori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

SRC = ./src/minishell.c \
      ./src/prompt/prompt.c\
	  ./src/history/history.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) ./libft.a -o $(NAME) -lreadline

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all