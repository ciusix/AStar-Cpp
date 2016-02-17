#include "Solver.h"

Solver::Solver(Labyrinth* labyrinth){
    this->labyrinth = labyrinth;
}

void Solver::solve() {
#ifdef DEBUG
    std::cout << "Solver started solve()" << std::endl;
#endif
    
    addCellToOpenList(labyrinth->getCell(labyrinth->getStartX(), labyrinth->getStartY()));
    
#ifdef DEBUG
    printList(&openList, "Open");
#endif   

    Cell* finishCell = labyrinth->getCell(labyrinth->getEndX(), labyrinth->getEndY());

    while (true) { 
        Cell* lowestFCell = findCellWithLowestFInOpenList();
        
        int x = lowestFCell->getX();
        int y = lowestFCell->getY();
        
        for (short dx = -1; dx <= 1; dx++) {   
            for (short dy = -1; dy <= 1; dy++) {
                if (!(dx == 0 && dy == 0)) {
                    Cell* neighbour = labyrinth->getCell(x + dx, y + dy);
                    if (neighbour != NULL && !neighbour->isWall() && !cellInList(neighbour, &closedList)) {
                        
                        if (!cellInList(neighbour, &openList)) {
                            addCellToOpenList(neighbour);
                        }
                        if (neighbour->getG() == 0 || neighbour->getG() > lowestFCell->getG() + (dx == 0 || dy == 0 ? labyrinth->getNormCost() : labyrinth->getDiagCost())) {
                            neighbour->setG(lowestFCell->getG() + (dx == 0 || dy == 0 ? labyrinth->getNormCost() : labyrinth->getDiagCost()));
                            neighbour->setParent(lowestFCell);
                            neighbour->calculateF();
                        }
                        
                        if (neighbour == finishCell) {
                            std::cout << "Solution: ";
                            finishCell->setIsInSolution(true);
                            printPathFrom(finishCell);
                            std::cout << std::endl;
                            labyrinth->printLabyrinthSolution();
                            return;
                        }
                    }
                }
            }
        }

        addCellToClosedList(lowestFCell);
        removeCellFromOpenList(lowestFCell);
        
#ifdef DEBUG
        labyrinth->printLabyrinth();
        printList(&openList, "Open");
        printList(&closedList, "Closed");
#endif 
        
    }
    
#ifdef DEBUG 
    std::cout << "Solver ended solve()" << std::endl;
#endif
}

void Solver::printList(std::vector<Cell*>* list, std::string name) {
    Cell* cell;
    std::cout << name << " list: ";
    for (unsigned int i = 0; i < list->size(); i++) {
        cell = list->at(i);
        std::cout << "(" << cell->getX() << ";" << cell->getY() << ") ";
    }
    std::cout << std::endl;
}

void Solver::addCellToOpenList(Cell* cell) {
    if (cell != NULL) {
        for (unsigned int i = 0; i < closedList.size(); i++) {
            if (cell == closedList.at(i)) {
                return;
            }
        }
        for (unsigned int i = 0; i < openList.size(); i++) {
            if (cell == openList.at(i)) {
                return;
            }
        }
        openList.push_back(cell);
    }
}

void Solver::removeCellFromOpenList(Cell* cell) {
    if (cell != NULL) {
        std::vector<Cell*>::iterator position = std::find(openList.begin(), openList.end(), cell);
        if (position != openList.end()) {
            openList.erase(position);
        }
    }
}

void Solver::addCellToClosedList(Cell* cell) {
    if (cell != NULL) {
        closedList.push_back(cell);
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

void Solver::printPathFrom(Cell* cell) {
    if (cell != NULL) {
        printPathFrom(cell->getParent());
        std::cout << "(" << cell->getX() << ";" << cell->getY() << ")";
        cell->setIsInSolution(true);
    }
}