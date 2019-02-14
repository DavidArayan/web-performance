CC = em++
OUTPT = index.html
CFLAGS = -O3
LDFLAGS	= -lm

INCS =\
	main.h

SRC =\
	main.c

OBJS =\
	src/main.o

progc : $(OBJS)
	$(CC) -s WASM=1 --emrun -o $(OUTPT) $(CFLAGS) $(OBJS) $(LDFLAGS)