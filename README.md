# Sudoku Solver (C++)

A command-line Sudoku Solver written in **C++** that uses the **Backtracking Algorithm** to solve any valid **9×9 Sudoku puzzle**. The program validates the input puzzle, displays the board in a clean formatted layout, and reports solving performance, including execution time and the number of recursive calls.

---

## Features

- Solves any valid **9×9 Sudoku** puzzle using recursive backtracking.
- Validates the initial puzzle for conflicting values before solving.
- Displays the Sudoku board in a clean, easy-to-read format with grid separators.
- Reports:
  - Solve time (in milliseconds)
  - Total recursive calls
- Handles invalid input gracefully by re-prompting the user.

---

## How It Works

The solver follows the classic **Backtracking Algorithm**:

1. Find the next empty cell (`0`) on the Sudoku board.
2. Try placing digits **1–9** in that cell.
3. Check whether the digit is safe by ensuring it does not already exist in:
   - The same row
   - The same column
   - The corresponding **3×3** subgrid
4. If the placement is valid, recursively solve the remaining board.
5. If the recursion reaches a dead end, remove the digit (backtrack) and try the next one.
6. Continue until every cell is filled or determine that no valid solution exists.

---

## Requirements

- A C++ compiler supporting **C++11** or later.
- Examples:
  - g++
  - clang++
  - Microsoft Visual C++ (MSVC)

---

## Compiling

```bash
g++ -std=c++11 -o sudoku sudoku_solver.cpp
```

---

## Running

Linux/macOS:

```bash
./sudoku
```

Windows:

```bash
sudoku.exe
```

---

## Possible Improvements

- Read Sudoku puzzles directly from a file.
- Implement constraint propagation techniques (e.g., Naked Singles) to reduce recursive calls.
- Support solving multiple Sudoku puzzles in a single execution.
- Add unit tests for the `isSafe()` and `solve()` functions.
- Generate random valid and solvable Sudoku puzzles.
- Develop a graphical user interface (GUI).

---

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- Backtracking Algorithm
- Standard Template Library (STL)
- `<chrono>` for execution time measurement
