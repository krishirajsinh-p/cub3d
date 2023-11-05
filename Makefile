# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 18:51:03 by kpuwar            #+#    #+#              #
#    Updated: 2023/11/05 22:05:34 by kpuwar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

#replace wildcard with file names later on
INCLUDES = $(wildcard includes/*.h)
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft

CC = cc
CFLAGS = -Wall -Werror -Wextra -Ofast
RM = rm -f

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)
	@make -C $(LIBMLX) -j4

libft:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a $(LIBMLX)/libmlx42.a -ldl -lm -lglfw -L"$(HOME)/.brew/opt/glfw/lib/" -I$(INCLUDES) -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT) clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(LIBMLX) clean

re: fclean all

norm:
	@norminette includes
	@norminette src
	@norminette lib/libft

brew:
	if [ -d $(HOME)/.brew ]; then \
		zsh -c "brew update"; \
		zsh -c "brew install glfw"; \
		zsh -c "brew install cmake"; \
	else \
		git clone --depth=1 https://github.com/Homebrew/brew $(HOME)/.brew; \
		$(shell echo 'export PATH=$$HOME/.brew/bin:$$PATH' >> $(HOME)/.zshrc) \
		zsh -c "brew update"; \
		zsh -c "brew install glfw"; \
		zsh -c "brew install cmake"; \
	fi

.PHONY: all clean fclean re libmlx libft norm brew
