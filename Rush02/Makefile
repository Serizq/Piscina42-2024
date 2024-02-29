# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 15:11:33 by ecaceres          #+#    #+#              #
#    Updated: 2024/02/25 07:14:55 by carlsanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_YELLOW_B=\033[1;33m
C_LIGHT_RED_B=\033[0;91m
C_WHITE=\033[0;97m
C_RESET=\033[0;39m

# Actualización de la lista de fuentes con los nuevos archivos
SRCS	= ./srcs/ft_string_utilities.c \
		  ./srcs/ft_parse_utilities.c \
		  ./srcs/ft_number_dict_operations.c \
		  ./srcs/ft_file_io_utilities.c \
		  ./srcs/ft_main_and_error.c \
		  ./srcs/ft_str_join.c \
		  ./srcs/ft_array_extend.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= rush-02
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

# Regla para compilar archivos .c a .o
.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

# Regla para compilar el ejecutable
${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

# Regla all para compilar todo
all : ${NAME}

# Regla para ejecutar el programa
run :
	./${NAME}

# Regla para limpiar objetos y binarios
clean :
	${RM} ${OBJS}

# Regla para limpiar todo incluyendo el ejecutable
fclean : clean
	${RM} ${NAME}

# Regla para verificar la norma
norm :
	norminette */*.[ch]

# Regla para encontrar fuentes automáticamente (mantenida para referencia)
find_sources :
	find srcs -type f -name "*.c" | xargs -I{} echo ./{} | tr '\n' ' '

# Regla para rehacer todo
re : fclean all

# Reglas de prueba
test : re
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Number: 42$(C_RESET)" ;
	@./${NAME} 42 | cat -e || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Number: 0$(C_RESET)" ;
	@./${NAME} 0 | cat -e || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Number: 10.4$(C_RESET)" ;
	@./${NAME} 10.4 | cat -e || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Number: 100000$(C_RESET)" ;
	@./${NAME} 100000 | cat -e || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Number: 20, language: FRENCH$(C_RESET)" ;
	@./${NAME} numbers_french.dict 20 | cat -e || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Number: 20, language: WITH_CUSTOM$(C_RESET)" ;
	@./${NAME} numbers_with_custom.dict 20 | cat -e || true ;
	@##

.PHONY: all clean fclean re .c.o test

