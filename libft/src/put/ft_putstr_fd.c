/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/23 15:26:16 by dritsema      #+#    #+#                 */
/*   Updated: 2021/10/28 23:22:00 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	slen;

	if (s)
	{
		slen = ft_strlen(s);
		write(fd, &*s, slen);
	}
}
