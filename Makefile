# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 16:15:30 by rpottier          #+#    #+#              #
#    Updated: 2022/02/12 20:51:54 by rpottier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRCS_DIR = server_srcs/

SERVER_SRCS		=	$(addprefix $(SERVER_SRCS_DIR), main_server.c \
						malloc.c \
						transmission_and_reset.c

SERVER_OBJS		=	$(addprefix $(SERVER_OBJS_DIR), $(SERVER_SRCS:.c=.o))

SERVER_OBJS_DIR = server_objs/

CFLAGS		=	-Wall -Wextra -Werror

INCLUDES	=	-I $(INC)

CC			=	cc

NAME		=	server

RM			=	rm -rf

INC			=	includes

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				@mkdir -p $(OBJS_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

makeftprintf:
			$(MAKE) -C ft_printf all

fcleanprintf:
			$(MAKE) -C ft_printf fclean 

$(NAME): 
	$(CC) $(CFLAGS) $(SERVER_SRCS) -L $(LINK_LIB) $(INCLUDES) -o fdf

clean:
			${RM} ${OBJS}

fclean:		clean fcleanlibft
			${RM} ${OBJS_DIR}
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
