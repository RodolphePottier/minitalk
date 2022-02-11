OBJS_DIR	=	objs/

SRCS_DIR	=	srcs/

SRCS		=	ft_alloc_buffers.c \
				ft_alloc_buffers_utils.c \
				ft_arg_utils.c	\
				ft_feed_buffers_utils.c	\
				ft_feed_buffers.c \
				ft_get_nbr_length.c \
				ft_parsing.c \
				ft_printf.c \
				ft_put_in_array.c \

OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

CFLAGS		=	-Wall -Werror -Wextra -I $(INC) -I $(LIB_DIR)/$(INC)

CC			=	cc

NAME		=	libftprintf.a

RM			=	rm -rf

LIB_DIR		=	libft

INC			=	includes

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				@mkdir -p $(OBJS_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

makeft:
			$(MAKE) -C libft all

fcleanft:
			$(MAKE) -C libft fclean

$(NAME): 	makeft $(OBJS)
			cp libft/libft.a $(NAME)
			ar rc $(NAME) $(OBJS)
			ranlib ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean fcleanft
			${RM} ${OBJS_DIR}
			${RM} ${NAME}

re:			fclean all

bonus:		$(ALL)

.PHONY:		makeft fcleanft all clean fclean re bonus
