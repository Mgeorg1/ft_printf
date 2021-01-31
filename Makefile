NAME	=	libftprintf.a

SRCS	=	base/ft_printf.c \
			parser/ft_parser.c \
			processor/ft_processor.c \
			processor/int_processor.c \
			processor/char_processor.c \
			processor/str_processor.c \
			processor/hex_processor.c \
			processor/ptr_processor.c \
			processor/if_neg_w.c \
			processor/prc_processor.c \
			processor/ft_putnbr_ptf.c \
			processor/u_int_len.c \
			processor/int_len.c \
			processor/ft_putnbr_u.c \
			processor/print_while.c \
			processor/if_negative.c \
			processor/int_len.c \

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

.PHONY:	all clean fclean re

all:		${NAME}

${NAME}:	${OBJS}
			@make -C ./libft
			@cp ./libft/libft.a ${NAME}
			@ar rc ${NAME} ${OBJS}
			@ranlib ${NAME}

c.o:
	${CC} ${CFLAGS} -c -I ./includes/ft_printf.h $< -o ${<:.c=.o}

clean:	
		@make clean -C ./libft
		@${RM} ${OBJS}

fclean:	
		@make fclean -C ./libft
		@${RM} ${OBJS}
		@${RM} libftprintf.a

re: 	fclean all