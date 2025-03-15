# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 16:00:27 by mring             #+#    #+#              #
#    Updated: 2025/03/15 09:59:28 by mring            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CFLAGS		= -Wall -Wextra -Werror -g

SRC			= algo create_and_free helper parsing push_swap push rev_rotate rotate small_sort swap
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

# Dummy rule to ignore extra command-line arguments
# like make test 10 for above testing case.
# would say "no rule for 10"
%:
	@:

.PHONY:			all clean fclean re