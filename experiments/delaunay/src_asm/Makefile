CC = em++
OUTPT = index.html
CFLAGS = -O3
LDFLAGS	= -lm

INCS =\
	decl.h\
	defs.h\
	extern.h\
	dc.h\
	edge.h

SRC =\
	dc.c\
	edge.c\
	error.c\
	i_o.c\
	main.c\
	memory.c\
	sort.c

OBJS =\
	src/dc.o\
	src/edge.o\
	src/error.o\
	src/i_o.o\
	src/main.o\
	src/memory.o\
	src/sort.o

progc : $(OBJS)
	$(CC) -s WASM=0 --emrun -o $(OUTPT) $(CFLAGS) $(OBJS) $(LDFLAGS)
