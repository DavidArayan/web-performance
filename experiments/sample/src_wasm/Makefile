CC = em++
OUTPT = index.js
CFLAGS = -O3
LDFLAGS	= -lm

INCS =\
	main.h

SRC =\
	main.c

OBJS =\
	src/main.o

progc : $(OBJS)
	$(CC) -s WASM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap"]' --emrun -o $(OUTPT) $(CFLAGS) $(OBJS) $(LDFLAGS)