# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 20:53:18 by abelhadj          #+#    #+#              #
#    Updated: 2023/06/17 00:05:29 by abelhadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d
NAME_B	= cub3d

CC		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit


LIBFT = $(addprefix  libft/, ft_isdigit ft_memset  ft_isprint ft_putendl_fd ft_itoa ft_strmapi \
		ft_bzero ft_putchar_fd  ft_atoi ft_strncmp var_compare ft_strcmp ft_memchr ft_striteri \
		ft_tolower  ft_strlen ft_putstr_fd ft_strlcat ft_calloc ft_strtrim \
		ft_toupper ft_isalnum ft_strrchr ft_str_not_in strlen_var ft_strlcpy ft_memcmp ft_split \
		ft_isalpha ft_memcpy ft_putnbr_fd ft_strnstr ft_strjoin \
		ft_isascii ft_memmove ft_strchr ft_strdup ft_strdupdup ft_substr \
		ft_lstiter ft_lstsize ft_lstclear ft_lstdelone ft_lstadd_back \
		ft_lstnew ft_lstadd_front two_d_strjoin ft_lstmap freed_strjoin ft_free ft_lstlast\
		ft_realloc ft_strjoinfree ft_freetab ft_charjoin ft_tablen)
		
UTILS	= $(addprefix utils/, ft_error name_check read_map split_map free_cart draw_utile)
GAME	= $(addprefix game/, game position quit update keys move turn draw hcast vcast ray ft_3d ft_ray ft_init)
CHECK	= $(addprefix check/, check00)
PARSING = $(addprefix parsing/, parsing check_lines1 p_utils/mini_utils\
		p_utils/first_part_lines check_colors accessible  map_checker/check_map \
		map_checker/check_content map_checker/map_utils1)

FILES	= main $(LIBFT) $(UTILS) $(CHECK) $(GAME) $(PARSING) get_next_line/get_next_line
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
	@$(CC) -g $(FLAGS) $(INCLUDES)  -c $< -o $@ 
	
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