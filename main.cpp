#include "Labyrinth.h" 
#include "Solver.h"
#include "UIManager.h"

Labyrinth* simpleLabyrinth();

int main (int argc, char *argv[]) {
    Labyrinth* labyrinth = simpleLabyrinth();
    
    // UIManager::get()->printLabyrinth(labyrinth, false);
    Solver* solver = new Solver(labyrinth);
    
    solver->solve();
    
}

Labyrinth* simpleLabyrinth() {
    Labyrinth* labyrinth = new Labyrinth(8,8);
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            labyrinth->addCell(x, y, new Cell(x, y));
        }
    }
    
    labyrinth->setStartX(1);
    labyrinth->setStartY(1);
    labyrinth->setEndX(6);
    labyrinth->setEndY(5);
    
    labyrinth->getCell(4, 2)->setIsWall(true);
    labyrinth->getCell(4, 3)->setIsWall(true);
    labyrinth->getCell(4, 4)->setIsWall(true);
    labyrinth->getCell(3, 4)->setIsWall(true);
    labyrinth->getCell(2, 4)->setIsWall(true);
    labyrinth->getCell(5, 3)->setIsWall(true);
    labyrinth->getCell(6, 3)->setIsWall(true);
    labyrinth->getCell(4, 5)->setIsWall(true);
    
    labyrinth->calculateHeuristics();
    
    return labyrinth;
}