
SRCS	= 	big_sort.c\
			big_sort_2.c\
			sort_funcs.c\
			sort_funcs_2.c\
			array_funcs.c\
			array_funcs_2.c\
			ps_support_funcs.c\
			apply_commands.c\
			check_stack.c\
			stack_funcs.c\
			push_swap.c\
			lists.c\

SRCS2	=	checker.c\
			support_checker_funcs.c\
			support_funcs.c\
			make_array_funcs.c\
			gnl.c\
			ps_commands_funcs.c\
			ps_commands.c\
			list_funcs.c\
			list_funcs_2.c\
			make_stack.c\

OBJS	=	$(SRCS:.c=.o)
OBJS2	=	$(SRCS2:.c=.o)

NAME	=	push_swap
NAME2	=	checker

CC		=	gcc

RM		=	rm -rf

CFLAGS		= -Wall -Werror -Wextra

%.o: %.c	Makefile push_swap.h checker.h
			$(CC) $(CFLAGS) -c $(@:.o=.c) -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME2):	$(OBJS2)
			$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(OBJS2)

fclean:		clean
			$(RM) $(NAME) $(NAME2)

bonus:		$(NAME2)

re:			fclean	all

.PHONY:		all clean fclean re bonus
