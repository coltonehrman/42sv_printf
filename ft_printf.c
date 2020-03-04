#include "ft_printf.h"

t_arg_list	*parse_arg_list(const char *format)
{
	t_arg_list	*root;
	t_arg_list	*arg_list;
	int			incoming_arg;

	arg_list = 0;
	root = arg_list;
	incoming_arg = 0;
	while (*format)
	{
		if (incoming_arg)
		{
			incoming_arg = 0;
			if (*format == 'c')
				arg_list->type = C;
		}
		else if (*format == '%')
		{
			incoming_arg = 1;
			if (!arg_list)
				arg_list = (t_arg_list *)malloc(sizeof(t_arg_list));
			else
			{
				arg_list->next = (t_arg_list *)malloc(sizeof(t_arg_list));
				arg_list = arg_list->next;
			}
			if (!root)
				root = arg_list;
			arg_list->next = 0;
		}
		++format;
	}
	return (root);
}

int			ft_printf(const char *format, ...)
{
	int			incoming_arg;
	int			*int_data;
	va_list		ap;
	t_arg_list	*arg_list;

	va_start(ap, format);
	arg_list = parse_arg_list(format);
	incoming_arg = 0;
	while (*format)
	{
		if (incoming_arg)
		{
			incoming_arg = 0;
			if (arg_list->type == C)
			{
				int_data = (int *)malloc(sizeof(int));
				*int_data = va_arg(ap, int);
				write(1, int_data, 1);
				free(int_data);
				int_data = 0;
			}
		}
		else if (*format == '%')
		{
			incoming_arg = 1;
		}
		else
			write(1, format, 1);
		++format;
	}
	va_end(ap);

	return (1);
}
