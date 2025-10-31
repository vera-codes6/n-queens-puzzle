/**
 * This code defines a class named `KMinistersSolver` for solving the k-ministers problem using backtracking.
 * It includes private data members for the chessboard, the count of solutions found, and the execution time of the algorithm.
 * The class contains methods for checking the safety of placing a minister, performing backtracking, initializing the solver,
 * solving the problem for a given k, and retrieving the execution time. The header guard `KMINISTERSSOLVER_H` 
 * prevents multiple inclusions of the header file in the same translation unit.
 **/



#ifndef KMINISTERSSOLVER_H
#define KMINISTERSSOLVER_H
#include <vector>
#include <chrono>


class KMinistersSolver {
private:
    std::vector<int> board;
    int solutions;
    double executionTime;
    bool isSafe(int row, int col);
    void kMinisterBacktracking(int k, int row);

public:
    KMinistersSolver();
    int solve(int k);
    double getExecutionTime();
};

#endif