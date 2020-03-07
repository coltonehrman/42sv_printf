#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

enum	e_arg_flag { Minus = '-', Plus = '+', Space = ' ', Hashtag = '#',
	Zero = '0' };

enum	e_arg_specifier { Decimal1 = 'd', Decimal2 = 'i', UDecimal = 'u',
	UOctal = 'o', UHex = 'x', UHexUpper = 'X', Float = 'f', FloatUpper = 'F',
	Scientific = 'e', ScientificUpper = 'E', ShortestRep = 'g',
	ShortestRepUpper = 'G', HexFloat = 'a', HexFloatUpper = 'A', Char = 'c',
	String = 's', Address = 'p', Nothing = 'n', Percent = '%' };

typedef struct	s_arg_flag {
	enum e_arg_flag		flag;
	struct s_arg_flag	*next;
}				t_arg_flag;

typedef struct	s_arg_list {
	struct s_arg_flag		*flags;
	int						width;
	enum e_arg_specifier	specifier;
	struct s_arg_list		*next;
}				t_arg_list;

int	ft_printf(const char *format, ...);
#endif