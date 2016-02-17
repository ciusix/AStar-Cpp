#include "Solver.h"

Solver::Solver(Labyrinth* labyrinth){
    this->labyrinth = labyrinth;
}

void Solver::solve() {    
    Cell* startCell = labyrinth->getCell(labyrinth->getStartX(), labyrinth->getStartY());
    Cell* finishCell = labyrinth->getCell(labyrinth->getEndX(), labyrinth->getEndY());
    
    startCell->calculateF();
    openList.push_back(startCell);

    while (true) { 
        Cell* lowestFCell = findCellWithLowestFInOpenList();
        
        for (short dx = -1; dx <= 1; dx++) {   
            for (short dy = -1; dy <= 1; dy++) {
                if (!(dx == 0 && dy == 0)) {
                    Cell* neighbour = labyrinth->getCell(lowestFCell->getX() + dx, lowestFCell->getY() + dy);
                    if (neighbour != NULL && !neighbour->isWall() && !cellInList(neighbour, &closedList)) {
                        
                        if (!cellInList(neighbour, &openList)) {
                            openList.push_back(neighbour);
                        }
                        
                        if (neighbour->getG() == 0 || neighbour->getG() > lowestFCell->getG() + (dx == 0 || dy == 0 ? labyrinth->getNormCost() : labyrinth->getDiagCost())) {
                            neighbour->setG(lowestFCell->getG() + (dx == 0 || dy == 0 ? labyrinth->getNormCost() : labyrinth->getDiagCost()));
                            neighbour->setParent(lowestFCell);
                            neighbour->calculateF();
                        }
                        
                        if (neighbour == finishCell) {
                            makePathFrom(finishCell);
#ifdef DEBUG
                            UIManager::get()->printLabyrinth(labyrinth, true);
#endif
                            return;
                        }
                    }
                }
            }
        }

        closedList.push_back(lowestFCell);
        openList.erase(std::remove(openList.begin(), openList.end(), lowestFCell), openList.end()); 
        
        if (openList.size() < 1) {
            break;
        }
    }
}

Cell* Solver::findCellWithLowestFInOpenList() {
    Cell* lowestFCell = NULL;
    Cell* currentCell;
    int lowestCost = std::numeric_limits<int>::max();
    for (unsigned int i = 0; i < openList.size(); i++) {
        currentCell = openList.at(i);
        if (currentCell->getF() < lowestCost) {
            lowestCost = currentCell->getF();
            lowestFCell = currentCell;
        }
    }
    return lowestFCell;
}

bool Solver::cellInList(Cell* cell, std::vector<Cell*>* list) {
    if (cell != NULL) {
        std::vector<Cell*>::iterator position = std::find(list->begin(), list->end(), cell);
        if (position != list->end()) {
            return true;
        }
    }
    return false;
}

void Solver::makePathFrom(Cell* cell) {
    if (cell != NULL) {
        makePathFrom(cell->getParent());
        cell->setIsInSolution(true);
        solution.push_back(cell);
    }
}

std::vector<Cell*> Solver::getSolution() {
    return solution;
}