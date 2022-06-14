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

SRCS =	$(SRC_ASCII) $(SRC_CONVERT) $(SRC_GNL) $(SRC_LST) $(SRC_MEM) $(SRC_PUT) $(SRC_STR)

SRC_ASCII =	ascii/ft_isalnum.c		ascii/ft_isalpha.c		ascii/ft_isascii.c		ascii/ft_isdigit.c \
			ascii/ft_isprint.c		ascii/ft_iswhitespace.c

SRC_CONVERT = convert/ft_atoi.c		convert/ft_itoa.c 		convert/ft_tolower.c	convert/ft_toupper.c

SRC_GNL =	gnl/get_next_line.c		gnl/get_next_line_utils.c

SRC_LST =	lst/ft_lstadd_back.c	lst/ft_lstadd_front.c	lst/ft_lstclear.c \
			lst/ft_lstdelone.c		lst/ft_lstiter.c		lst/ft_lstlast.c \
			lst/ft_lstmap.c			lst/ft_lstnew.c			lst/ft_lstsize.c

SRC_MEM =	mem/ft_bzero.c			mem/ft_calloc.c			mem/ft_memchr.c			mem/ft_memcmp.c \
			mem/ft_memcpy.c			mem/ft_memmove.c		mem/ft_memset.c

SRC_PUT =	put/ft_putchar_fd.c		put/ft_putendl_fd.c		put/ft_putnbr_fd.c		put/ft_putstr_fd.c

SRC_STR =	str/ft_split.c			str/ft_strchr.c			str/ft_strdup.c			str/ft_striteri.c \
			str/ft_strjoin.c		str/ft_strlcat.c		str/ft_strlcpy.c		str/ft_strlen.c \
			str/ft_strmapi.c		str/ft_strncmp.c		str/ft_strnstr.c		str/ft_strrchr.c \
			str/ft_strtrim.c		str/ft_substr.c

INC	=	-I ./include

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

OBJS = $(patsubst %.c, obj/%.o, $(SRCS))

all: heading comp

.PHONY: heading comp compdone done clean fclean re

comp: $(OBJS) compdone $(NAME) done

heading:
	@printf "$(CYAN)---< $(ORANGE)Duco's libft $(CYAN)>---\n"; \



compdone:
	@printf "$(INSET)$(BLUE)Compiling - $(GREEN)%-29s $(CYAN)%-10s$(RESET)\n" "Done!" ""; \


done:
	@printf "$(BEGIN)$(CYAN)-------< $(ORANGE)Done $(CYAN)>-------\n$(RESET)"; \


obj/%.o: src/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $^ -o $@
	@printf "$(INSET)$(BLUE)Compiling - $(GREEN)%-29s $(CYAN)%-10s$(RESET)\n" "$^" ""
	@$(eval COMP += $@)

$(NAME): $(OBJS)
	@printf "$(INSET)"
	@ar rs $(NAME) $(OBJS)

clean:
	@rm -rf obj
	@printf "\033[1;31m- $(BLUE)Removed object files\n$(RESET)"

fclean: clean
	@rm -f libft.a
	@printf "\033[1;31m- $(BLUE)Removed archive file\n$(RESET)"

re: heading fclean comp
