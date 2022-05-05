CC		=	gcc

ifeq ($(TESTFLAGS), 1)
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g
else
CFLAGS	=	-Wall -Werror -Wextra
endif

SRCS	=	main.c stack_utils.c error_check.c rotate.c swap.c push.c sort.c test.c bubble_sort.c radix_sort.c

OBJS	=	$(patsubst %.c, obj/%.o, $(SRCS))

NAME	=	push_swap

INC		=	-Ilibft -Ift_printf -I.

LIBFT	=	libft/libft.a

FT_PRINTF	= ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $^ $(CFLAGS) $(INC) -o $@

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

ifeq ($(TESTFLAGS), 1)
$(LIBFT):
	make -C libft/

$(FT_PRINTF):
	make -C ft_printf/
else
$(LIBFT):
	make TESTFLAGS=$(TESTFLAGS) -C libft/

$(FT_PRINTF):
	make TESTFLAGS=$(TESTFLAGS) -C ft_printf/
endif

clean:
	@rm -f *.o
	@rm -rf obj
	
fclean: clean
	@rm -f $(NAME)
	@rm -f ft_printf/libftprintf.a libft/libft.a

re: fclean all