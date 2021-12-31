/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: dritsema <dritsema@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2021/12/31 14:09:08 by dritsema       #+#    #+#                */
/*   Updated: 2021/12/31 14:54:09 by dritsema        ########   odam.nl       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_buf	r_buf;
	t_buf			buf;

	buf.size = 0;
	while (!check_newline(&buf, r_buf))
	{
		if (r_buf.size)
		{
			buf.content = add_to_str(r_buf, &buf);
			r_buf.content = past_newline(&r_buf);
		}
		else
		{
			if (!r_buf.content)
				r_buf.content = malloc(BUFFER_SIZE);
			r_buf.size = read(fd, r_buf.content, BUFFER_SIZE);
			if (!r_buf.size)
			{
//				printf("free: size %i, buf content: %s", r_buf.size, buf.content);
				free(r_buf.content);
				return (0);
			}
		}
//		printf("r_buf.size: %i, buf size: %i, buf content [%s]", r_buf.size, buf.size, buf.content);
	}
	if (buf.content)
		return (buf.content);
	return (0);
}
