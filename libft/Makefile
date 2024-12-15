# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 12:52:27 by vpericat          #+#    #+#              #
#    Updated: 2022/11/21 12:26:41 by vpericat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##	VARIABLE	##
#OUTPUT
NAME = libft.a

#SOURCE FILES
SRC_FILES =  ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_split.c\
	ft_strchr.c\
	ft_strswap.c\
	ft_strdup.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strldup.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strmapi.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strchri.c\
	ft_strrchr.c\
	ft_strtrim.c\
	ft_substr.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelfirst.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_strisdigit.c\
	ft_strisint.c\
	my_error.c\
	lerp.c\
	invlerp.c\
	multifree.c\
	get_next_line.c

#PATHS
SRC_DIR = source
OBJ_DIR = object

#OBJECTS
OBJS = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

#MISCELLANEOUS
PREPROCFLAGS = -I. -O3
HEADER = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3

##	VISUALS	##
_BANNER = \033[1m\033[35m[LIBFT]\033[39m
_BUILDBANNER = $(_BANNER)\033[32m[BUILD]\033[39m —\033[0m
_CLEANBANNER = $(_BANNER)\033[33m[REMOVED]\033[39m —\033[0m

##	RULES	##
all: ${NAME}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@$(CC) $(CFLAGS) $(PREPROCFLAGS) -c $< -o $@
	@echo "$(_BUILDBANNER) $@"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@echo "$(_BUILDBANNER) $@ folder"

${NAME}: $(OBJ_DIR) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(_BUILDBANNER) ${NAME}"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(_CLEANBANNER) $(OBJ_DIR) folder"

fclean: clean
	@rm -f $(NAME)
	@echo "$(_CLEANBANNER) $(NAME)"

re: fclean all

#RULES TO USE FROM EXTERNAL MAKEFILES
extclean:
	@rm -rf $(OBJ_DIR)
	@echo "$(_CLEANBANNER) $(OBJ_DIR) folder"

extfclean:
	@$(RM) $(NAME)
	@echo "$(_CLEANBANNER) $(NAME)"

.PHONY: all clean fclean re message extclean extfclean