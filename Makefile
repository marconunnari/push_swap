# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/05 18:46:15 by mnunnari          #+#    #+#              #
#    Updated: 2017/06/05 18:46:17 by mnunnari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

all: $(NAME)

checker: checker_folder/srcs/*.c checker_folder/includes/*.h
	@make -C checker_folder >/dev/null
	@cp checker_folder/checker .
	@echo "checker done"

$(NAME): checker $(NAME)_folder/srcs/*.c $(NAME)_folder/includes/*.h
	@make -C $(NAME)_folder >/dev/null
	@cp $(NAME)_folder/$(NAME) .
	@echo "$(NAME) done"

clean:
	make clean -C checker_folder
	make clean -C $(NAME)_folder

fclean:
	make fclean -C checker_folder
	make fclean -C $(NAME)_folder
	rm -f checker
	rm -f $(NAME)

re: fclean all
