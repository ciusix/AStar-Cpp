#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

#include "Labyrinth.h"
#include "Cell.h"


class UIManager {
    
    private:
        UIManager();
    
        static UIManager* self;
    public:
        static UIManager* get();
        
        void printLabyrinth(Labyrinth*, bool);
        void printList(std::vector<Cell*>*, std::string);
    
};

#endif