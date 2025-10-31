/**
 * It uses include guards (#ifndef, #define, #endif) to prevent the header file (queen_solver.h)
 * from being included more than once in the same compilation unit.
 */



#ifndef QUEEN_SOLVER_H
#define QUEEN_SOLVER_H
#include <vector>


class QueenSolver {
public:
    QueenSolver();
    void solve();

private:
    int numQueens;
    int totalSolutions;
    bool isSafe(std::vector<int> board);
    int countQueensSolutions(std::vector<int> board);
};

#endif