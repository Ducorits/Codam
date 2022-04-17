/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/23 15:57:11 by dritsema      #+#    #+#                 */
/*   Updated: 2021/10/23 16:13:23 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recurse(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	n = n % 10 + 48;
	write(fd, &n, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	ncpy;

	ncpy = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		ncpy = n * -1;
	}
	recurse(ncpy, fd);
}
