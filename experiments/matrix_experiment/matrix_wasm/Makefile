CC = em++
OUTPT = matexp.html
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
	matrix4f.o\
	rand.o\
	main.o

matexp : $(OBJS)
	$(CC) -s WASM=1 --emrun -o $(OUTPT) $(CFLAGS) $(OBJS) $(LDFLAGS)