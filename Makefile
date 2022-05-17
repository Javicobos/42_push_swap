# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 11:50:53 by jcobos-d          #+#    #+#              #
#    Updated: 2022/05/17 12:33:17 by jcobos-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	push_swap_utils.c input_p_s.c ft_printf.c printf_pointerprinter.c

OBJS	=	${SRCS:.c=.o}

NAME	=	push_swap

CFLAGS	=	-Wall -Wextra -Werror #-g3 -fsanitize=address

# COLORS

BLACK				=	\033[0;30m
RED					=	\033[0;31m
GREEN				=	\033[0;32m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
MAGENTA				=	\033[0;35m
CYAN				=	\033[0;36m
RESET				=	\033[0m

.c.o:
			@echo "${BLUE}Building $@${RESET}"
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@echo "${CYAN}Making $@${RESET}"
			gcc ${CFLAGS} -o $(NAME) $(OBJS)
			@echo "${GREEN}✨ Complete! $@ created ✨${RESET}"

all:		${NAME}

clean:
			@rm -f ${OBJS} ${B_OBJS}
			@echo "${GREEN}Objects cleaned from $(CURDIR) ${RESET}"

fclean:		clean
			@rm -f ${NAME}
			@echo "${GREEN}Binary ${NAME} cleaned${RESET}"

re:			fclean all

.PHONY:		all clean fclean re