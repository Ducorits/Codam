#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	check_newline(t_buf *buf)
{
	int	count;

	count = 0;
	while (count < buf->size)
	{
		if (buf->content[count] == '\n')
		{
			return (count);
		}
		count++;
	}
	return (-1);
}

char	*past_newline(t_buf *buf, int newline_index)
{
	int		i;

	i = 0;
	while (i + newline_index + 1 < buf->size)
	{
		buf->content[i] = buf->content[i + newline_index + 1];
		i++;
	}
	buf->size = i;
	return (buf->content);
}

char	*str_join(t_buf *return_buf, t_buf *read_buf)
{
	char	*str;
	int		i;
	int		j;

//	printf("%p %p %i %i\n", return_buf->content, read_buf->content, return_buf->size, read_buf->size); 
	str = malloc((return_buf->size + read_buf->size + 1) * sizeof(char));
	i = 0;
	while (i < return_buf->size)
	{
		str[i] = return_buf->content[i];
//		printf("%c", return_buf->content[i]);
		i++;
	}
	j = 0;
	while (j < read_buf->size)
	{
		str[i + j] = read_buf->content[j];
//		printf("%c", read_buf->content[j]);
		j++;
	}
	return_buf->size += read_buf->size;
	if (return_buf->content)
		free(return_buf->content);
//	printf("\n");
	return (str);
}

char	*until_newline(t_buf *buf, int newline_index)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc((newline_index + 2) * sizeof(char));
	while (i <= newline_index)
	{
		str[i] = buf->content[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

