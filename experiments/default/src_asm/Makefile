CC = em++
OUTPT = index.html
CFLAGS = -O3
LDFLAGS	= -lm
INCS =\
	src/main.h

SRC =\
	src/main.c

OBJS =\
	main.o

progc : $(OBJS)
	$(CC) -s WASM=0 --emrun -o $(OUTPT) $(CFLAGS) $(OBJS) $(LDFLAGS)