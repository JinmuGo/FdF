#
#

ifndef TOPDIR
		TOPDIR = $(abspath ../..)
endif
include $(TOPDIR)/config/Rules.mk
include $(TOPDIR)/config/color_rules.mk

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS =-O2 -Wno-deprecated

HEAD = mlx.h

all bonus:
	$(Q)$(call color_printf,$(CYAN),$(NOM),🎯 starting compile mlx)
	$(MAKE) $(NOM)
	$(Q)$(call color_printf,$(GREEN),$(NOM),🔰 done!)

$(NOM):	$(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)
	$(MAKE) files=$(NOM) src_dir=`pwd` dst_dir=$(TOPDIR)/lib link_files
	$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/includes link_files

fclean clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app
	$(Q)$(MAKE) files="$(NOM)" src_dir=`pwd` dst_dir=$(TOPDIR)/lib unlink_files
	$(Q)$(MAKE) files="$(HEAD)" src_dir=`pwd` dst_dir=$(TOPDIR)/includes unlink_files
	$(Q)$(call color_printf,$(RED),$(NOM),🗑️  remove Objects && Dependency file)

re: clean all
