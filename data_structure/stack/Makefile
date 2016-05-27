#################################################
# 针对C环境,一个目录下所有.c编译出一个可执行文件,
# 编写的Makefile
#
# $@:   目标文件
# $^:   所有的依赖文件
# $<:   第一个依赖文件.
#
# author:       gaochao
# email:        gaoc@dsp.ac.cn
# date:         2009/03/24
#################################################

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#		 need complete
#
# {exe(default), static, shared}
BINARY_TYPE := 

MODULE := stack

LFLAGS := 

CFLAGS := -Wall -MD -O2 
CFLAGS += 
#
#		     done
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#


ifeq ($(BINARY_TYPE), static)
	TARGET = $(addsuffix .a, $(addprefix lib, $(MODULE)))
else
ifeq ($(BINARY_TYPE), shared)
	TARGET = $(addsuffix .so, $(addprefix lib, $(MODULE)))
endif
endif

TARGET ?= $(MODULE)

.PHONY: all
all: createdir $(TARGET)
	chmod a+x $(TARGET)
	@echo "-------- $(TARGET) done ---------"

SOURCES := $(wildcard *.c)

OBJS := $(patsubst %.c, %.o, $(SOURCES))

OBJDIR := .objs

CROSS_COMPILE := 

AS := $(CROSS_COMPILE)as
LD := $(CROSS_COMPILE)ld
CC := $(CROSS_COMPILE)gcc

CXX := $(CROSS_COMPILE)g++
AR := $(CROSS_COMPILE)ar

MKDIR := mkdir -p
RM := rm -rf

.PHONY: createdir
createdir: 
	$(MKDIR) $(OBJDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$@ 

$(TARGET): $(OBJS)
ifeq ($(BINARY_TYPE), static)
	$(AR) rc $@ $(addprefix $(OBJDIR)/, $^)
else
ifeq ($(BINARY_TYPE), shared)
	$(CC) -shared -o $@ $(addprefix $(OBJDIR)/, $^)
else
	$(CC) -o $@ $(addprefix $(OBJDIR)/, $^) $(LFLAGS)
endif
endif

.PHONY: clean
clean:
	$(RM) $(TARGET)
	$(RM) $(OBJDIR)

