OBJS_DIR	=	objs/

SRCS_DIR	=	srcs/

SRCS	=	ft_atoi.c \
			ft_atoui_base.c \
			ft_atouli_base.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_realloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_uitoa.c \
			ft_ulitoa.c \
			ft_itoa.c \
			ft_is_white_space.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c  \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_putnbr_base.c \
			ft_atoi_base.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_convert_base.c \
			ft_convert_base2.c 

OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

CFLAGS		=	-Wall -Werror -Wextra -I includes

CC			=	cc

NAME		=	libft.a

RM			=	rm -rf

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				@mkdir -p $(OBJS_DIR)
				${CC} ${CFLAGS} -c $< -o $@

$(NAME): 		$(OBJS)
				ar r ${NAME} ${OBJS}
				ranlib ${NAME}

all:			$(NAME)

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${OBJS_DIR}
				${RM} ${NAME}

re:				fclean all

.PHONY:	all clean fclean re
