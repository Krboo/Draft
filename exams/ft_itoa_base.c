# include <stdlib.h>

int		intlen(int value, int base)
{
	int i;

	i = 0;
	if (value == 0)
		return (1);
	if (value < 0)
	{
		value = value * -1;
		if (base == 10)
			i++;
	}
	while (value != 0)
	{
		value = value / base;
		i++;
	}
	return (i);
}
char    *ft_itoa_base(int value, int base)
{
	int sign;
	char *result;
	int len;
	int c;

	len = intlen(value, base);
	if (base < 2 || base > 16)
		return (NULL);
	if (value < 0)
		sign = -1;
	else
		sign = 1;
	result = malloc(sizeof(char) * len + 1);
	result[len] = '\0';
	len--;
	if (value == 0)
		result[0] = '0';
	if (value < 0 && base == 10)
		result[0] = '-';
	while (value != 0)
	{
		c = '0';
		if (value % base * sign >= 10)
			c = c + 7;
		result[len] = value % base * sign + c;

		len--;
		value = value / base;
	}
	return (result);
}
