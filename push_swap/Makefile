CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g

SRCS	=	main.c utils.c #push.c swap.c

OBJS	=	$(patsubst %.c, obj/%.o, $(SRCS))

NAME	=	push_swap

INC		=	-I /libft/ -I /ft_printf/

LIBFT	=	libft/libft.a

FT_PRINTF	= ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $^ $(CFLAGS) $(INC) -o $@

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make TESTFLAGS=1 -C libft/

$(FT_PRINTF):
	make TESTFLAGS=1 -C ft_printf/

test: obj/test.o $(LIBFT) $(FT_PRINTF) 
	$(CC) $^ $(INC) -o test_yes

clean:
	@rm -f *.o
	@rm -rf obj
	
fclean: clean
	@rm -f $(NAME)
	@rm -f ft_printf/libftprintf.a libft/libft.a

re: fclean all