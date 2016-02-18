#ifndef FILEREADER_H
#define FILEREADER_H

#define CHAR_READ_SUCC 1
#define CHAR_READ_FAIL 0

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include "Labyrinth.h"

class FileReader {
    
    private:
        FileReader();
    
        static FileReader* self;
    
    char readChar(std::ifstream* file, char*);
    public:
        static FileReader* get();
    
        Labyrinth* getLabyrinth();
    
};

#endif