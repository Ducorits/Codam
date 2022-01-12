for ((i = 1; i <= 100; i++));
do
	gcc test.c get_next_line.c get_next_line_utils.c -D MALLOC_COUNT=$i -Wall -Werror -Wextra -g -fsanitize=address
	./a.out 
done
