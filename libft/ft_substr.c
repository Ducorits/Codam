/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 16:25:41 by dritsema      #+#    #+#                 */
/*   Updated: 2021/10/28 23:06:01 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	malloc_size;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	else if (slen >= (len + (start + 1)))
		malloc_size = len + 1;
	else
		malloc_size = slen - start + 1;
	sub = (char *)malloc(malloc_size * sizeof(char));
	if (sub)
	{
		ft_memcpy(sub, (s + start), malloc_size);
		sub[malloc_size - 1] = '\0';
	}
	return (sub);
}
