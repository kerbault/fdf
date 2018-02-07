# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/16 07:56:05 by aberneli     #+#   ##    ##    #+#        #
#    Updated: 2018/02/06 16:56:29 by kerbault    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re normy

NAME = fdf

SRCS =

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

INC = -I minilibx_macos -I libft

HEADERS =

LIBS = minilibx_macos/libmlx.a libft/libft.a

EXT_LIBS = -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	gcc $(FLAGS) $(LIBS) $(EXT_LIBS) $(OBJS) -o $(NAME)

$(LIBS):
	make -C ./libft
	make -C ./minilibx_macos

./%.o: ./%.c $(HEADERS)
	gcc $(FLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
	make -C ./libft re
	make -C ./minilibx_macos re

re2: fclean all

normy:
	norminette $(SRCS) $(HEADERS)
