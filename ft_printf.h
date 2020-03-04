#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

enum ArgType { C };

typedef struct	s_arg_list {
	enum ArgType		type;
	struct s_arg_list	*next;
}				t_arg_list;

int	ft_printf(const char *format, ...);
#endif
