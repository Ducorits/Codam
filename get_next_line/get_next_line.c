/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/31 14:09:08 by dritsema      #+#    #+#                 */
/*   Updated: 2022/01/11 14:16:24 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_buf	r_buf;
	t_return		buf;

	buf.size = 0;
	if (fd == -1)
		return (0);
	while (!check_newline(&buf))
	{
		if (r_buf.size)
		{
			buf.content = add_to_str(r_buf, &buf);
			past_newline(&r_buf);
		}
		else
		{
			r_buf.size = read(fd, r_buf.content, BUFFER_SIZE);
			if (!r_buf.size)
				break ;
		}
	}
	if (buf.size != 0)
	{
		return (buf.content);
	}
	return (0);
}
