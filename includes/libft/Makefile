SRCS =	ft_strchr.c \
		ft_strlen.c \
		ft_strdup.c 

NAME 			= libft.a

OBJECTS 		= $(SRCS:.c=.o)

AR 				= ar rcs

CC 				= cc

RM 				= rm -f

CFLAGS 			= -Wall -Werror -Wextra

all: 			$(NAME)


$(NAME):		$(OBJECTS)
					$(AR) $(NAME) $(OBJECTS)

bonus:			$(BONUS_OBJECTS) $(NAME)
					$(AR) $(NAME)

clean:
				$(RM) $(OBJECTS)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re 