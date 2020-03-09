CC=g++
CFLAGS=-c -Wall

all:test

vector.o:vector.cpp
	$(CC) $(CFLAGS) vector.cpp

test:vector.o
	$(CC) test.cpp vector.o -o test

clean:
	rm *.o test