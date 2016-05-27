###############################################
# 针对C环境,一个文件对应一个可执行文件,
# 编写的Makefile
#
# $@:	目标文件
# $^:	所有的依赖文件
# $<:	第一个依赖文件.
#
# author: 	gaochao
# email:	gc1011@mail.ustc.edu.cn
# date:		2007/05/17
###############################################

SOURCES = $(wildcard *.c)

TARGET = $(patsubst %.c,%,$(SOURCES))

CC = gcc

CFLAGS = -Wall -O -g

LINKS =   

# 直接生成可执行文件
%: %.c
	$(CC) $< $(CFLAGS) $(LINKS) -o $@

# 多目标
.PHONY: all
all: $(TARGET)
	chmod a+x $(TARGET)

.PHONY: clean
clean:
	rm -rf *.o $(TARGET)

