# N-Queens Puzzle (C++ and Python)

Solvers for the classic N-Queens problem (also known as the k-ministers problem) in C++ and a Python Jupyter notebook. The task is to place N queens on an N×N chessboard so that no two queens share a row, column, or diagonal.

## Repository structure

- `Back Tracking/` — C++ backtracking solver (`KMinistersSolver`) with timing and per-N solution counts.
- `Heuristic/` — C++ permutation-based solver that counts solutions by iterating permutations (named “Heuristic” in this repo).
- `Solver using Nested For Loops/` — Python Jupyter notebook showing a simple nested-loops approach.
- `docs/` — Additional notes or artifacts.

Note on naming: “k-ministers” in the code is equivalent to the N-Queens problem; k = N.

## Build and run (Windows PowerShell)

Prerequisites:
- A C++17 compiler (GCC/MinGW-w64, Clang, or MSVC). For MSVC, use a “Developer Command Prompt for VS” or call vcvars before building.
- Optional for the notebook: Python 3.8+ and Jupyter.

Create an output folder:

```
mkdir -Force bin
```

Build with GCC/MinGW-w64:

```
g++ -O2 -std=c++17 "Back Tracking\main.cpp" "Back Tracking\KMinistersSolver.cpp" -o bin\backtracking.exe
g++ -O2 -std=c++17 "Heuristic\main.cpp" "Heuristic\queen_solver.cpp" -o bin\permutation.exe
```

Build with MSVC (run in Developer Command Prompt or after setting vcvars):

```
cl /EHsc /O2 /std:c++17 "Back Tracking\main.cpp" "Back Tracking\KMinistersSolver.cpp" /Fe:bin\backtracking.exe
cl /EHsc /O2 /std:c++17 "Heuristic\main.cpp" "Heuristic\queen_solver.cpp" /Fe:bin\permutation.exe
```

Run the backtracking solver (prints number of solutions and execution time for each k from 1..K):

```
./bin/backtracking.exe
```

You will be prompted:
- Enter the maximum value of k (N). Output columns: “Ministers”, “Number of Answers”, “Execution Time (s)”.

Run the permutation-based solver (counts solutions for N = 1..N):

```
./bin/permutation.exe
```

You will be prompted:
- Enter the number of queens N. Output columns: “Queens”, “Solutions”.

Open and run the Python notebook:
- In VS Code, open `Solver using Nested For Loops/N_queensPuzzle.ipynb` and run the cells, or use Jupyter Lab/Notebook.

## Methods implemented

- Backtracking (C++): Depth-first search with pruning using row/diagonal safety checks. Tracks execution time per N.
- Permutation-based search (C++): Generates all row permutations and counts safe boards. Clear but exponential; intended for small N.
- Nested loops (Python, notebook): Illustrative brute-force approach for very small N.

## References

- GeeksforGeeks: N-Queen Problem (Backtracking) — https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/
- Wikipedia: N-queens puzzle — https://en.wikipedia.org/wiki/Eight_queens_puzzle
- Russell & Norvig, Artificial Intelligence: A Modern Approach (3rd ed.)

## License

This project is released under the MIT License. See `LICENSE` for details.