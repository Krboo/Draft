#include "ft_printf.h"

static char	*ft_char2str(char c)
{
	char	*str;

	str = ft_strnew(2);
	str[0] = c;
	str[1] = 0;
	return (str);
}

static char	*parser(va_list pa, char *format)
{
	if (*format == '%')
		return("%");
	if (*format == 'd')
		return (ft_itoa(va_arg(pa, int)));
	if (*format == 's')
		return (va_arg(pa, char *));
	if (*format == 'c')
		return (ft_char2str(va_arg(pa, int)));
	return("NOPE");
}

int		ft_printf(char *format, ...)
{
	va_list 	pa;
	char		*str;
	char		*final;
	
	final = ft_strnew(1);
	str = NULL;
	va_start(pa, format);
	while (*format != '\0')
	{
		if (*format == '%')
			str = parser(pa, ++format);
		else
			str = ft_char2str(*format);
		final = ft_strjoin(final, str);
		++format;
	}
	ft_putstr(final);
	va_end(pa);
	return (0);
}
