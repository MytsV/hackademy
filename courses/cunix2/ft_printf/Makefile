CC			:= gcc
RM			:= rm -rf
CFLAGS		= -std=c99 -Iinclude -g -c
SRCS		:= $(wildcard src/*.c) $(wildcard src/tools/*.c)
OBJS		:= $(SRCS:.c=.o)
LIB_NAME	:= libprintf.a
STYLE50		:= ~/.local/bin/style50


printf:		fclean $(OBJS)
			@$(CC) $(CFLAGS) $(SRCS)

all:		fclean $(OBJS)
			@$(CC) $(CFLAGS) $(SRCS)
			@ar -rcs $(LIB_NAME) $(OBJS)

checkstyle:
			$(STYLE50) $(SRCS)

fclean:
			$(RM) $(OBJS) $(LIB_NAME)
