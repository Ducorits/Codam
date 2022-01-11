#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

// int	test_add_to_str()
// {
// 	static t_buf	read;
// 	t_return		buf;

// 	if (!read.content)
// 	{
// //		read.content = malloc(13);
// 		read.content[0] = ' ';
// 		read.content[1] = 'w';
// 		read.content[2] = 'o';
// 		read.content[3] = 'r';
// 		read.content[4] = 'l';
// 		read.content[5] = 'd';
// 		read.content[6] = '\n';
// 		read.content[7] = ' ';
// 		read.content[8] = 'h';
// 		read.content[9] = 'a';
// 		read.content[10] = 'i';
// 		read.content[11] = 'l';
// 		read.content[12] = '\n';
// 		read.size = 13;
// 	}
// 	buf.content = "hello";
// //	read.content = " world\n hail\n";
// 	buf.size = 5;
// 	if (read.content)
// 		buf.content = add_to_str(read, &buf);
// 	read.content = past_newline(&read);
// 	printf("add_to_str:(read.size: %i, buf.size: %i, %s)\n", read.size, buf.size, buf.content);
// //	buf.content = add_to_str(read, &buf);
// //	read.content = past_newline(&read);
// //	printf("add_to_str:(read.size: %i, buf.size: %i, %s)\n", read.size, buf.size, buf.content);
// 	return (0);
// }

// int	test_add_to_str1()
// {
// 	static t_buf	read;
// 	t_return		buf;
// 	int				i;

// //	if (!read.content)
// //	{
// 	read.content = malloc(7);
// 	read.content[0] = ' ';
// 	read.content[1] = 'w';
// 	read.content[2] = 'o';
// 	read.content[3] = 'r';
// 	read.content[4] = 'l';
// 	read.content[5] = 'd';
// 	read.content[6] = '0';
// 	read.size = 7;
// //	}
// 	buf.content = "hello";
// 	buf.size = 5;
// 	i = 0;
// 		while (i < 3)
// 		{
// 			i++;
// 			buf.content = add_to_str(read, &buf);
// 		}
// 	printf("add_to_str:(read.size: %i, buf.size: %i, %s)\n", read.size, buf.size, buf.content);
// //	buf.content = add_to_str(read, &buf);
// //	read.content = past_newline(&read);
// //	printf("add_to_str:(read.size: %i, buf.size: %i, %s)\n", read.size, buf.size, buf.content);
// 	return (0);
// }


int	test1()
{
	int		i;
	int		fd;
	char	*str;
	fd = open("script", O_RDONLY);
	i = 0;
	while	(i < 10)
	{
		str = get_next_line(fd);
		i++;
		if (str)
			printf("%i %s", i, str);
		free(str);
	}
	close(fd);
	return (0);
}

int	test2()
{
	int		i;
	int		fd;
	char	*str;
	fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDONLY);
	i = 0;
	while	(i < 10)
	{
		str = get_next_line(fd);
		i++;
		if (str)
		{
			printf("%i", i);
			write(1, str, strlen(str));
			free(str);
		}
	}
	close(fd);
	return (0);
}

int	main()
{
//	test_str_join();
//	test_until_newline();
//	test_add_to_str();
//	test_add_to_str();
//	test_add_to_str();
//	test_add_to_str1();
//	test_add_to_str1();
//	test1();
	test2();
	return (0);
}
