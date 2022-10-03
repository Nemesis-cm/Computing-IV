CC = g++
CFLAGS = -std=c++11 -c -g -O1  
LIBS = -lboost_unit_test_framework
OBJS = TextWriter.o RandWriter.o
EXE = TextWriter

all : $(EXE)

$(EXE) : $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

%.o : %.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean :
	\rm $(EXE) $(OBJS)