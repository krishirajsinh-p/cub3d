# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 21:08:59 by kpuwar            #+#    #+#              #
#    Updated: 2023/05/31 16:06:42 by kpuwar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = 	ft_isalpha.c			\
		ft_isdigit.c			\
		ft_isalnum.c			\
		ft_isascii.c			\
		ft_isprint.c			\
		ft_strlen.c				\
		ft_memset.c				\
		ft_bzero.c				\
		ft_memcpy.c				\
		ft_memmove.c			\
		ft_strlcpy.c			\
		ft_strlcat.c			\
		ft_toupper.c			\
		ft_tolower.c			\
		ft_strchr.c				\
		ft_strrchr.c			\
		ft_strncmp.c			\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_strnstr.c			\
		ft_atoi.c				\
		ft_calloc.c				\
		ft_strdup.c				\
		ft_substr.c				\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_split.c				\
		ft_itoa.c				\
		ft_strmapi.c			\
		ft_striteri.c			\
		ft_putchar_fd.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\
		get_next_line.c			\
		ft_printf.c				\
		ft_printf_utils.c		\
		ft_bubble_sort.c		\
		ft_check_dup.c			\
		ft_print_array.c		\
		ft_free_split.c			\
		ft_print_array.c		\
		ft_get_index.c			\
		ft_is_array_sorted.c	\
		ft_sqrt.c

SRCSB =	ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\
		$(SRCS)

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

%.o : %.c libft.h
	$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) 

all: $(NAME)

clean:
	rm -f $(OBJSB)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJSB)
	ar rc $(NAME) $(OBJSB)

.PHONY: all clean fclean re bonus
