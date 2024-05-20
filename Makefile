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

INCLUDES	=	-I ./includes -I $(LIBFT)/libft.h -I $(LIBMLX)/include
SRCS 		=	$(wildcard src/*.c)
OBJS		=	$(SRCS:.c=.o)

LIBMLX		=	./lib/MLX42
LIBFT		=	./lib/libft
LIBS		=	$(LIBFT)/libft.a $(LIBMLX)/libmlx42.a -ldl -lglfw -pthread -lm

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

.PHONY: all clean fclean re libmlx libft brew
