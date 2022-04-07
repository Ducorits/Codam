CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

SRCS	=	main.c push.c swap.c utils.c

OBJS	=	$(patsubst %.c, obj/%.o, $(SRCS))

NAME	=	push_swap

INC		=	-I libft/libft.h -I push_swap.h

LIBFT	=	libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $^ $(INC) -o $@

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft/

clean:
	@rm -f *.o
	@rm -rf obj
	
fclean: clean
	@rm -f $(NAME)

re: fclean all