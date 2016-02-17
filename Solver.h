#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <vector>
#include <limits>
#include <stdio.h>
#include <string.h>
#include <algorithm>

#include "Labyrinth.h"
#include "UIManager.h"

class Solver {

    private:
        Labyrinth* labyrinth;
        std::vector<Cell*> openList, closedList;
        std::vector<Cell*> solution;

        Cell* findCellWithLowestFInOpenList();
        bool cellInList(Cell*, std::vector<Cell*>*);
        void makePathFrom(Cell*);
        std::vector<Cell*> getSolution();
        
    public:
        Solver(Labyrinth*);
        
        void solve();
};

#endif