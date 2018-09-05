CC	= g++
CFLAGS	= -O3
LDFLAGS	= -lm
INCS =\
	matrix4f.h

SRC =\
	matrix4f.c\
	main.c

OBJS =\
	matrix4f.o\
	main.o

matexp	: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS) $(LDFLAGS)