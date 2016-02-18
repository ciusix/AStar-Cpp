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

Labyrinth* FileReader::getLabyrinth() {
    return NULL;
}

char FileReader::readChar(std::ifstream* file, char *flag) {
    static char c;
    if (!(file->get(c))) {
        (*flag) = CHAR_READ_FAIL;
    }
    return c;
}