#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <stdio.h>
#include <stdlib.h> 
#include <iostream>

#include "Cell.h"

#define NORM_COST 10
#define DIAG_COST 14

class Labyrinth {

    private:
        int startX, startY, endX, endY;
        int width, height;
        Cell **cells; // Pointer to array of pointers
        
    public:
        Labyrinth(int, int);
        void addCell(int, int, Cell*);
        Cell* getCell(int, int);
        
        void setStartX(int);
        int getStartX();
        void setStartY(int);
        int getStartY();
        void setEndX(int);
        int getEndX();
        void setEndY(int);
        int getEndY();
        void calculateHeuristics();
        int getNormCost();
        int getDiagCost();
        int getWidth();
        int getHeight();
};

#endif