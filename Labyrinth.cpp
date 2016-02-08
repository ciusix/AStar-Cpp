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
    return cells[y * height + x];
}

void Labyrinth::calculateHeuristics() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            getCell(x, y)->setH(abs(x - endX) + abs(y - endY));
        }
    }
}

void Labyrinth::printLabyrinth() {
    Cell* cell;
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cell = getCell(x, y);
            std::cout << "+-------";
        }
        std::cout << "+" << std::endl;
        
        for (int x = 0; x < width; x++) {
            cell = getCell(x, y);
            printf("| H=%3d ", cell->getH());
        }

        std::cout << "|" << std::endl;
        
        for (int x = 0; x < width; x++) {
            cell = getCell(x, y);
            printf("| G=%3d ", cell->getG());
        }

        std::cout << "|" << std::endl;
        
        for (int x = 0; x < width; x++) {
            cell = getCell(x, y);
            printf("| F=%3d ", cell->getF());
        }

        std::cout << "|" << std::endl;
    }
    
    for (int x = 0; x < width; x++) {
        std::cout << "+-------";
    }
    std::cout << "+" << std::endl;
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
