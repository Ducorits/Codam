/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 15:36:21 by dritsema      #+#    #+#                 */
/*   Updated: 2021/10/15 15:56:37 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	srclen;

	srclen = ft_strlen(s1) + 1;
	dst = (char *)malloc(srclen * sizeof(char));
	if (dst)
		ft_strlcpy(dst, s1, srclen + 1);
	return (dst);
}
