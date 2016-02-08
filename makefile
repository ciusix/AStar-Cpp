CC = g++
CFLAGS = -Wall -static-libgcc -static-libstdc++

default: astar

build: clean astar

astar:  Solver.o
	$(CC) $(CFLAGS) -o astar main.cpp Solver.o Cell.o Labyrinth.o

Solver.o:  Solver.cpp Solver.h Cell.o Labyrinth.o
	$(CC) $(CFLAGS) -c Solver.cpp

Cell.o: Cell.cpp Cell.h
	$(CC) $(CFLAGS) -c Cell.cpp
	
Labyrinth.o:  Labyrinth.cpp Labyrinth.h Cell.o
	$(CC) $(CFLAGS) -c Labyrinth.cpp
    	
clean:
ifeq ($(OS),Windows_NT)
	del *.o
	del *.gch
	del *.exe
else
	-rm *.o
	-rm *.gch
	-rm astar
endif