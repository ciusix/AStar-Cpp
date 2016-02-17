#include "Cell.h"

Cell::Cell(int x, int y){
    this->h = 0;
    this->g = 0;
    this->x = x;
    this->y = y;
    parent = NULL;
    calculateF();
    wall = false;
    inSolution = false;
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
    return f;
}

void Cell::calculateF() {
    f = h + g;;
}

Cell* Cell::getParent() {
    return parent;
}

void Cell::setParent(Cell* parent) {
    this->parent = parent;
}

int Cell::getX() {
    return x;
}

int Cell::getY() {
    return y;
}

bool Cell::isWall() {
    return wall;
}

void Cell::setIsWall(bool wall) {
    this->wall = wall;
}

bool Cell::isInSolution() {
    return inSolution;
}

void Cell::setIsInSolution(bool inSolution) {
    this->inSolution = inSolution;
}