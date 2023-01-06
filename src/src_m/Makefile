# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 14:05:59 by jgo               #+#    #+#              #
#    Updated: 2023/01/05 08:38:39 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ..)
endif

include $(TOPDIR)/config/Rules.mk
include $(TOPDIR)/config/color_rules.mk

FDF = fdf
NAME = $(FDF)

MLX_PROCESS = install_name_tool -change libmlx.dylib $(TOPDIR)/lib/libmlx.dylib $(NAME)
CPPFLAGS = -I$(TOPDIR)/includes -I./includes
LDFLAGS = -L$(TOPDIR)/lib
LDLIBS = -lftprintf -lft -lmlx -framework OpenGL -framework AppKit

DIRS = draw hooks input utils

HEADS = fdf.h \
		error.h	\
		declaration.h \
		input.h \
		utils.h \
		color.h \
		draw.h \
		event.h \
		hooks.h \
		key_map.h

SRCS = fdf.c \
		error.c \
		input.c \
		utils.c \
		input_utils.c \
		hook_utils.c \
		hook_key_press.c \
		edit_map.c \
		map_utils.c \
		matrix.c


OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

all bonus :
		$(Q)$(call color_printf,$(YELLOW),$(FDF),🎯 Start compiling)
		$(Q)$(foreach lib, $(LIBS), $(MAKE) TOPDIR=$(TOPDIR) -C $(lib) $@;)
		$(MAKE) $(NAME)
		$(Q)$(call color_printf,$(GREEN),$(FDF),✨ compiled!)

$(NAME): $(OBJS)
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@
	$(MLX_PROCESS)
	$(MAKE) files="$(HEADS)" src_dir=`pwd`/includes dst_dir=$(TOPDIR)/includes link_files
	$(MAKE) files="$(NAME)" src_dir=`pwd` dst_dir=$(TOPDIR) link_files
	
clean:
	$(Q)$(foreach lib, $(LIBS), $(MAKE) TOPDIR=$(TOPDIR) -C $(lib) $@;)
	$(MAKE) files="$(HEADS)" src_dir=`pwd` dst_dir=$(TOPDIR)/includes unlink_files
	$(RM) $(DEPS) $(OBJS)

fclean: clean
	$(Q)$(foreach lib, $(LIBS), $(MAKE) TOPDIR=$(TOPDIR) -C $(lib) $@;)
	$(MAKE) files="$(NAME)" src_dir=`pwd` dst_dir=$(TOPDIR) unlink_files
	$(RM) $(NAME)

re: fclean
	$(Q)$(foreach lib, $(LIBS), $(MAKE) TOPDIR=$(TOPDIR) -C $(lib) $@;)
	$(MAKE)

.PHONY: all clean fclean re bonus