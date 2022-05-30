CC	=	gcc

SHELL := /bin/bash

BLUE = \033[1;34m
CYAN = \033[1;36m
ORANGE = \033[38;5;214m
GREEN = \033[1;32m
RESET = \033[0m
UP1 = \033[1F
BEGIN = \033[0G
SAVE = \0337
RESTORE = \0338
INSET = $(BEGIN)$(GREEN)+ $(BLUE)
BORDER = printf "$(BEGIN)$(CYAN)|\033[45G|\n$(UP1)\033[3G$(BLUE)"

SRCS =	ascii/ft_isalnum.c		ascii/ft_isalpha.c		ascii/ft_isascii.c		ascii/ft_isdigit.c \
		ascii/ft_isprint.c		ascii/ft_tolower.c		ascii/ft_toupper.c \
		convert/ft_atoi.c		convert/ft_itoa.c \
		\
		mem/ft_bzero.c			mem/ft_calloc.c			mem/ft_memchr.c			mem/ft_memcmp.c \
		mem/ft_memcpy.c			mem/ft_memmove.c		mem/ft_memset.c \
		\
		put/ft_putchar_fd.c		put/ft_putendl_fd.c		put/ft_putnbr_fd.c		put/ft_putstr_fd.c \
		str/ft_split.c			str/ft_strchr.c			str/ft_strdup.c			str/ft_striteri.c \
		str/ft_strjoin.c		str/ft_strlcat.c		str/ft_strlcpy.c		str/ft_strlen.c \
		str/ft_strmapi.c		str/ft_strncmp.c		str/ft_strnstr.c		str/ft_strrchr.c \
		str/ft_strtrim.c		str/ft_substr.c \
		\
		lst/ft_lstadd_back.c	lst/ft_lstadd_front.c	lst/ft_lstclear.c \
		lst/ft_lstdelone.c		lst/ft_lstiter.c		lst/ft_lstlast.c \
		lst/ft_lstmap.c			lst/ft_lstnew.c			lst/ft_lstsize.c \
		\
		gnl/get_next_line.c		gnl/get_next_line_utils.c

INC	=	-I ./include

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

OBJS = $(patsubst %.c, obj/%.o, $(SRCS))

all: border comp

comp: compstart $(OBJS) compdone $(NAME) done

border:
	@printf "$(CYAN)---< $(ORANGE)Duco's libft $(CYAN)>---\n"

compstart:
	@printf "\n"

compdone:
	@printf "$(SAVE)\033[1A$(INSET)$(BLUE)Compiling - $(GREEN)%-29s $(CYAN)%-10s$(RESET)\n$(RESTORE)" "Done!" ""

done:
	@printf "$(BEGIN)$(CYAN)-------< $(ORANGE)Done $(CYAN)>-------\n"

obj/%.o: src/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $^ -o $@
	@printf "$(SAVE)\033[1A$(INSET)$(BLUE)Compiling - $(GREEN)%-29s $(CYAN)%-10s$(RESET)$(RESTORE)" "$^" ""
	$(eval COMP += $@)

$(NAME): $(OBJS)
	@printf "$(INSET)Making Archive...\n$(INSET)"
	@ar rs $(NAME) $(COMP)

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@printf "\033[1;31m- $(BLUE)Removed object files\n$(RESET)"

fclean: clean
	@rm -f libft.a
	@printf "\033[1;31m- $(BLUE)Removed archive file\n$(RESET)"

re: border fclean comp
