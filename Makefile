# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 14:57:47 by igaliuk           #+#    #+#              #
#    Updated: 2018/03/04 19:13:01 by igaliuk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc

FLAG = -Wall -Wextra -Werror

SRC = ft_arrways.c \
	ft_atoi_li.c \
	ft_error_frees.c \
	ft_finding_way.c \
	ft_processing_links.c \
	ft_processing_rooms.c \
	ft_processing_ways_daughter.c \
	ft_processing_ways.c \
	ft_readinst.c \
	ft_starting_ants_daughter.c \
	ft_starting_ants.c \
	lem_in.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "       Compiling lem-in....\n"
	make -C libft
	@$(CC) $(FLAG) libft/libft.a -o $@ $^

%.o: %.c
	@$(CC) $(FLAG) -c -o $@ $<

clean:
	@echo "\n       Deleting objects....\n"
	@rm -f $(OBJ)
	make clean -C libft

fclean: clean
	@echo "       Deleting binary file....\n"
	@rm -f $(NAME)
	make fclean -C libft

re: fclean all
