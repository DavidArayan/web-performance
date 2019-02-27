CC = emcc
OUTPT = index.js
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
	$(CC) -s WASM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap"]' -s ALLOW_MEMORY_GROWTH=1 --emrun -o $(OUTPT) $(CFLAGS) $(OBJS) $(LDFLAGS)