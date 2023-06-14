# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 20:53:18 by abelhadj          #+#    #+#              #
#    Updated: 2023/06/13 22:10:14 by abelhadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d
NAME_B	= cub3d

CC		= cc
FLAGS	= # -Wall -Wextra -Werror
RM		= rm -rf
FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit


LIBFT	= $(addprefix libft/, ft_itoa ft_calloc ft_putstr_fd ft_strcmp ft_strchr ft_strlen ft_strjoin_gnl ft_strjoin \
			ft_strncmp get_next_line ft_split ft_tablen ft_memmove ft_memcpy ft_strdup)
UTILS	= $(addprefix utils/, ft_error name_check read_map split_map free_cart)
GAME	= $(addprefix game/, game position quit update keys move turn draw hcast vcast ray)
CHECK	= $(addprefix check/, check00)

FILES	= main $(LIBFT) $(UTILS) $(CHECK) $(GAME)
SRC		= $(FILES:=.c)
OBJ		= $(FILES:=.o)
HEADER  = include/cub3d.h
INCLUDES= -I include

GREEN		=	\e[92;5;118m
RED			=	\e[0;31m
GRAY		=	\e[33;2;37m
CURSIVE		=	\e[33;3m
RESET		=	\e[0m

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@printf "$(CURSIVE)$(GRAY)	- Compiling $(NAME)... $(RESET)\n"
	@$(CC) $(OBJ) $(INCLUDES) $(FRAMEWORKS) -o $(NAME)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) $(INCLUDES)  -c $< -o $@ 
	
clean:
	@$(RM) $(OBJ)
	@printf "$(CURSIVE)$(GRAY)	- Removing object files ... $(RESET)\n"
	@printf "$(RED)    - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(CURSIVE)$(GRAY)	- Removing $(NAME)... $(RESET)\n"
	@printf "$(RED)    - Executable removed.$(RESET)\n"

re: fclean all


.PHONY: all clean fclean re