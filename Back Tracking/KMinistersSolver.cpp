/**
 * This code defines a class `KMinistersSolver` for solving the k-ministers problem using backtracking.
 * The class includes functions for checking the safety of a placement, backtracking to explore solutions,
 * solving the problem for a given number of ministers, and retrieving the execution time.
 **/



#include "KMinistersSolver.h"
#include <iostream>
using namespace std;
using namespace std::chrono;


// Constructor to initialize solutions and execution time
KMinistersSolver::KMinistersSolver() {
    solutions     = 0;
    executionTime = 0.0;
}

// Function to check if placing a minister at a position is safe
bool KMinistersSolver::isSafe(int row, int col) {
    // Check if there is a conflict with previously placed ministers
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || abs(i - row) == abs(board[i] - col)) {
            return false;
        }
    }
    return true;
}

// Backtracking algorithm to find solutions for the k-ministers problem
void KMinistersSolver::kMinisterBacktracking(int k, int row) {
    // Base case: All ministers placed, increment solutions count
    if (row == k) {
        ++solutions;
        return;
    }
    // Explore possible positions for the current minister
    for (int col = 0; col < k; ++col) {
        if (isSafe(row, col)) {
            board[row] = col;                                                        // Place minister at a safe position and move to the next row
            kMinisterBacktracking(k, row + 1);
            board[row] = -1;                                                         // Reset for backtracking
        }
    }
}

// Solve function to initialize and start the backtracking algorithm
int KMinistersSolver::solve(int k) {
    board = vector<int>(k, -1);                                                      // Initialize board with -1 (no ministers placed initially)
    auto start = high_resolution_clock::now();                                 // Measure execution time
    kMinisterBacktracking(k, 0);                                                // Start backtracking algorithm
    auto end = high_resolution_clock::now();                                   // Measure execution time and convert to seconds
    auto duration = duration_cast<microseconds>(end - start);
    executionTime = duration.count() / 1e6;
    return solutions;
}

// Function to get the execution time of the last solve operation
double KMinistersSolver::getExecutionTime() {
    return executionTime;                                                           // Return the execution time
}