# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmartine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/09 12:57:33 by pmartine          #+#    #+#              #
#    Updated: 2016/02/09 13:17:05 by pmartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME =		ft_ls
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
LDLIBS =	-lft
RM =		/bin/rm -rf
OBJ =		$(SRC:.c=.o)
EXT =		$(NAME:.a=.h)
EXT	+=		Makefile

SRC = srcs/main.c   

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft/
	@$(CC) $(CFLAGS) -c $(SRC) -I ./includes
	mv *.o srcs
	@echo "Objects created" 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft
	@echo "Program created"

clean:
	@echo "Objects are being removed ..." 
	@$(RM) $(OBJ)
	@make -C libft/ clean

fclean: clean
	@echo "$(NAME) is being removed ..."
	@$(RM) $(OBJ) $(NAME)
	@make -C libft/ fclean

re: fclean all
