#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

class Sudoku
{
private:
    int board[9][9];
    long long recursiveCalls = 0;

    bool findEmptyCell(int &row, int &col)
    {
        for (row = 0; row < 9; row++)
        {
            for (col = 0; col < 9; col++)
            {
                if (board[row][col] == 0)
                    return true;
            }
        }
        return false;
    }

    bool isSafe(int row, int col, int num)
    {
        for (int i = 0; i < 9; i++)
            if (board[row][i] == num)
                return false;
        for (int i = 0; i < 9; i++)
            if (board[i][col] == num)
                return false;

        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[startRow + i][startCol + j] == num)
                    return false;

        return true;
    }

    bool solve()
    {
        recursiveCalls++;
        int row, col;
        if (!findEmptyCell(row, col))
            return true;

        for (int num = 1; num <= 9; num++)
        {
            if (isSafe(row, col, num))
            {
                board[row][col] = num;
                if (solve())
                    return true;
                board[row][col] = 0;
            }
        }
        return false;
    }

    bool isInitialBoardValid()
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == 0)
                    continue;
                int current = board[row][col];
                board[row][col] = 0;
                if (!isSafe(row, col, current))
                {
                    board[row][col] = current;
                    return false;
                }
                board[row][col] = current;
            }
        }
        return true;
    }

public:
    void inputBoard()
    {
        cout << "=====================================\n";
        cout << "          SUDOKU SOLVER\n";
        cout << "=====================================\n\n";
        cout << "Enter the Sudoku puzzle.\n";
        cout << "Use 0 for empty cells.\n\n";

        for (int row = 0; row < 9; row++)
        {
            cout << "Row " << row + 1 << " : ";
            for (int col = 0; col < 9; col++)
            {
                cin >> board[row][col];
                while (cin.fail() || board[row][col] < 0 || board[row][col] > 9)
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid value! Enter again : ";
                    cin >> board[row][col];
                }
            }
        }
        cout << "\nPuzzle loaded successfully.\n";
    }

    void printBoard()
    {
        cout << "\n+-------+-------+-------+\n";
        for (int row = 0; row < 9; row++)
        {
            cout << "| ";
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == 0)
                    cout << ". ";
                else
                    cout << board[row][col] << " ";
                if ((col + 1) % 3 == 0)
                    cout << "| ";
            }
            cout << endl;
            if ((row + 1) % 3 == 0)
                cout << "+-------+-------+-------+\n";
        }
    }

    bool validatePuzzle()
    {
        return isInitialBoardValid();
    }

    bool solvePuzzle()
    {
        return solve();
    }

    void printStatistics()
    {
        cout << "\nRecursive Calls : " << recursiveCalls << endl;
    }
};

int main()
{
    Sudoku sudoku;
    sudoku.inputBoard();

    if (!sudoku.validatePuzzle())
    {
        cout << "\nThe initial puzzle is invalid (conflicting values).\n";
        return 1;
    }

    cout << "\nInitial Puzzle:\n";
    sudoku.printBoard();

    auto start = chrono::high_resolution_clock::now();
    bool solved = sudoku.solvePuzzle();
    auto end = chrono::high_resolution_clock::now();

    if (solved)
    {
        cout << "\nSolved Puzzle:\n";
        sudoku.printBoard();
    }
    else
    {
        cout << "\nNo solution exists for the given puzzle.\n";
    }

    chrono::duration<double, milli> elapsed = end - start;
    cout << fixed << setprecision(3);
    cout << "\nTime taken     : " << elapsed.count() << " ms\n";
    sudoku.printStatistics();

    return 0;
}