#include "Labyrinth.h"

Labyrinth::Labyrinth(int width, int height){
    this->width = width;
    this->height = height;

    cells = new Cell*[width * height];
}

void Labyrinth::addCell(int x, int y, Cell* cell) {
    cells[y * height + x] = cell;
}

Cell* Labyrinth::getCell(int x, int y) {
    if (x >= 0 && y >= 0 && x < width && y < height) {
        return cells[y * height + x];
    } else {
        return NULL;
    }
}

void Labyrinth::calculateHeuristics() {
    int diag, norm;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            diag = abs(x - endX) < abs(y - endY) ? abs(x - endX) : abs(y - endY);
            norm = abs(x - endX) + abs(y - endY) - 2 * diag;
            getCell(x, y)->setH(diag * DIAG_COST + norm * NORM_COST);
        }
    }
}

void Labyrinth::setStartX(int startX) {
    this->startX = startX;
}

int Labyrinth::getStartX(){
    return startX;
}

void Labyrinth::setStartY(int startY){
    this->startY = startY;
}

int Labyrinth::getStartY(){
    return startY;
}

void Labyrinth::setEndX(int endX){
    this->endX = endX;
}

int Labyrinth::getEndX(){
    return endX;
}

void Labyrinth::setEndY(int endY){
    this->endY = endY;
}

int Labyrinth::getEndY(){
    return endY;
}

int Labyrinth::getNormCost() {
    return NORM_COST;
}

int Labyrinth::getDiagCost() {
    return DIAG_COST;
}

int Labyrinth::getWidth() {
    return width;
}

int Labyrinth::getHeight() {
    return height;
}

