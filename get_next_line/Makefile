SRCS =	get_next_line.c \
				get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

NAME = get_next_line.a

CC = clang

TESTFLAGS = -fsanitize=address -g

CFLAGS = -Werror -Wextra -Wall -D BUFFER_SIZE=

NUM = $(test%:test=)

all: $(NAME) 

$(NAME): $(OBJS)
	ar rs $@ $<

%.o: %.c
	$(CC) $(CFLAGS)42 -c $<

test%: test.c
	$(CC) $(CFLAGS)$(@:test%=%) $(SRCS) test.c -o test
	./test

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
