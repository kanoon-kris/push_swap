# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/23 15:40:51 by kboonkos          #+#    #+#              #
#    Updated: 2026/11/08 00:15:00 by kboonkos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror \
	-MMD -MP # Automatically generate dependency files (.d) for headers
INCLUDE = -I. -Ilibft
CFLAGS += $(INCLUDE)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = push_swap.c parser.c payload_utility.c ft_strcmp.c disorder.c
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

FORCE:

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(DEPS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

run:
	./$(NAME) $$(cat args.txt)

norm:
	norminette $(SRCS)
	norminette -R CheckForbiddenSourceHeader push_swap.h libft/libft.h

# Include the dependency files if they exist.
-include $(DEPS)
.PHONY: all clean fclean re run
