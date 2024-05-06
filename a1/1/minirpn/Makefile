CC=gcc
CFLAGS=-g -Wall -fstack-protector-all
LIB=-lm

OBJECTS=rpn.o stack.o lex.o 

compile: $(OBJECTS)
	$(CC) $(CFLAGS) $(LIB) -o rpn $(OBJECTS)
	./tests.sh

all: compile

clean:
	rm -f *.o rpn
