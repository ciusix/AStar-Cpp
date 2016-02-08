#ifndef CELL_H
#define CELL_H

class Cell {

    private:
        int h, g, f;
        
    public:
        Cell();
        
        int getH();
        void setH(int);
        int getG();
        void setG(int);
        int getF();
        void calculateF();
        
};

#endif