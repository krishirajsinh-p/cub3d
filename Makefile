# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 18:51:03 by kpuwar            #+#    #+#              #
#    Updated: 2023/11/26 21:23:16 by kpuwar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

#replace wildcard with file names later on
INCLUDES	=	-I ./includes -I $(LIBFT)/libft.h -I $(LIBMLX)/include
SRCS 		=	$(wildcard src/*.c)
OBJS		=	$(SRCS:.c=.o)

LIBMLX		=	./lib/MLX42
LIBFT		=	./lib/libft
LIBS		=	$(LIBFT)/libft.a $(LIBMLX)/libmlx42.a -ldl -lglfw -pthread -lm -L"$(HOME)/.brew/opt/glfw/lib/"

CC = cc
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast
RM = rm -rf

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)
	@make -C $(LIBMLX) -j4

libft:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCLUDES) -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT) clean

fclean: clean
	@make -C $(LIBFT) fclean
	@make -C $(LIBMLX) clean
	@$(RM) $(LIBMLX)/CMakeFiles
	@$(RM) $(LIBMLX)/cmake_install.cmake
	@$(RM) $(LIBMLX)/Makefile
	@$(RM) $(LIBMLX)/CMakeCache.txt
	@$(RM) $(NAME)

re: fclean all

brew:
	if [ -d $(HOME)/.brew ]; then \
		brew update; \
		brew install glfw; \
		brew install cmake; \
	else \
		git clone --depth=1 https://github.com/Homebrew/brew $(HOME)/.brew; \
		echo 'export PATH=$$HOME/.brew/bin:$$PATH' >> $(HOME)/.zshrc; \
		brew update; \
		brew install glfw; \
		brew install cmake; \
	fi

.PHONY: all clean fclean re libmlx libft brew
