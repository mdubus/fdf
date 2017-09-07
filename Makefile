# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 14:11:57 by gpouyat           #+#    #+#              #
#*   Updated: 2016/12/01 11:50:27 by gpouyat          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CC			=	clang
NAME		=	fdf
FLAGS		=	-Wall -Wextra -Werror

LIBDIR		=	libft
LIBLINK		=	-L $(LIBDIR) -lft
LIB 		=	$(LIBDIR)/libft.a

INCLUDES	= 	-I ./includes

OBJDIR		=	objs
SRCDIR		=	srcs
SRC			=	main.c\
				parsing.c\
				parsing_split_temp.c\
				parsing_length.c\
				parsing_type_and_name_file.c\
				useful.c\
				useful2.c\
				print_tab.c\
				init.c\
				key_events.c\
				init_flat_points.c\
				put_flat_points.c\
				mouse_events.c\
				bresenham.c\
				bresenham_color.c\
				projection.c\
				int_rgb_converter.c\

OBJ			= $(SRC:.c=.o)
SRCS		=	$(addprefix $(SRCDIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))


all: directory $(NAME)

$(NAME): $(OBJDIR) $(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $@ $(OBJS) -L minilibx -lmlx -framework OpenGL -framework AppKit $(LIBLINK)

$(LIB):
	@make -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ $(INCLUDES)

directory: $(OBJDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBDIR) clean
	@rm -rf $(OBJDIR)
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all

.PHONY: clean all re fclean directory
