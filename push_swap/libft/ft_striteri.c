/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/23 11:50:47 by dritsema      #+#    #+#                 */
/*   Updated: 2021/10/23 15:00:19 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	slen;
	unsigned int	i;

	if (s)
	{
		i = 0;
		slen = ft_strlen(s);
		while (i < slen)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
