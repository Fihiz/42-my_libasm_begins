# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 16:59:52 by sad-aude          #+#    #+#              #
#    Updated: 2020/12/02 21:35:47 by sad-aude         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

CC = clang
CFLAGS = -Wall -Wextra -Werror
NASM = nasm
NASMFLAGS = -f elf64

FILES = ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s	\
		ft_read.s \
		ft_strdup.s

OBJ = $(FILES:.s=.o)

all: draw $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "\033[1mYOU CAN RUN [MAKE TEST] TO BEGIN TESTING PART \033[0m"

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

clean:
	@echo "\033[1m|=> .O DELETION <=|\033[0m"
	@rm -rf $(OBJ)

fclean: clean
	@echo "\033[1m|=> .A DELETION <=|\033[0m"
	@rm -f $(NAME)
	
re: fclean all

draw:
	@printf "\n"
	@printf "\033[34m          _____                    _____                    _____          \033[0m\n"
	@printf "\033[34m         /\    \                  /\    \                  /\    \         \033[0m\n"
	@printf "\033[34m        /::\    \                /::\    \                /::\____\        \033[0m\n"
	@printf "\033[34m       /::::\    \              /::::\    \              /::::|   |        \033[0m\n"
	@printf "\033[34m      /::::::\    \            /::::::\    \            /:::::|   |        \033[0m\n"
	@printf "\033[34m     /:::/\:::\    \          /:::/\:::\    \          /::::::|   |        \033[0m\n"
	@printf "\033[34m    /:::/__\:::\    \        /:::/__\:::\    \        /:::/|::|   |        \033[0m\n"
	@printf "\033[34m   /::::\   \:::\    \       \:::\   \:::\    \      /:::/ |::|   |        \033[0m\n"
	@printf "\033[34m  /::::::\   \:::\    \    ___\:::\   \:::\    \    /:::/  |::|___|______  \033[0m\n"
	@printf "\033[34m /:::/\:::\   \:::\    \  /\   \:::\   \:::\    \  /:::/   |::::::::\    \ \033[0m\n"
	@printf "\033[34m/:::/  \:::\   \:::\____\/::\   \:::\   \:::\____\/:::/    |:::::::::\____\ \033[0m\n"
	@printf "\033[34m\::/    \:::\  /:::/    /\:::\   \:::\   \::/    /\::/    / ~~~~~/:::/    /\033[0m\n"
	@printf "\033[34m \/____/ \:::\/:::/    /  \:::\   \:::\   \/____/  \/____/      /:::/    / \033[0m\n"
	@printf "\033[34m          \::::::/    /    \:::\   \:::\    \                  /:::/    /  \033[0m\n"
	@printf "\033[34m           \::::/    /      \:::\   \:::\____\                /:::/    /   \033[0m\n"
	@printf "\033[34m           /:::/    /        \:::\  /:::/    /               /:::/    /    \033[0m\n"
	@printf "\033[34m          /:::/    /          \:::\/:::/    /               /:::/    /     \033[0m\n"
	@printf "\033[34m         /:::/    /            \::::::/    /               /:::/    /      \033[0m\n"
	@printf "\033[34m        /:::/    /              \::::/    /               /:::/    /       \033[0m\n"
	@printf "\033[34m        \::/    /                \::/    /                \::/    /        \033[0m\n"
	@printf "\033[34m         \/____/                  \/____/                  \/____/         \033[0m\n"
	@printf "\033[34m                                                                           \033[0m\n"
	@printf "\033[34m                                                     42-my_libasm, sad-aude\033[0m\n"
	@printf "\n"

test: all
	$(CC) $(CFLAGS) main.c $(NAME) -o result