#ifndef CELL_H
#define CELL_H

#include <stdlib.h> 

class Cell {

    private:
        int x, y;
        int h, g, f;
        Cell* parent;
        bool wall;
        bool inSolution;
        
    public:
        Cell(int, int);
        
        int getH();
        void setH(int);
        int getG();
        void setG(int);
        int getF();
        void calculateF();
        Cell* getParent();
        void setParent(Cell*);
        int getX();
        int getY();
        bool isWall();
        void setIsWall(bool);
        bool isInSolution();
        void setIsInSolution(bool);
        
};

#endif