CC = gcc
CFLAGS = -O3
LDFLAGS	= -lm

INCS =\
	matrix4f.h\
	rand.h

SRC =\
	matrix4f.c\
	rand.c\
	main.c

OBJS =\
	src/matrix4f.o\
	src/rand.o\
	src/main.o

progc : $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS) $(LDFLAGS)