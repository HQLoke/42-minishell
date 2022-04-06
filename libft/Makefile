NAME	=	libft.a

CFLAGS	=	-Wall -Wextra -Werror
CC = gcc ${CFLAGS}
AR = ar rcs
RM = rm -f

SRCS	=	ft_memset.c		ft_bzero.c		ft_memcpy.c		ft_memccpy.c	ft_memmove.c	\
			ft_memchr.c		ft_memcmp.c		ft_strlen.c		ft_strlcpy.c	ft_strlcat.c	\
			ft_strchr.c		ft_strrchr.c	ft_strncmp.c	ft_atoi.c		ft_isalpha.c	\
			ft_isdigit.c	ft_isalnum.c	ft_isascii.c	ft_isprint.c	ft_toupper.c	\
			ft_tolower.c	ft_calloc.c		ft_strdup.c		ft_substr.c		ft_strjoin.c	\
			ft_strtrim.c	ft_split.c		ft_itoa.c		ft_strmapi.c	ft_putchar_fd.c	\
			ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	ft_strnstr.c

OBJS	=	${SRCS:.c=.o}

BONUS	=	ft_lstnew.c			ft_lstadd_front.c			ft_lstsize.c	ft_lstlast.c	\
			ft_lstadd_back.c	ft_lstdelone.c				ft_lstclear.c	ft_lstiter.c	\
			ft_lstmap.c

BONUS_OBJS = ${BONUS:.c=.o}

#First three targets are executed because first calls on second, second calls on third
all:		${NAME}

${NAME}:	${OBJS} ${BONUS_OBJS}
			@${AR} ${NAME} ${OBJS} ${BONUS_OBJS}

#It is used not only by all, but both all and bonus
#If the dependency fits the wildcard pattern, then its substituted into the function below one by one
%.o: %.c
			@${CC} -c $< -o $@

clean:
			@${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re
