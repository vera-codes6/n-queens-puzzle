/**
 * This code contains the main function.
 * It creates an instance of the QueenSolver class,
 * calls the solve method to find solutions for the N-Queens problem,
 * and then returns 0 to indicate successful execution.
 */



#include <iostream>
#include "queen_solver.h"


int main() {
    QueenSolver queenSolver;
    queenSolver.solve();
    return 0;
}