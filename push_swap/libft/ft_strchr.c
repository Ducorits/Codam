/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/07 15:19:13 by dritsema      #+#    #+#                 */
/*   Updated: 2021/10/19 14:36:53 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *) s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *) s + i);
	return (NULL);
}
