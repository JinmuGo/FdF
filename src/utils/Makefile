# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 08:31:25 by jgo               #+#    #+#              #
#    Updated: 2023/05/27 19:20:22 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ../../)
endif

include $(TOPDIR)/make_config/src/Rules.mk
include $(TOPDIR)/make_config/com/ColorRules.mk

SRCS = error.c \
		input_utils.c \
		print_status.c \
		print_utils.c \
		input.c \
		matrix.c \
		utils.c \
		color.c

NAME = utils.a

CPPFLAGS = -I$(TOPDIR)/includes -I../includes
LDFLAGS = -L$(TOPDIR)/lib

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

all bonus : 
	$(Q)$(call color_printf,$(CYAN),$(NAME),🎯 starting compile $(NAME))
	$(Q)$(MAKE) $(NAME)
	$(Q)$(call color_printf,$(GREEN),$(NAME),🔰 done!)

$(NAME): $(OBJS)
	$(Q)$(call color_printf,$(GREEN),$(NAME),📚 archive object)
	$(AR) $(ARFLAGS) $@ $^
	$(Q)$(MAKE) files="$(NAME)" src_dir=`pwd` dst_dir=$(TOPDIR)/src/lib link_files
	
clean:
	$(Q)$(MAKE) files="$(NAME)" src_dir=`pwd` dst_dir=$(TOPDIR)/src/lib unlink_files
	$(Q)$(call color_printf,$(RED),$(NAME),🗑️  remove Objects && Dependency file)
	$(RM) $(OBJS) $(DEPS)

fclean: clean
		$(Q)$(call color_printf,$(RED),$(NAME),🗑️  remove $(NAME))
		$(RM) $(NAME)
	
re : fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus