#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	test_str_join()
{
	t_buf	part_a;
	t_buf	part_b;

	part_b.content = " world\n";
	part_b.size = 7;
	part_a.content = malloc(5);
	part_a.content[0] = 'h';
	part_a.content[1] = 'e';
	part_a.content[2] = 'l';
	part_a.content[3] = 'l';
	part_a.content[4] = 'o';
	part_a.size = 5;
	part_a.content = str_join(&part_a, &part_b);
	part_a.content[part_a.size] = '\0';
	printf("%s", part_a.content);
	return (0);	
}

int	test1()
{
	int		i;
	int		fd;
	char	*str;
	fd = open("script", O_RDONLY);
	i = 0;
	while	(i < 200)
	{
		str = get_next_line(fd);
		i++;
//		printf("%s", str);
	}
//	str = get_next_line(fd);
//	printf("%s", str);
	close(fd);
	return (0);
}

int	main()
{
	test_str_join();
	test1();
	return (0);
}
