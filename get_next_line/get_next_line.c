#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buf	read_buf;
	t_buf					return_buf;
	int						newline_index;

	return_buf.size = 0;
	newline_index = -1;
	while (newline_index == -1)
	{
		if (read_buf.content)
		{
			newline_index = check_newline(&read_buf);
			if (newline_index != -1)
			{
				if (return_buf.content)
					return_buf.content = str_join(&return_buf, &read_buf);
				else
				{
					return_buf.content = until_newline(&read_buf, newline_index);
					return_buf.size = newline_index + 1;
				}
					read_buf.content = past_newline(&read_buf, newline_index);
				write(1, return_buf.content, return_buf.size);
				return (return_buf.content);
			}
			else
			{
				return_buf.content = str_join(&return_buf, &read_buf);
//				return_buf.size += read_buf.size;
				read_buf.size = read(fd, read_buf.content, BUFFER_SIZE);
//				return_buf.size += read_buf.size;
//				printf("Newline Not inside\n");
			}
		}
		else
		{
			read_buf.content = malloc(BUFFER_SIZE * sizeof(char));
			read_buf.size = read(fd, read_buf.content, BUFFER_SIZE);
//			return_buf.size += read_buf.size;
//			printf("there was no buffer yet\n");
		}
	}
	return ("");
}

