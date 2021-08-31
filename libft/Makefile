NAME		=	libft.a

FT_LIST		=	${shell find ./ -name "*.c"}

OBJS		=	$(patsubst %.c,%.o,$(FT_LIST))

OPTFLAGS	=	-O2
CFLAGS		=	-Wall -Wextra -Werror
HEADER		=	libft.h

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $?
			@clear
			@echo "Library is open for you, my Master!!!"

%.o:		%.c $(HEADER)
			@gcc $(CFLAGS) $(OPTFLAGS) -c $< -o $@


clean:
			@rm -f $(OBJS) $(OBJS_B)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus