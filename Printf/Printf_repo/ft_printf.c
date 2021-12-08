/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 14:43:41 by dritsema      #+#    #+#                 */
/*   Updated: 2021/11/09 14:12:27 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

static int	doit(va_list args, const char **s)
{
	int	count;

	count = 0;
	if ((*s)[1] == 'i')
		count = ft_printnbr(va_arg(args, int));
	if ((*s)[1] == 'd')
		count = ft_printnbr(va_arg(args, int));
	if ((*s)[1] == 'u')
		count = ft_printun(va_arg(args, unsigned int));
	if ((*s)[1] == 's')
		count = ft_printstr(va_arg(args, char *));
	if ((*s)[1] == 'c')
		count = ft_printchar(va_arg(args, int));
	if ((*s)[1] == 'x')
		count = ft_printhex(va_arg(args, unsigned int));
	if ((*s)[1] == 'X')
		count = ft_upprinthex(va_arg(args, unsigned int));
	if ((*s)[1] == 'p')
	{
		count += write(1, "0x", 2);
		count += ft_printhex(va_arg(args, unsigned long));
	}
	if ((*s)[1] == '%')
		count = ft_printchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
	{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			count += doit(args, &s);
			s = s + 2;
		}
		else
		{
			ft_printchar(*s);
			count++;
			s++;
		}
	}
	va_end(args);
	return (count);
}
