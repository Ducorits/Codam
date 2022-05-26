CC	=	gcc

SRCS =	ascii/ft_isalnum.c		ascii/ft_isalpha.c		ascii/ft_isascii.c		ascii/ft_isdigit.c \
		ascii/ft_isprint.c		ascii/ft_tolower.c		ascii/ft_toupper.c \
		convert/ft_atoi.c		convert/ft_itoa.c \
		mem/ft_bzero.c			mem/ft_calloc.c			mem/ft_memchr.c			mem/ft_memcmp.c \
		mem/ft_memcpy.c			mem/ft_memmove.c		mem/ft_memset.c \
		put/ft_putchar_fd.c		put/ft_putendl_fd.c		put/ft_putnbr_fd.c		put/ft_putstr_fd.c \
		str/ft_split.c			str/ft_strchr.c			str/ft_strdup.c			str/ft_striteri.c \
		str/ft_strjoin.c		str/ft_strlcat.c		str/ft_strlcpy.c		str/ft_strlen.c	\
		str/ft_strmapi.c		str/ft_strncmp.c		str/ft_strnstr.c		str/ft_strrchr.c \
		str/ft_strtrim.c		str/ft_substr.c

INC	=	-I ./include

BONUS_SRCS =	lst/ft_lstadd_back_bonus.c	lst/ft_lstadd_front_bonus.c	lst/ft_lstclear_bonus.c	\
				lst/ft_lstdelone_bonus.c	lst/ft_lstiter_bonus.c		lst/ft_lstlast_bonus.c	\
				lst/ft_lstmap_bonus.c		lst/ft_lstnew_bonus.c		lst/ft_lstsize_bonus.c

BONUS_OBJS = $(patsubst %.c, obj/%.o, $(BONUS_SRCS))

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

OBJS = $(patsubst %.c, obj/%.o, $(SRCS))

all: $(OBJS) $(NAME)

bonus: add_bonus all

add_bonus:
	$(eval OBJS += $(BONUS_OBJS))

obj/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $^ -o $@
	$(eval COMP += $@)

ifdef COMP
$(NAME): $(OBJS)
	ar rs $(NAME) $(COMP)
else
$(NAME): $(OBJS)
	@printf "nothing to add to archive.\n"
endif


clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "Cleaned objects"

fclean: clean
	@rm -f libft.a
	@echo "Cleaned archive"

re: fclean all
