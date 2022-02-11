# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 16:15:30 by rpottier          #+#    #+#              #
#    Updated: 2022/02/08 15:58:31 by rpottier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


OBJS_DIR	=	objs/

SRCS_DIR	=	srcs/

GNL_DIR		=	gnl/

GNL			=	$(addprefix $(GNL_DIR), get_next_line.c \
					get_next_line_utils.c)

SRCS		=	$(addprefix $(SRCS_DIR), main.c \
				bresenham.c \
				bresenham_utils.c \
				transform_and_draw.c \
				centering.c \
				put_pxl.c \
				parsing.c \
				rotation.c \
				key_hook.c \
				key_hook_utils.c \
				key_handling1.c \
				key_handling2.c \
				color.c \
				colors_utils.c \
				debug.c \
				map_size.c \
				init_zoom.c \
				exit.c)

OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

CFLAGS		=	-o3 -Wall -Wextra 
#-g3 -fsanitize=address
INCLUDES	=	-I $(INC)

LINK_LIB	=	$(LIB_DIR) $(LIB)

CC			=	cc

NAME		=	fdf

RM			=	rm -rf

LIB_DIR		=	libft/

LIB			=	-lft

MLX_LIB		=	-lmlx -lX11 -lXext -lm

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
	$(CC) $(CFLAGS) $(GNL) $(SRCS) $(MLX_LIB) -L $(LINK_LIB) $(INCLUDES) -o fdf

clean:
			${RM} ${OBJS}

fclean:		clean fcleanlibft
			${RM} ${OBJS_DIR}
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
