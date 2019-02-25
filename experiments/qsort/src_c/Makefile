CC = g++
CFLAGS = -O3
LDFLAGS	= -lm

INCS =\
	rand.h\
	main.h

SRC =\
	rand.c\
	main.c

OBJS =\
	src/rand.o\
	src/main.o

progc : $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS) $(LDFLAGS)