/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printstr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/06 15:45:58 by dritsema      #+#    #+#                 */
/*   Updated: 2021/11/09 13:12:31 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_printstr(char *s)
{
	int	slen;

	if (!s)
		return (write(1, "(null)", 6));
	slen = ft_strlen(s);
	return (write(1, s, slen));
}
