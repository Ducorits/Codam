/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 20:18:00 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/26 20:49:29 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		((unsigned char *) dst)[i] = ((const unsigned char *) src)[i];
		i++;
		n--;
	}
	return (dst);
}
