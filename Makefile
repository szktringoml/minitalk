# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 14:11:34 by string            #+#    #+#              #
#    Updated: 2023/10/01 11:37:32 by kousuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SRV = server.c 
SRC_CLT = client.c utils.c
BONUS_SRV = server_bonus.c
BONUS_CLT = client_bonus.c utils_bonus.c


SRV_OBJS = ${SRC_SRV:.c=.o}
CLT_OBJS = ${SRC_CLT:.c=.o}
SRV_BONUS_OBJS = ${BONUS_SRV:.c=.o}
CLT_BONUS_OBJS = ${BONUS_CLT:.c=.o}

OBJS_NAME_SRV = server
OBJS_NAME_CLT = client
BONUS_OBJS_NAME_SRV = server_bonus
BONUS_OBJS_NAME_CLT = client_bonus

LIBFT = libftex/libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(OBJS_NAME_SRV) $(OBJS_NAME_CLT)

$(LIBFT):
	make -C libftex

%.o: %.c 
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_NAME_SRV): $(SRV_OBJS)
	$(CC) $(FLAGS) -c $(SRC_SRV)
	$(CC) $(FLAGS) -o $@ $(SRC_SRV) $(LIBFT)
$(OBJS_NAME_CLT): $(SRV_OBJS)
	$(CC) $(FLAGS) -c $(SRC_CLT)
	$(CC) $(FLAGS) -o $@ $(SRC_CLT) $(LIBFT)
	
$(BONUS_OBJS_NAME_SRV): $(LIBFT) $(SRV_OBJS)
	$(CC) $(FLAGS) -c $(BONUS_SRV) 
	$(CC) $(FLAGS) -o $@ $(SRV_BONUS_OBJS) $(LIBFT)
$(BONUS_OBJS_NAME_CLT): $(LIBFT) $(SRV_OBJS)
	$(CC) $(FLAGS) -c $(BONUS_CLT)
	$(CC) $(FLAGS) -o $@ $(CLT_BONUS_OBJS) $(LIBFT)

bonus: $(LIBFT) $(BONUS_OBJS_NAME_SRV) $(BONUS_OBJS_NAME_CLT)

clean:
	make fclean -C libftex
	rm -rf $(SRV_OBJS) $(CLT_OBJS) $(SRV_BONUS_OBJS) $(CLT_BONUS_OBJS) $(LIBFT)

fclean: clean
	rm -f $(OBJS_NAME_SRV) $(OBJS_NAME_CLT) $(BONUS_OBJS_NAME_SRV) $(BONUS_OBJS_NAME_CLT)

re: clean all

bonus_re: fclean bonus

.PHONY: all clean fclean re bonus bonus_re
