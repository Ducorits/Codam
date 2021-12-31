/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dritsema <dritsema@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:45:38 by dritsema          #+#    #+#             */
/*   Updated: 2021/12/31 01:10:46 by dritsema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	check_newline(t_buf *buf)
{
	int	count;

	count = 0;
	if (buf->content)
	{
		while (count < buf->size)
		{
			if (buf->content[count] == '\n')
			{
				return (count + 1);
			}
			count++;
		}
	}
	return (0);
}

int	newline_pos(t_buf read)
{
	int	i;

	i = 0;
	while (i < read.size)
	{
		if (read.content[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

char	*past_newline(t_buf *read)
{
	int	i;
	int	j;

	i = newline_pos(*read);
	j = 0;
	while (j < read->size - i)
	{
		read->content[j] = read->content[i + j];
		j++;
	}
	read->size = j;
	return (read->content);
}

char	*add_to_str(t_buf read, t_buf *buf)
{
	int		i;
	int		j;
	char	*str;

	i = newline_pos(read);
	str = malloc(buf->size + i + 1);
	j = 0;
	while (j < buf->size)
	{
		str[j] = buf->content[j];
		j++;
	}
	j = 0;
	while (j < i)
	{
		str[buf->size + j] = read.content[j];
		j++;
	}
	str[buf->size + i] = '\0';
	if (buf->size)
		free(buf->content);
	buf->size = buf->size + i;
	return (str);
}
