# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 00:48:52 by hael-ghd          #+#    #+#              #
#    Updated: 2024/06/10 17:56:39 by hael-ghd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex_bonus

CC = cc

FLAGS = -Wall -Wextra -Werror

SOURCE = pipex_m.c pipex_utils_m.c pipex_utils1_m.c pipex_utils2_m.c pipex_utils3_m.c \

SOURCE_BONUS = pipex_bonus.c pipex_utils_bonus.c pipex_utils1_bonus.c pipex_utils2_bonus.c pipex_utils3_bonus.c \

OBJ_SRC = $(SOURCE:.c=.o)

OBJ_SRC_BONUS = $(SOURCE_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SRC) 
	$(CC) $(FLAGS) $(OBJ_SRC) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_SRC_BONUS)
	$(CC) $(FLAGS) $(OBJ_SRC_BONUS) -o $(NAME_BONUS)

%_m.o: %_m.c pipex.h
	$(CC) $(FLAGS) -c $<

%bonus.o: %bonus.c pipex_bonus.h
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJ_SRC) $(OBJ_SRC_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
