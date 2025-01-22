# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 16:00:27 by mring             #+#    #+#              #
#    Updated: 2025/01/13 17:02:51 by mring            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CFLAGS		= -Wall -Wextra -Werror

SRC			= push_swap
SRCS		= $(addsuffix .c, $(SRC))
SRC_DIR		= src

OBJ_DIR		= obj
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
INCS		= -I ./includes/

# LIBFT_PATH	=	./libft
# LIBFT		=	$(LIBFT_PATH)/libft.a

all: ${NAME}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				@$(CC) ${CFLAGS} -c $< -o $@ $(INCS)

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

${NAME}: 		$(OBJ_DIR) $(OBJS)
				@$(CC) $(OBJS) -o $(NAME)

clean:
				@rm -rf ${OBJ_DIR}
				@echo "/// cleaning $(NAME) ///"

fclean: 		clean
				@rm -f ${NAME}
				@echo "/// fcleaning $(NAME) ///"

re: 			fclean all

test2: $(NAME)
				$(eval ARG = $(shell echo $$((RANDOM % 101)) $$((RANDOM % 101))))
				@echo "Generated ARG: $(ARG)"
				./push_swap $(ARG) | ./checker_Mac $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l
test5: $(NAME)
				$(eval ARG = $(shell echo $$((RANDOM % 101)) $$((RANDOM % 101)) $$((RANDOM % 101)) $$((RANDOM % 101)) $$((RANDOM % 101))))
				@echo "Generated ARG: $(ARG)"
				./push_swap $(ARG) | ./checker_Mac $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l

.PHONY:			all clean fclean re 