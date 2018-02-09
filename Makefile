CXXFLAGS ?= -std=c++11
CXX := g++
CC := g++

all: int_cast_test

int_cast_test.o: int_cast.h

clean:
	rm -f *.o
	rm -f int_cast_test
