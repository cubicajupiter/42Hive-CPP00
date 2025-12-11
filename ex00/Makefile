# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 12:06:00 by jvalkama          #+#    #+#              #
#    Updated: 2025/12/11 17:00:52 by jvalkama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=megaphone

SRCDIR			:=src
VPATH			:=$(SRCDIR)
SRCS			:=______.cpp

OBJDIR			:=obj
OBJS			:=$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

COMPILER		:=c++
CXXFLAGS		:=-Wall -Wextra -Werror -std=c++17

INC_DIR			:=inc
INCLUDES		:=-I $(INC_DIR)

HEADER			:=$(INC_DIR)/________.hpp

RM				:=rm -f


all:				$(NAME)

$(OBJDIR):
						mkdir -p $(OBJDIR)

$(NAME):			$(OBJS)
						@echo "linking $@"
						$(COMPILER) $(CXXFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o:		$(SRCDIR)/%.cpp $(HEADER) | $(OBJDIR)
						@echo "Compiling $<"
						$(COMPILER) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
						@echo "Cleaning object files"
						@$(RM) $(OBJS)

fclean:				clean
						@echo "Cleaning all"
						@$(RM) $(NAME)
						@$(RM) -rf $(OBJDIR)

re:					fclean all

.PHONY: all clean fclean re
