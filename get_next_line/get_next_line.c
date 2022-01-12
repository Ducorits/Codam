/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/31 14:09:08 by dritsema      #+#    #+#                 */
/*   Updated: 2022/01/11 15:24:04 by alkrusts        ########   odam.nl       */
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
	while (!check_newline(&buf))
	{
		if (r_buf.size > 0)
		{
			buf.content = add_to_str(r_buf, &buf);
			if (buf.content == NULL)
				return (NULL);
			past_newline(&r_buf);
		}
		else
		{
			r_buf.size = read(fd, r_buf.content, BUFFER_SIZE);
			if (r_buf.size < 1)
				break ;
		}
	}
	if (buf.size != 0)
	{
		return (buf.content);
	}
	return (0);
}
