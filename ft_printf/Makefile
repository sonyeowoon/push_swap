NAME = libftprintf.a

INCLUDES = ./ft_printf.h

SRCS = ft_printf.c \
	   ft_write.c \
	   ft_write2.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rcs $(NAME) $^

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
