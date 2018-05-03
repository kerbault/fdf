# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/04/24 13:57:39 by kerbault     #+#   ##    ##    #+#        #
#    Updated: 2018/05/03 17:57:04 by kerbault    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SHELL		:= /bin/bash

#### System configuration section ####

NAME		:= libft.a
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar
ARFLAGS		:= rcs
MKDIR		:= mkdir
MKDIRFLAGS	:= -p
RM			:= /bin/rm
RMFLAGS		:= -rf
ECHO		:= echo
QUIET		:= @
NORM		:= norminette

#### Definition section ####

INCLUDESDIR	:= includes
SRCDIR		:= src
SRCS		:= \
	ft_atoi.c \
	ft_lstadd.c \
	ft_memmove.c \
	ft_putwchar.c \
	ft_striter.c \
	ft_strnstr.c \
	ft_bzero.c \
	ft_lstdel.c \
	ft_memset.c \
	ft_putwchar_fd.c \
	ft_striteri.c \
	ft_strrchr.c \
	ft_isalnum.c \
	ft_lstdelone.c \
	ft_putaddr.c \
	ft_putwstr.c \
	ft_strjoin.c \
	ft_strsplit.c \
	ft_isalpha.c \
	ft_lstiter.c \
	ft_putaddr_fd.c \
	ft_putwstr_fd.c \
	ft_strlcat.c \
	ft_strstr.c \
	ft_isascii.c \
	ft_lstmap.c \
	ft_putchar.c \
	ft_strcat.c \
	ft_strlen.c \
	ft_strsub.c \
	ft_isdigit.c \
	ft_lstnew.c \
	ft_putchar_fd.c \
	ft_strchr.c \
	ft_strmap.c \
	ft_strtrim.c \
	ft_islower.c \
	ft_memalloc.c \
	ft_putendl.c \
	ft_strclr.c \
	ft_strmapi.c \
	ft_swap.c \
	ft_isprint.c \
	ft_memccpy.c \
	ft_putendl_fd.c \
	ft_strcmp.c \
	ft_strncat.c \
	ft_tolower.c \
	ft_isspace.c \
	ft_memchr.c \
	ft_putnbr.c \
	ft_strcpy.c \
	ft_strncmp.c \
	ft_toupper.c \
	ft_isupper.c \
	ft_memcmp.c \
	ft_putnbr_fd.c \
	ft_strdel.c \
	ft_strncpy.c \
	ft_itoa.c \
	ft_memcpy.c \
	ft_putstr.c \
	ft_strdup.c \
	ft_strnequ.c \
	ft_itoa_base.c \
	ft_memdel.c \
	ft_putstr_fd.c \
	ft_strequ.c \
	ft_strnew.c \
	get_next_line.c
	
OBJDIR		:= obj
OBJS		:= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

#### Rules section ####

.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	$(QUIET)$(ECHO) "Linking and Indexing the library"
	$(QUIET)$(AR) $(ARFLAGS) $@ $(OBJS)
	$(QUIET)$(ECHO) "Done."

$(OBJDIR):
	$(QUIET)$(MKDIR) $(MKDIRFLAGS) $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(QUIET)$(ECHO) "Compiling $<"
	$(QUIET)$(CC) $(CFLAGS) -I$(INCLUDESDIR) -c $< -o $@

clean:
	$(QUIET)$(ECHO) "Cleaning the objects"
	$(QUIET)$(RM) $(RMFLAGS) $(OBJS)

fclean: clean
	$(QUIET)$(ECHO) "Deleting the library"
	$(QUIET)$(RM) $(RMFLAGS) $(NAME) $(OBJDIR)

re: fclean all

norm:
	$(QUIET)$(ECHO) "Checking Norm 101"
	$(QUIET)$(NORM) $(SRCDIR)/$(SRC) $(INCLUDESDIR)/*.h

gpush: fclean
	$(QUIET) git add *
	$(QUIET) git commit -m "quick push"
	$(QUIET) git push
