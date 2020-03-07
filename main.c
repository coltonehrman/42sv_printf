#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	
	ft_printf("testing%-5c%05c%1c\n", 'a', 'b', 'c');
	printf("testing%-5c%05c%1c\n", 'a', 'b', 'c');

	ft_printf("testing%01c%05c%1c\n", 'a', 'b', 'c');
	printf("testing%01c%05c%1c\n", 'a', 'b', 'c');

	ft_printf("testing%01c%05c%1c\n", 'a', 'b', 'c');
	printf("testing%01c%05c%1c\n", 'a', 'b', 'c');

	ft_printf("testing%%\n", 'a');
	printf("testing%%\n", 'a');
	

	ft_printf("%x\n", 42);
	printf("%x\n", 42);

	ft_printf("%.c\n", 1);
	printf("%.c\n", 1);

	ft_printf("%.4d\n", 4);
	printf("%.4d\n", 4);

	/*
	ft_printf("%s", "abc");
	ft_printf("%u", 42);
	ft_printf("{%10d}", 42);
	ft_printf("{%*3d}", 5, 0);
	ft_printf("{%-10d}", 42);
	ft_printf("111%s333%s555", "222", "444");
	//ft_printf("%p", &i);
	ft_printf("%*d", 5, 42);
	ft_printf("%X", 42);
	ft_printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l);
	ft_printf("%hhd%hhd", 1, 42);
	ft_printf("%+d", 42);
	ft_printf("%#o", 42);
	//ft_printf("s: %s, p: %p, d:%d", "a string", &test_simple_mix, 42);
	ft_printf("%o", 42);
	ft_printf("%ld%ld", 0l, 42l);
	ft_printf("%s %d %p %% %x", "bonjour ", 42, &free, 42);
	ft_printf("%#.o, %#.0o", 0, 0);
	ft_printf("%hd%hd", (short int)0, (short int)42);
	ft_printf("{%010d}", 42);
	ft_printf("%");
	ft_printf("%lld%lld", 0ll, 42ll);
	ft_printf("%.4o", 42);
	ft_printf("%*.*d", 0, 3, 0);
	ft_printf("%i", 42);
	ft_printf("%d", 42);
	ft_printf("%.0p, %.p", 0, 0);
	ft_printf("%u", -42);
	ft_printf("%o, %ho, %hho", -42, -42, -42);
	ft_printf("%.4s", "42");
	ft_printf("% d", 9999);
	ft_printf("{% +d}", 42);
	//ft_printf("%hhd - %hhd", SHRT_MAX - 42, SHRT_MAX - 4200);
	*/

	return (1);	
}