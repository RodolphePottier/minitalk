# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 16:15:30 by rpottier          #+#    #+#              #
#    Updated: 2022/02/13 20:21:04 by rpottier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	= srcs/

SRCS_SERVER	=	server/main_server.c \
				server/malloc.c \
				server/transmission_and_reset.c

SRCS_CLIENT	=	client/main_client.c \
				client/client_utils.c

OBJS_CLIENT	=	$(addprefix $(OBJS_DIR), $(SRCS_CLIENT:.c=.o))

OBJS_SERVER	=	$(addprefix $(OBJS_DIR), $(SRCS_SERVER:.c=.o))

OBJS_DIR	= 	objs/

CFLAGS		=	-Wall -Wextra -Werror  -I includes -I ft_printf/includes

INCLUDES	=	-I $(INC)

CC			=	cc

NAME		=	minitalk

RM			=	rm -rf

INC			=	includes

LIB_DIR		= 	./ft_printf/

LIB			=	-lftprintf

all:		$(NAME)

$(NAME):		makeftprintf client server

client:			$(OBJS_CLIENT)
				$(CC) $(CFLAGS) $^ -o client -L ./ft_printf -lftprintf

server:			$(OBJS_SERVER)
				$(CC) $(CFLAGS) $^ -o server -L ./ft_printf -lftprintf

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				@mkdir -p $(OBJS_DIR) $(OBJS_DIR)client $(OBJS_DIR)server
				${CC} ${CFLAGS} -c $< -o $@

bonus : $(NAME)

makeftprintf:
			$(MAKE) -C ft_printf all

fcleanprintf:
			$(MAKE) -C ft_printf fclean 

clean:
			$(RM) $(OBJS_DIR)
			make -C ft_printf clean

fclean:		clean fcleanprintf
			${RM} ${OBJS_DIR}
			${RM} server
			${RM} client

re:			fclean all

.PHONY:		all clean fclean re client server
