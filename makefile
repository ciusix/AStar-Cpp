CC = g++
CFLAGS = -DDEBUG -Wall

default: astar

build: clean astar

astar:  Solver.o FileReader.o
	$(CC) $(CFLAGS) -o astar main.cpp Solver.o Cell.o Labyrinth.o UIManager.o FileReader.o

Solver.o:  Solver.cpp Solver.h Cell.o Labyrinth.o UIManager.o
	$(CC) $(CFLAGS) -c Solver.cpp

Cell.o: Cell.cpp Cell.h
	$(CC) $(CFLAGS) -c Cell.cpp
	
Labyrinth.o:  Labyrinth.cpp Labyrinth.h Cell.o
	$(CC) $(CFLAGS) -c Labyrinth.cpp
    
UIManager.o: UIManager.cpp UIManager.h
	$(CC) $(CFLAGS) -c UIManager.cpp

FileReader.o: FileReader.cpp FileReader.h
	$(CC) $(CFLAGS) -c FileReader.cpp    	

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