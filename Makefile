CC = cc 

CFLAGS = -Wall -Werror -Wextra 

SRCS =  ft_split.c\
		ft_strjoin.c\
		ft_strtrim.c\
		get_path.c\
		ft_strstr.c\

OBJS = ${SRCS:.c=.o}

ARV = ar -rcs

NAME = libfpipex.a

REM = rm -f

.c.o :
	$(CC) -c $(CFLAGS) $< -o $@
	$(ARV) $(NAME) $@

all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) pipex.c $(NAME) -o pipex

clean :
	${REM} ${OBJS}

fclean : clean
	${REM} ${NAME}
	${REM} pipex

re : fclean all

.PHONY : all clean fclean bonus re