#include "Cell.h"

Cell::Cell(){
    this->h = -1;
    this->g = 0;
    calculateF();
}

int Cell::getH() {
    return h;
}
void Cell::setH(int h) {
    this->h = h;
}

int Cell::getG() {
    return g;
}

void Cell::setG(int g) {
    this->g = g;
}

int Cell::getF() {
    return g;
}

void Cell::calculateF() {
    f = h + g;;
}