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

ifeq ($(TESTFLAGS), 1)
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g 
else
CFLAGS = -Wall -Wextra -Werror
endif

NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)($(OBJS))

$(NAME): %.o $(HEADERS)
	ar rs $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

bonus: $(NAME)($(OBJS)) $(NAME)($(BONUS_OBJS))

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f libftprintf.a

re: fclean all
