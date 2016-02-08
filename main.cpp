#include "Labyrinth.h" 
#include "Solver.h"

Labyrinth* simpleLabyrinth();

int main (int argc, char *argv[]) {
    Labyrinth* labyrinth = simpleLabyrinth();
    
    labyrinth->printLabyrinth();
    Solver* solver = new Solver(labyrinth);
    
}

Labyrinth* simpleLabyrinth() {
    Labyrinth* labyrinth = new Labyrinth(5,5);
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            labyrinth->addCell(x, y, new Cell());
        }
    }
    
    labyrinth->setStartX(1);
    labyrinth->setStartY(1);
    labyrinth->setEndX(4);
    labyrinth->setEndY(3);
    
    labyrinth->calculateHeuristics();
    
    return labyrinth;
}