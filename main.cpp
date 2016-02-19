#include "Labyrinth.h" 
#include "Solver.h"
#include "UIManager.h"
#include "FileReader.h"

int main (int argc, char *argv[]) {
    if (argc == 2) {
        Labyrinth* labyrinth = FileReader::get()->getLabyrinth(argv[1]);
        if (labyrinth != NULL) {
            labyrinth->calculateHeuristics();
            Solver* solver = new Solver(labyrinth);
            solver->solve();
        }
    }
}