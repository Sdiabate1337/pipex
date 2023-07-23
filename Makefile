PROG = pipex
CC = cc 
CFLAGS = -Wall -Wextra -Werror 

SRCS = pipex.c pipex_utils.c 
SRCS_BONUS = pipex_bonus.c pipex_utils.c bonus_utils.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all:	${PROG}


${PROG}:	${OBJS}
		@echo "\033[33m----Compiling lib----"
		@make re -C ./libft
		@$(CC) ${OBJS} -Llibft -lft -o ${PROG}
		@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

bonus:	${OBJS_BONUS}
		@echo "\033[33m----Compiling lib----"
		@make re -C ./libft
		@$(CC) ${OBJS_BONUS} -Llibft -lft -o ${PROG}
		@echo "\033[32mPipex Bonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

clean:
		@make clean -C ./libft
		@rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
		@make fclean -C ./libft
		@rm -f $(NAME)
		@rm -f ${PROG}
		@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:			fclean all

re_bonus:	fclean bonus

.PHONY: all clean fclean bonus re re_bonus