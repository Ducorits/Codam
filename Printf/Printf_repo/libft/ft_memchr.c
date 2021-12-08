/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 15:04:06 by dritsema      #+#    #+#                 */
/*   Updated: 2021/11/03 15:04:59 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;

	src = (const unsigned char *)s;
	while (n > 0)
	{
		if (*src == (unsigned char)c)
		{
			return ((void *)src);
		}
		src++;
		n--;
	}
	return (NULL);
}
