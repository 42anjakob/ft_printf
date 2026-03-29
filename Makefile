NAME		=	libftprintf.a

CFLAGS		=	-c -Wall -Wextra -Werror

SRCS		=	ft_printf.c \
				ft_printf_utils.c

OBJS_DIR	=	objects
OBJS		=	${SRCS:%.c=$(OBJS_DIR)/%.o}

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) -rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
