CC = g++
CFLAGS = -std=c++11 -c -g -Og 
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
OBJS = PhotoMagic.o FibLFSR.o
EXE = PhotoMagic

all : $(EXE)

PhotoMagic : $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LIBS)

FibLFSR.o : FibLFSR.cpp FibLFSR.h
	$(CC) $(CFLAGS) FibLFSR.cpp

PhotoMagic.o : PhotoMagic.cpp
	$(CC) $(CFLAGS) PhotoMagic.cpp


clean :
	\rm *.o $(EXE)