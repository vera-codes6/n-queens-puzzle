/**
 * This code represents the definition of the member functions of the QueenSolver class.
 * It implements the functionalities declared in the queen_solver.h header file.
 */



#include "queen_solver.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;


// Constructor for QueenSolver class
QueenSolver::QueenSolver() {
    numQueens      = 0;                                                                                 // Initialize the number of queens to 0
    totalSolutions = 0;                                                                                 // Initialize totalSolutions to 0
}

// Method to solve the N-Queens problem
void QueenSolver::solve() {
    cout << "****************************************************************\n";
    cout << "---> Enter the number of queens: \n";
    cin >> numQueens;
    cout << setw(10) << left << "Queens" << setw(15) << left << "Solutions" << endl;                    // Output column headers

    // Loop over increasing number of queens
    for (int i = 1; i <= numQueens; i++) {
        std::vector<int> queens(i);                                                                     // Create a vector to represent the current board state
        std::iota(queens.begin(), queens.end(), 0);                                                     // Initialize the board state
        int solutions = countQueensSolutions(queens);                                                   // Count the number of solutions for the current board state
        totalSolutions += solutions;                                                                    // Add the number of solutions to the total
        std::cout << std::setw(10) << std::left << i << std::setw(15) << std::left << solutions << std::endl;
    }
}

// Method to check if a board state is safe (no queens attacking each other)
bool QueenSolver::isSafe(std::vector<int> board) {
    int n = board.size();                                                                               // Get the size of the board
    for (int i = 0; i < n; i++) {                                                                       // Loop over all pairs of queens
        for (int j = i + 1; j < n; j++) {
            if (board[i] == board[j] || abs(i - j) == abs(board[i] - board[j])) {                       // Check if two queens are in the same row or diagonals
                return false;                                                                           // If any pair of queens attack each other, return false
            }
        }
    }
    return true;                                                                                        // If no queens attack each other, return true
}

// Method to count the number of solutions for a given board state
int QueenSolver::countQueensSolutions(std::vector<int> board) {
    int count = 0;                                                                                      // Initialize the count of solutions to 0
    do {
        if (isSafe(board)) {                                                                            // Check if the current board state is safe
            count++;                                                                                    // If safe, increment the count of solutions
        }
    } while (std::next_permutation(board.begin(), board.end()));                                        // Generate next permutation of the board
    return count; // Return the total count of solutions
}
