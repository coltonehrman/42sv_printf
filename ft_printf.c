/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cehrman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:20:40 by cehrman           #+#    #+#             */
/*   Updated: 2020/03/05 12:20:43 by cehrman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int			is_flag(const char c)
{
	return (c == Minus || c == Plus || c == Space || c == Hashtag || c == Zero);
}

int			is_specifier(const char c)
{
	return (c == Decimal1 || c == Decimal2 || c == UDecimal || c == UOctal
			|| c == UHex || c == UHexUpper || c == Float || c == FloatUpper
			|| c == Scientific || c == ScientificUpper || c == ShortestRep
			|| c == ShortestRepUpper || c == HexFloat || c == HexFloatUpper
			|| c == Char || c == String || c == Address || c == Nothing
			|| c == Percent);
}

t_arg_list	*create_arg_list()
{
	t_arg_list *arg_list;

	arg_list = (t_arg_list *)malloc(sizeof(t_arg_list));
	arg_list->flags = 0;
	arg_list->width = -1;
	arg_list->specifier = -1;
	arg_list->next = 0;
	return (arg_list);
}

t_arg_flag	*create_arg_flag(char flag)
{
	t_arg_flag *arg_flag;

	arg_flag = (t_arg_flag *)malloc(sizeof(t_arg_flag));
	arg_flag->flag = flag;
	arg_flag->next = 0;
	return (arg_flag);
}

t_arg_list	*parse_arg(const char *format)
{
	int			i;
	int			width;
	char		c;
	t_arg_list	*arg_list;
	t_arg_flag	*flags;

	i = 0;
	arg_list = create_arg_list();
	// look for any flags
	while ((c = format[i]) && is_flag(c))
	{
		if (!(arg_list->flags))
			arg_list->flags = create_arg_flag(c);
		else
		{
			flags = arg_list->flags;
			while (flags->next)
				flags = flags->next;
			flags->next = create_arg_flag(c);
		}
		++i;
	}
	if ((c = format[i]) && ft_isdigit(c))
	{
		width = ft_atoi(format + i);
		arg_list->width = width;
		i += ft_count_digits(width);
	}
	if ((c = format[i]) && c == '.')
	{
		// parse precision
	}
	if ((c = format[i]) && c == ' ')
	{
		// parse length
	}
	if ((c = format[i]) && is_specifier(c))
	{
		arg_list->specifier = c;
	}
	return (arg_list);
}

t_arg_list	*parse_args(const char *format)
{
	t_arg_list	*root;
	t_arg_list	*arg_list;
	t_arg_list	*tmp;
	char		c;
	int			i;
	int			incoming_arg;

	arg_list = 0;
	root = arg_list;

	i = 0;
	incoming_arg = 0;
	while ((c = format[i]))
	{
		if (incoming_arg)
		{
			incoming_arg = 0;
			tmp = parse_arg((format + i));
			if (!arg_list)
			{
				arg_list = tmp;
				root = arg_list;
			}
			else
			{
				while (arg_list->next)
					arg_list = arg_list->next;
				arg_list->next = tmp;
			}
		}
		else if (c == Percent)
			incoming_arg = 1;
		++i;
	}
	return (root);
}

char		*clean_format(const char *format)
{
	int		i;
	int		trim;
	char	*cleaned_format;
	char	*tmp;
	char	*start;
	char	*end;
	char	c;
	
	i = 0;
	cleaned_format = ft_strdup(format);
	while ((c = cleaned_format[i]))
	{
		if (c == Percent)
		{
			++i;
			trim = 0;
			while ((c = cleaned_format[i + trim]) && is_flag(c))
				++trim;
			if ((c = cleaned_format[i + trim]) && ft_isdigit(c))
				trim += ft_count_digits(ft_atoi(format + i + trim));
			if ((c = cleaned_format[i + trim]) && c == '.')
			{
				// parse precision
			}
			if ((c = cleaned_format[i + trim]) && c == ' ')
			{
				// parse length
			}
			if ((c = cleaned_format[i + trim]) && is_specifier(c))
				++trim;
			tmp = cleaned_format;
			start = ft_strsub(cleaned_format, 0, i);
			end = ft_strsub(cleaned_format, i + trim, ft_strlen(cleaned_format));
			cleaned_format = ft_strjoin(start, end);
			ft_strdel(&tmp);
			ft_strdel(&start);
			ft_strdel(&end);
			--i;
		}
		++i;
	}
	return (cleaned_format);
}

void		debug_args(t_arg_list	*arg_list)
{
	int i = 0;
	t_arg_flag *flags;
	
	while (arg_list)
	{
		printf("[%d]: \n", i++);
		flags = arg_list->flags;
		printf("flags: [");
		while (flags)
		{
			printf("%c,", flags->flag);
			flags = flags->next;
		}
		printf("]\n");
		printf("width: %d\n", arg_list->width);
		printf("specifier: %c\n\n", arg_list->specifier);
		arg_list = arg_list->next;
	}
}

int			has_flag(t_arg_flag *flags, enum e_arg_flag flag)
{
	while (flags)
	{
		if (flags->flag == flag)
			return (1);
		flags = flags->next;
	}
	return (0);
}

int			count_digits_base(unsigned int n, int base)
{
	if (n < (unsigned int)base)
		return (1);
	return (1 + count_digits_base(n / base, base));
}

char		*itoa_base(unsigned int n, int base)
{
	char	char_bases[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
					'8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	char	*str;
	int		num_digits;

	num_digits = count_digits_base(n, base);
	str = ft_strnew(num_digits + 1);
	str[num_digits] = 0;
	while (num_digits--)
	{
		str[num_digits] = char_bases[n % base];
		n /= base;
	}
	return (str);
}

int			convert_n_print(t_arg_list *arg, va_list ap)
{
	int printed;

	printed = 0;
	if (arg->specifier == Char)
	{
		ft_putchar(va_arg(ap, int));
		++printed;
	}
	else if (arg->specifier == UHex || arg->specifier == UHexUpper)
	{
		ft_putstr(itoa_base(va_arg(ap, unsigned int), 16));
		// need to change for right number of characters printed
		++printed;
	}
	else if (arg->specifier == Percent)
	{
		ft_putchar('%');
		++printed;
	}
	return (printed);
}

int			print_with_arg(t_arg_list *arg_list, va_list ap)
{
	int		printed;
	char	empty_char;
	char	*str;

	printed = 0;
	empty_char = ((has_flag(arg_list->flags, Zero)) ? '0' : ' ');
	if (arg_list->width > 0)
	{
		str = ft_strnew(arg_list->width);
		ft_memset(str, empty_char, arg_list->width - 1);
		str[arg_list->width - 1] = 0;
	}
	else
		str = ft_strnew(0);
	if (has_flag(arg_list->flags, Minus))
	{
		printed += convert_n_print(arg_list, ap);
		ft_putstr(str);
		printed += ft_strlen(str);
	}
	else
	{
		ft_putstr(str);
		printed += ft_strlen(str);
		printed += convert_n_print(arg_list, ap);
	}
	ft_strdel(&str);
	return (printed);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_arg_list	*arg_list;
	char		*cleaned_format;
	int			printed;

	va_start(ap, format);
	arg_list = parse_args(format);
	cleaned_format = clean_format(format);
	////////////////////////
	// debug_args(arg_list);
	/////////////////////////
	printed = 0;
	while (*cleaned_format)
	{
		if (*cleaned_format == '%')
		{
			if (arg_list)
			{
				printed += print_with_arg(arg_list, ap);
				arg_list = arg_list->next;
			}
			else
				ft_printf("ERROR! Args are not matching up.");
		}
		else
		{
			ft_putchar(*cleaned_format);
			++printed;
		}
		++cleaned_format;
	}
	va_end(ap);

	return (printed);
}