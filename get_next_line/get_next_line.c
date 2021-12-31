/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dritsema <dritsema@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:39:43 by dritsema          #+#    #+#             */
/*   Updated: 2021/12/31 01:33:15 by dritsema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buf	r_buf;
	t_buf			buf;

	buf.size = 0;
	while (!check_newline(&buf))
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
				free(r_buf.content);
				return (0);
			}
		}
	}
	if (buf.content)
		return (buf.content);
	return (0);
}
