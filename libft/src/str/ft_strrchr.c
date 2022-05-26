/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 12:39:36 by dritsema      #+#    #+#                 */
/*   Updated: 2021/10/08 19:05:05 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*b;

	i = 0;
	b = (char *) s + i;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			b = (char *) s + i;
		i++;
	}
	if (s[i] == c)
		b = (char *) s + i;
	if (*b == (char) c)
		return ((char *) b);
	else
		return (NULL);
}
