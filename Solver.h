#ifndef SOLVER_H
#define SOLVER_H

#include "Labyrinth.h"

#define NORM_COST 10
#define DIAG_COST 14

class Solver {

    private:
        Labyrinth* labyrinth;
        
    public:
        Solver(Labyrinth*);
};

#endif