NAME		=	pipex

SRCS_FILES	= 	${shell find ./srcs_man -name "*.c"}

SRCS_MAN	= 	$(SRCS_FILES)
OBJS_MAN	=	$(patsubst %.c,%.o,$(SRCS_MAN))

LIB_DIR		=	libft
HEADER		=	-I./include/pipex.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS_MAN)
			@make -C $(LIB_DIR)
			@$(CC) $(CFLAGS) $(LIB_DIR)/libft.a $(OBJS_MAN) -o $(NAME)
			@clear
			@echo "Let's play, my Master!!!"

%.o:		%.c
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
			@make clean -C $(LIB_DIR)
			$(RM) $(OBJS_MAN)

fclean:		clean
			@make fclean -C $(LIB_DIR)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re