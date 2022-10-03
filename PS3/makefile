CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: Triangle

Triangle: Tfractal.o Triangle.o
	$(CC) Tfractal.o Triangle.o -o Triangle $(LFLAGS)

Tfractal.o:	Tfractal.cpp Triangle.hpp
	$(CC) -c Tfractal.cpp $(CFLAGS)

Triangle.o: Triangle.cpp Triangle.hpp
	$(CC) -c Triangle.cpp $(CFLAGS)

clean:
	rm Triangle
	rm Tfractal.o
	rm Triangle.o