NAME= libft.a
LIBFT_SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_strlen.c ft_strdup.c ft_strlcpy.c ft_strchr.c \
			ft_strrchr.c ft_strnstr.c ft_strlcat.c ft_strncmp.c ft_atoi.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_strmapi.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putnbr_fd.c ft_calloc.c ft_putendl_fd.c ft_striteri.c
BONUS_SRC = ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_lstdelone.c ft_lstclear.c ft_lstadd_front.c ft_lstadd_back.c ft_lstiter.c

OBJ = $(LIBFT_SRC:.c=.o)
B_OBJ = $(BONUS_SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
green = \033[0;32m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(green)Creating $@"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
clean:
	@rm -f $(OBJ) $(B_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(OBJ) $(B_OBJ)
	@echo "$(green)Creating $@"
	@ar rc $(NAME) $(OBJ) $(B_OBJ)
	@ranlib $(NAME)

.PHONY: all clean fclean bonus re
