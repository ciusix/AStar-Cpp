#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <vector>
#include <limits>
#include <stdio.h>
#include <string.h>
#include <algorithm>

#include "Labyrinth.h"

class Solver {

    private:
        Labyrinth* labyrinth;
        std::vector<Cell*> openList, closedList;
        void printList(std::vector<Cell*>*, std::string);
        void addCellToOpenList(Cell*);
        void removeCellFromOpenList(Cell*);
        void addCellToClosedList(Cell*);
        Cell* findCellWithLowestFInOpenList();
        bool cellInList(Cell*, std::vector<Cell*>*);
        void printPathFrom(Cell*);        
        
    public:
        Solver(Labyrinth*);
        
        void solve();
};

#endif