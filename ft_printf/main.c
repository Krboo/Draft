#include "ft_printf.h"

int	main()
{
	char	*test;

	test = "GG";
	ft_printf(CBLUE"char = %c int = %d %% Chaine = %s ChaineVariable = %s\n",'y', 123,  "Krboo is beautiful !", test );
	ft_printf("-----------\n"CEND);
	printf(CRED"char = %c int = %d %% Chaine = %s ChaineVariable = %s\n", 'y', 123,  "Krboo is beautiful !", test );
	printf("-----------\n"CEND);
	return (0);
}
