#include <unistd.h>

void	ft_putnbr_hex(int octet, int rem)
{
	char const *base = "0123456789abcdef";

	if (rem > 1)
		ft_putnbr_hex(octet >> 4, rem - 1);
	write(1, base + (octet % 16), 1);
}

void	sp_putchar(unsigned char const *ptr)
{
	char const c = *ptr;

	if (' ' <= c && c <= '~')
		write(1, ptr, 1);
	else
		write(1, ".", 1);
}

void	ft_print_spaces(int a)
{
	write(1, "  ", 2);
	if (a % 2)
		write(1, " ", 1);
}

void	print_memory(const void *addr, size_t size)
{
	size_t				i;
	size_t				a;
	unsigned char const *ptr = addr;

	i = 0;
	while (i < size)
	{
		a = -1;
		while (++a < 16 && a + i < size)
		{
			ft_putnbr_hex(*(ptr + i + a), 2);
			if (a % 2)
				write(1, " ", 1);
		}
		while (a < 16)
		{
			ft_print_spaces(a);
			a++;
		}
		a = -1;
		while (++a < 16 && a + i < size)
			sp_putchar(ptr + a + i);
		write(1, "\n", 1);
		i += 16;
	}
}
