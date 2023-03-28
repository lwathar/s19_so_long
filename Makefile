# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 13:37:29 by lowathar          #+#    #+#              #
#    Updated: 2023/03/28 13:08:24 by lowathar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME    = so_long
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
MLX     = -lmlx -framework OpenGL -framework AppKit

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS    =   ./src/so_long.c \
			./src/check_cmd.c \
			./src/init_game.c \
			./src/check_map.c \
			./src/map_to_image.c \
			./src/key_input.c \
			./src/game_end.c \
			./src/check_path.c \
			./src/utils.c \

BONUS	=	./src_bonus/so_long_bonus.c \
			./src_bonus/check_cmd_bonus.c \
			./src_bonus/init_game_bonus.c \
			./src_bonus/check_map_bonus.c \
			./src_bonus/map_to_image_bonus.c \
			./src_bonus/key_input_bonus.c \
			./src_bonus/game_end_bonus.c \
			./src_bonus/check_path_bonus.c \
			./src_bonus/utils_bonus.c \

OBJS    = ${SRCS:.c=.o}

BOBJS	= ${BONUS:.c=.o}

%.c%.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################

CLR_RMV     = \033[0m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
CYAN        = \033[1;36m
RM          = rm -rf

${NAME}:    ${OBJS}
		@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
		@${MAKE} -C ./libft
		@ $(MAKE) -C ./mlx all >/dev/null 2>&1
		@ cp ./mlx/libmlx.a .
		@${CC} ${CFLAGS} ${OBJS} ${MLX} ./libft/libft.a -o ${NAME}
		@echo "$(GREEN)$(NAME) created ✔"

all:    ${NAME}

clean:
		@${MAKE} -C ./libft clean
		@${MAKE} -C ./mlx clean
		@${RM} ${OBJS} ${BOBJS}
		@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔"

fclean: clean
		@${RM} ${NAME}
		@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔"
		@${RM} libmlx.a
		@${RM} ./libft/libft.a

re:     fclean all 

bonus:		${BOBJS}
		@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
		@${MAKE} -C ./libft
		@ $(MAKE) -C ./mlx all >/dev/null 2>&1
		@ cp ./mlx/libmlx.a .
		@${CC} ${CFLAGS} ${BOBJS} ${MLX} ./libft/libft.a -o ${NAME}
		@echo "$(GREEN)$(NAME) created ✔"

.PHONY: all clean fclean re