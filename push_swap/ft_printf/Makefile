SRCS =	ft_printf.c \
		ft_printchar.c \
		ft_printhex.c \
		ft_printstr.c \
		ft_upprinthex.c \
		ft_printun.c \
		ft_printnbr.c

BONUS_SRCS =

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

HEADERS = ft_printf.h

CC= gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)($(OBJS))

$(NAME): %.o $(HEADERS)
	ar rs $@ $<

ifeq ($(TESTFLAGS), 1)
%.o: %.c
	$(CC) $(CFLAGS) -fsanitize=address -g -c $<
else
%.o: %.c
	$(CC) $(CFLAGS) -c $<
endif

bonus: $(NAME)($(OBJS)) $(NAME)($(BONUS_OBJS))

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f libftprintf.a

re: fclean all
