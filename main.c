#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	ft_printf("testing%c%c%c\n", 'a', 'b', 'c');
	printf("testing%c%c%c\n", 'a', 'b', 'c');
	
	ft_printf("testing%c%c%c\n", 'a', 'b');
	printf("testing%c%c%c\n", 'a', 'b');

	return (1);	
}
