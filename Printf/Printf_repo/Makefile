SRCS =	ft_printf.c \
		ft_printchar.c \
		ft_printhex.c \
		ft_printstr.c \
		ft_upprinthex.c \
		ft_printun.c \
		ft_printnbr.c

BONUS_SRCS =

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

HEADERS =	libft/libft.h \
			ft_printf.h

CC= gcc

CFLAGS = -Wall -Wextra -Werror

TESTFLAGS = -g -fsanitize=address

NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

all: libft.a $(NAME)($(OBJS))

$(NAME): %.o $(HEADERS)
	ar rs $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

bonus: $(NAME)($(OBJS)) $(NAME)($(BONUS_OBJS))

libft.a: ./libft/Makefile
	make -C libft/
	cp ./libft/libft.a ./libftprintf.a

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f libftprintf.a libft.a

re: fclean all

test: all
	$(CC) $(CFLAGS) $(TESTFLAGS) $(NAME) main.c -o test
	@echo "\n\ntesting this shit!\n"
	@./test
