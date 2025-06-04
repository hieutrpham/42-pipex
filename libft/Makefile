# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 11:45:16 by trupham           #+#    #+#              #
#    Updated: 2025/04/26 17:33:05 by trupham          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=cc
CFLAGS := -Wall -Wextra -Werror
SRC :=	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		ft_printf.c \
		ft_utils.c \
		ft_putnbr.c \
		ft_puthex.c \

BONUS:= ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c \

OBJ := $(patsubst %.c, %.o, $(SRC))
OBJ_BONUS := $(patsubst %.c, %.o, $(BONUS))
BONUS_NAME := libftbonus

NAME := libft.a

GREEN    := \033[32m
RESET    := \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@printf "$(GREEN)$(NAME) created successfully!$(RESET)\n"

bonus : $(BONUS_NAME)

$(BONUS_NAME): $(NAME) $(OBJ_BONUS)
	@ar rcs $^
	@printf "$(GREEN)$(BONUS_NAME) created successfully!$(RESET)\n"
	@touch $(BONUS_NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I. -c -o $@ $<

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS) $(BONUS_NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
