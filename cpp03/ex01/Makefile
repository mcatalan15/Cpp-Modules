# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 08:03:29 by mcatalan@st       #+#    #+#              #
#    Updated: 2024/09/09 19:34:45 by mcatalan@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RST = \033[0m

NAME    :=	ScavTrap

SRC     :=	main.cpp		\
			ClapTrap.cpp   \
			ScavTrap.cpp

OBJ_DIR := obj

OBJ     := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

CPP     := c++ -std=c++98

CPPFLAGS := -W -Wall -Wextra -Werror

RM      := @rm -rfv

all:    $(NAME)

clean:
	$(RM) $(OBJ_DIR) $(DEP_DIR) > /dev/null
	@echo "$(RED)Objects removed$(RST)"

fclean: clean
	$(RM) $(NAME) > /dev/null
	@echo "$(RED)$(NAME) removed$(RST)"

re: fclean all

$(NAME): $(OBJ) Makefile
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Compiled$(RST)"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

.PHONY: all clean fclean re
