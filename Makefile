# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 16:00:27 by mring             #+#    #+#              #
#    Updated: 2025/02/24 12:12:47 by mring            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CFLAGS		= -Wall -Wextra -Werror -g

SRC			= push_swap swap push rotate rev_rotate
SRCS		= $(addsuffix .c, $(SRC))
SRC_DIR		= src

OBJ_DIR		= obj
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
INCS		= -I ./includes/

LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

all: ${NAME}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				@$(CC) ${CFLAGS} -c $< -o $@ $(INCS)

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

${NAME}: 		$(OBJ_DIR) $(OBJS) $(LIBFT)
				@$(CC) $(OBJS) -o $(NAME) $(LIBFT)
				@echo "/// compiled: $(NAME) ///"

${LIBFT}:
	@$(MAKE) -C $(LIBFT_PATH)

clean:
				@rm -rf ${OBJ_DIR}
				@$(MAKE) -C $(LIBFT_PATH) clean
				@echo "/// cleaning.. ///"

fclean: 		clean
				@rm -f ${NAME}
				@$(MAKE) -C $(LIBFT_PATH) fclean

re: 			fclean all

test: $(NAME)
	$(eval N = $(if $(filter-out test,$(MAKECMDGOALS)), $(word 2, $(MAKECMDGOALS)), 5))
	$(eval ARG = $(shell bash -c 'for i in $$(seq $(N)); do echo -n "$$((RANDOM % 101)) " ; done' | sed 's/ *$$//'))
	@echo "Generated ARG ($(N) numbers): $(ARG)"
	./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

# Dummy rule to ignore extra command-line arguments
# like make test 10 for above testing case.
# would say "no rule for 10"
%:
	@:


test5: $(NAME)
				$(eval ARG = $(shell echo $$((RANDOM % 101)) $$((RANDOM % 101)) $$((RANDOM % 101)) $$((RANDOM % 101)) $$((RANDOM % 101))))
				@echo "Generated ARG: $(ARG)"
				./push_swap $(ARG) | ./checker_Mac $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l
#linux test cases
test2l: $(NAME)
				$(eval ARG = $(shell echo $$((RANDOM % 101)) $$((RANDOM % 101))))
				@echo "Generated ARG: $(ARG)"
				./push_swap $(ARG) | ./checker_linux $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l
test5l: $(NAME)
				$(eval ARG = $(shell echo $$((RANDOM % 101)) $$((RANDOM % 101)) $$((RANDOM % 101)) $$((RANDOM % 101)) $$((RANDOM % 101))))
				@echo "Generated ARG: $(ARG)"
				./push_swap $(ARG) | ./checker_linux $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l

.PHONY:			all clean fclean re test test5 test2l test5l