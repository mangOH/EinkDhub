#
# Makefile
#
CC = $(TOOLCHAIN_DIR)/$(TOOLCHAIN_PREFIX)gcc
CFLAGS = -Wall -Wshadow -Wundef -Wmaybe-uninitialized
CFLAGS +=--sysroot=$(LEGATO_SYSROOT)
CFLAGS += -O3 -g3 -I./
CFLAGS += -fPIC

LDFLAGS += --sysroot=$(LEGATO_SYSROOT) 

LVGL_DIR = ${shell pwd}

MAINSRC = 

#LIBRARIES
include ./lvgl/lv_core/lv_core.mk
include ./lvgl/lv_hal/lv_hal.mk
include ./lvgl/lv_objx/lv_objx.mk
include ./lvgl/lv_fonts/lv_fonts.mk
include ./lvgl/lv_misc/lv_misc.mk
include ./lvgl/lv_themes/lv_themes.mk
include ./lvgl/lv_draw/lv_draw.mk

#DRIVERS
include ./lv_drivers/display/display.mk
include ./lv_drivers/indev/indev.mk

OBJEXT ?= .o

AOBJS = $(ASRCS:.S=$(OBJEXT))
COBJS = $(CSRCS:.c=$(OBJEXT))

MAINOBJ = $(MAINSRC:.c=$(OBJEXT))

SRCS = $(ASRCS) $(CSRCS) $(MAINSRC)
OBJS = $(AOBJS) $(COBJS)


all: clean default

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "CC $<"
    
default: $(AOBJS) $(COBJS) $(MAINOBJ)
	$(CC) $(MAINOBJ) $(AOBJS) $(COBJS) $(LDFLAGS) -o liblv.so -shared


clean: 
	rm -f $(BIN) $(AOBJS) $(COBJS) $(MAINOBJ)
