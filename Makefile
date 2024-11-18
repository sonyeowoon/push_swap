NAME = push_swap

INCLUDES = ./push_swap.h

SRCS = push_swap.c \
	   ft_printf/ft_printf.c \
	   ft_printf/ft_write.c \
	   ft_printf/ft_write2.c \
	   libft/ft_isdigit.c \
	   libft/ft_isspace.c \
	   libft/ft_strncmp.c \
	   make_stack.c \
	   stack_control.c \
	   chk_dupnsort.c \
	   ps_util.c \
	   ps_util2.c \
	   push_swap_cmd.c \
	   ft_sorting.c \
	   pb_pivot_utils.c \
	   find_median.c \
	   pa_all_utils.c \
	   pa_flg.c \
	   pa_all_utils2.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
