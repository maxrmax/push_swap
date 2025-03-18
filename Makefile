# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 16:00:27 by mring             #+#    #+#              #
#    Updated: 2025/03/18 17:30:38 by mring            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
BONUS_NAME		= checker
CFLAGS			= -Wall -Wextra -Werror -g

SRC				= algo create_and_free helper parsing push_swap push rev_rotate rotate small_sort swap
SRCS			= $(addsuffix .c, $(SRC))
SRC_DIR			= src

SRC_BONUS		= checker create_and_free push rev_rotate rotate swap helper parsing checker_utils1 checker_utils2 checker_utils3 checker_utils4
SRCS_BONUS		= $(addsuffix .c, $(SRC_BONUS))

OBJ_DIR			= obj
OBJS			= $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS		= $(SRCS_BONUS:%.c=$(OBJ_DIR)/%.o)
INCS			= -I ./includes/

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

all: 			${NAME}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) ${CFLAGS} -c $< -o $@ $(INCS)


${NAME}: 		$(OBJS) $(LIBFT)
				@$(CC) $(OBJS) -o $(NAME) $(LIBFT)
				@echo "/// compiled: $(NAME) ///"

bonus: 			${BONUS_NAME}

${BONUS_NAME}:  $(OBJS_BONUS) $(LIBFT)
				@$(CC) $(OBJS_BONUS) -o $(BONUS_NAME) $(LIBFT)
				@echo "/// compiled: $(BONUS_NAME) ///"			

${LIBFT}:
				@$(MAKE) -C $(LIBFT_PATH)

clean:
				@rm -rf ${OBJ_DIR}
				@$(MAKE) -C $(LIBFT_PATH) clean
				@echo "/// cleaning.. ///"

fclean: 		clean
				@rm -f ${NAME} ${BONUS_NAME}
				@$(MAKE) -C $(LIBFT_PATH) fclean

re: 			fclean all

.PHONY:			all clean fclean re bonus