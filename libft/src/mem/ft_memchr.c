/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 19:04:49 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/26 19:04:50 by dritsema      ########   odam.nl         */
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
