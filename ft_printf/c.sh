#make -C libft/ fclean
#make -C libft/
gcc -Wall -Wextra -Werror -I libft/includes/ -c ft_printf.c
gcc -Wall -Wextra -Werror -I libft/includes/ -c main.c
gcc ft_printf.o main.o -L libft/ -lft
rm *.o
