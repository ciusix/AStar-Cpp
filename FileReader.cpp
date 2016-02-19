#include "FileReader.h"

// Need to declare static variable like this
FileReader* FileReader::self;

FileReader::FileReader() {
    
}

FileReader* FileReader::get() {
    if (self == NULL) {
        self = new FileReader();
    }
    return self;
}

Labyrinth* FileReader::getLabyrinth(std::string fileName) {
    
    std::ifstream inputFile;
    inputFile.open(fileName.c_str(), std::ios::binary | std::ios::in);
    
    if (inputFile.is_open()) {
    
        std::vector<std::vector<char> > characters;
        std::vector<char> newVector;
        characters.push_back(newVector);
        
        char letter = 0;
        char flag = CHAR_READ_SUCC;

        letter = readChar(&inputFile, &flag);
        
        while (flag != CHAR_READ_FAIL) {
            processChar(letter, &characters);
            letter = readChar(&inputFile, &flag);
        }
        
        inputFile.close();
        
        Labyrinth* labyrinth = new Labyrinth(characters.at(0).size(), characters.size());
        
        for (int x = 0; x < characters.at(0).size(); x++) {
            for (int y = 0; y < characters.size(); y++) {
                labyrinth->addCell(x, y, new Cell(x, y));
                
                if (characters.at(y).at(x) == '1') {
                    labyrinth->getCell(x, y)->setIsWall(true);
                } else if (characters.at(y).at(x) == 'S') {
                    labyrinth->setStartX(x);
                    labyrinth->setStartY(y);
                } else if (characters.at(y).at(x) == 'F') {
                    labyrinth->setEndX(x);
                    labyrinth->setEndY(y);
                }
            }
        }
        return labyrinth;
    }
    return NULL;
}

void FileReader::processChar(char character, std::vector<std::vector<char> > *characters) {
    if (character == '\n') {
        std::vector<char> newVector;
        characters->push_back(newVector);
    } else {
        characters->at(characters->size() - 1).push_back(character);
    }
}

char FileReader::readChar(std::ifstream* file, char *flag) {
    static char c;
    if (!(file->get(c))) {
        (*flag) = CHAR_READ_FAIL;
    }
    return c;
}