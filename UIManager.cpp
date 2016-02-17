#include "UIManager.h"

// Need to declare static variable like this
UIManager* UIManager::self;

UIManager::UIManager() {
    
}

UIManager* UIManager::get() {
    if (self == NULL) {
        self = new UIManager();
    }
    return self;
}
        
void UIManager::printLabyrinth(Labyrinth* labyrinth, bool onlyPath) {
    Cell* cell;
    int width, height, startX, startY, endX, endY;
    
    width = labyrinth->getWidth();
    height = labyrinth->getHeight();
    startX = labyrinth->getStartX();
    startY = labyrinth->getStartY();
    endX = labyrinth->getEndX();
    endY = labyrinth->getEndY();
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cell = labyrinth->getCell(x, y);
            std::cout << "+-------";
        }
        std::cout << "+" << std::endl;
        
        for (int x = 0; x < width; x++) {
            cell = labyrinth->getCell(x, y);
            if (x == startX && y == startY) {
                printf("| START ");
            } else if (x == endX && y == endY) {
                printf("| END   ");
            } else if (cell->isWall()) {
                printf("| WALL  ");
            } else {
                printf("|       ");
            }
        }
        std::cout << "|" << std::endl;
        
        for (int x = 0; x < width; x++) {
            cell = labyrinth->getCell(x, y);
            if (!onlyPath || cell->isInSolution()) {
                printf("| H=%3d ", cell->getH());
            } else {
                printf("|       ");
            }
        }
        std::cout << "|" << std::endl;
        
        for (int x = 0; x < width; x++) {
            cell = labyrinth->getCell(x, y);
            if (!onlyPath || cell->isInSolution()) {
                printf("| G=%3d ", cell->getG());
            } else {
                printf("|       ");
            }
        }

        std::cout << "|" << std::endl;
        
        for (int x = 0; x < width; x++) {
            cell = labyrinth->getCell(x, y);
            if (!onlyPath || cell->isInSolution()) {
                printf("| F=%3d ", cell->getF());
            } else {
                printf("|       ");
            }
        }

        std::cout << "|" << std::endl;
    }
    
    for (int x = 0; x < width; x++) {
        std::cout << "+-------";
    }
    std::cout << "+" << std::endl;
}

void UIManager::printList(std::vector<Cell*>* list, std::string name) {
    Cell* cell;
    std::cout << name << " list: ";
    for (unsigned int i = 0; i < list->size(); i++) {
        cell = list->at(i);
        std::cout << "(" << cell->getX() << ";" << cell->getY() << ") ";
    }
    std::cout << std::endl;
}