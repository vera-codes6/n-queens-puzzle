/**
 * This code snippet prompts the user to input the maximum value of (k), representing the maximum number of ministers.
 * Then, for each number from 1 up to the maximum \( k \), it creates an instance of the `KMinistersSolver` class
 * and solves the ministers' problem for that particular value of (k). After obtaining the solutions,
 * it prints out a table displaying the number of ministers, the corresponding number of solutions found,
 * and the execution time for solving the problem using the `KMinistersSolver` class.
 **/



#include <iostream>
#include "KMinistersSolver.h"
using namespace std;


int main() {
    int max_k;
    cout << "---> Enter the maximum value of k: ";
    cin >> max_k;
    cout << "\n********************************************************************\n";
    cout << "Ministers\tNumber of Answers\tExecution Time (s)\n";
    for (int k = 1; k <= max_k; ++k) {
        KMinistersSolver solver;
        int solutions = solver.solve(k);
        double executionTime = solver.getExecutionTime();
        cout << k << "\t\t" << solutions << "\t\t\t" << executionTime << endl;
    }
    return 0;
}