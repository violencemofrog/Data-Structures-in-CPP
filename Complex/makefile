CC=g++
CFLAGS=-c -Wall

all:test

complex.o:complex.cpp complex.h
	$(CC) $(CFLAGS) complex.cpp

test:complex.o
	$(CC) $(CFLAGS) test.cpp
	$(CC) test.o complex.o -o test

.PHONY:clean
clean:
	-rm *.o test