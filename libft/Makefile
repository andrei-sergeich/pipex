NAME		=	libft.a

FT_LIST		=	ft_atoi.c		ft_bzero.c		ft_calloc.c		ft_isalnum.c	ft_isalpha.c\
				ft_isascii.c	ft_isdigit.c	ft_isprint.c	ft_memccpy.c	ft_memchr.c\
				ft_memcmp.c		ft_memcpy.c		ft_memmove.c	ft_memset.c		ft_strchr.c\
				ft_strdup.c		ft_strlcat.c	ft_strlcpy.c	ft_strlen.c		ft_strncmp.c\
				ft_strnstr.c	ft_strrchr.c	ft_tolower.c	ft_toupper.c\
				ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_itoa.c\
				ft_strmapi.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c\
				ft_strcpy.c		ft_strclr.c		ft_find_max.c	ft_error.c		ft_prompt.c\
				ft_atoi_only_for_num.c\
				ft_abs.c	ft_find_min.c	ft_iterative_power.c\
				ft_recursive_power.c	ft_sqrt.c	ft_strcmp.c\
				get_next_line.c\
				ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c\
				ft_lstdelone.c	ft_lstclear.c		ft_lstiter.c	ft_lstmap.c 	ft_perror.c\
#				ft_lstfindmax_val.c	ft_lstfindmin_val.c\
#				ft_lstfind_ind_of_max_value.c	ft_lstfind_ind_of_min_value.c\

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