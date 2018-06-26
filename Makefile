# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/22 21:55:44 by kerbault     #+#   ##    ##    #+#        #
#    Updated: 2018/06/26 17:16:13 by kerbault    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SHELL		:= /bin/bash

#### Start of system configuration section ####

NAME		:= fdf
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar
ARFLAGS		:= rcs
MKDIR		:= mkdir
MKDIRFLAGS	:= -p
RM			:= /bin/rm
RMFLAGS		:= -rf
ECHO		:= echo -e
QUIET		:= @
NORM		:= norminette -R CheckForbiddenSourceHeader
GREEN		:= \033[0;32m
NC			:= \033[0m

#### Libraries def section ####

LIBFTDIR	:= libft
MLXDIR		:= minilibx_macos
EXT_LIBS	:=	-framework OpenGl -framework AppKit
LIBS		:=	\
	$(MLXDIR)/libmlx.a \
	$(LIBFTDIR)/libft.a \
	$(EXT_LIBS)

#### Start of files definition section ####

INCLUDESDIR	:= inc
INCLUDES 	:= \
	-I $(INCLUDESDIR)/ \
	-I $(LIBFTDIR)/$(INCLUDESDIR) \
	-I $(MLXDIR)
SRCDIR		:=	src
SRCS		:=	\
	main.c\
	opt_mod_1.c\
	opt_mod_2.c\
	opt_mod_3.c\
	pers_cav.c\
	keymap.c\
	set_map.c\
	read_map.c
OBJDIR		:=	obj
OBJS		:=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

#### Start of rules section ####

.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(LIBFTDIR)/libft.a $(MLXDIR)/libmlx.a $(OBJDIR) $(OBJS)
	$(QUIET)$(ECHO) "Creating the executable"
	$(QUIET)$(CC) $(CCFLAGS) $(LIBS) $(OBJS) -o $@
	$(QUIET)$(ECHO) "Done"

$(OBJDIR):
	$(QUIET)$(MKDIR) $(MKDIRFLAGS) $(OBJDIR)

$(LIBFTDIR)/libft.a:
	$(QUIET)$(ECHO) "Creating the lib"
	$(QUIET)$(MAKE) -C $(LIBFTDIR)
	$(QUIET)$(ECHO) "Compilation lib"
	
$(MLXDIR)/libmlx.a:
	$(QUIET)$(ECHO) "Creating the mlx"
	$(QUIET)$(MAKE) -C $(MLXDIR)
	$(QUIET)$(ECHO) "Compilation mlx"
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDESDIR)/$(NAME).h
	$(QUIET)$(ECHO) "Compiling $<"
	$(QUIET)$(CC) $(CFLAGS) -I $(INCLUDESDIR) -c $< -o $@

ifeq ($(shell $(MAKE) --question -C ./$(LIBFTDIR) ; echo $$?), 1)
.PHONY: $(LIBFTDIR)/$(LIBFTDIR).a
endif
ifeq ($(shell $(MAKE) --question -C ./$(MLXDIR) ; echo $$?), 1)
.PHONY: $(MLXDIR)/libmlx.a
endif

clean:
	$(QUIET)$(ECHO) "Cleaning the objects"
	$(QUIET)$(RM) $(RMFLAGS) $(OBJS)

fclean: clean
	$(QUIET)$(ECHO) "Deleting the library"
	$(QUIET)$(MAKE) -C $(LIBFTDIR) fclean
	$(QUIET)$(MAKE) -C $(MLXDIR) clean
	$(QUIET)$(RM) $(RMFLAGS) $(NAME) $(OBJDIR)

re: fclean all

norm:
	$(QUIET)$(ECHO) "${GREEN}Checking norm 101${NC}"
	$(QUIET)$(NORM) $(SRCDIR)/$(SRC) $(INCLUDESDIR)/*.h

gpush: fclean
	$(QUIET) git add *
	$(QUIET) git commit -m "quick push"
	$(QUIET) git push

test: fclean norm all
	$(QUIET)$(ECHO) "${GREEN}Testing${NC}"
	$(QUIET) ./ft_printftest
	$(QUIET)$(RM) $(RMFLAGS) $(NAME)	
