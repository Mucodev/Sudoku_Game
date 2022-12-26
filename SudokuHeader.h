#ifndef Sudoku
#define Sudoku

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <time.h>
#include <cstdlib>

using namespace std;

class SudokuGame
{
private:
    int sudokuArray[9][9]/* =
    {
        {0, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 1, 0, 0, 0},
        {0, 7, 8, 0, 0, 0, 0, 0, 1},
        {0, 0, 4, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 2, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0} }*/;
    /*
    int[][] grid =
    {
     {5, 3, 0, 0, 7, 0, 0, 0, 0},
     {6, 0, 0, 1, 9, 5, 0, 0, 0},
     {0, 9, 8, 0, 0, 0, 0, 6, 0},
     {8, 0, 0, 0, 6, 0, 0, 0, 3},
     {4, 0, 0, 8, 0, 3, 0, 0, 1},
     {7, 0, 0, 0, 2, 0, 0, 0, 6},
     {0, 6, 0, 0, 0, 0, 2, 8, 0},
     {0, 0, 0, 4, 1, 9, 0, 0, 5},
     {0, 0, 0, 0, 8, 0, 0, 7, 9},
    };
    int[][] grid =
    {
     {0, 6, 0, 1, 0, 4, 0, 5, 0},
     {0, 0, 8, 3, 0, 5, 6, 0, 0},
     {2, 0, 0, 0, 0, 0, 0, 0, 1},
     {8, 0, 0, 4, 0, 7, 0, 0, 6},
     {0, 0, 6, 0, 0, 0, 3, 0, 0},
     {7, 0, 0, 9, 0, 1, 0, 0, 4},
     {5, 0, 0, 0, 0, 0, 0, 0, 2},
     {0, 0, 7, 2, 0, 6, 9, 0, 0},
     {0, 4, 0, 5, 0, 8, 0, 7, 0},
    };
    int[][] grid =
    {
     {8, 0, 0, 0, 0, 7, 0, 0, 0},
     {0, 6, 2, 0, 4, 0, 0, 0, 0},
     {0, 3, 0, 0, 0, 5, 7, 0, 0},
     {9, 0, 0, 0, 0, 2, 0, 4, 0},
     {5, 0, 0, 4, 0, 1, 0, 0, 9},
     {0, 4, 0, 9, 0, 0, 0, 0, 7},
     {0, 0, 1, 3, 0, 0, 0, 7, 0},
     {0, 0, 0, 0, 5, 0, 2, 8, 0},
     {0, 0, 0, 8, 0, 0, 0, 0, 3},
    };
    */

    int sudokuDiff[9][9];
public:
    SudokuGame()
    {
        cout << setw(50) << "Welcome to Sudoku Game" << endl
             << setw(40)
             << "Rules" << endl
             << endl
             << setw(20) << "1. Use Numbers 1-9" << endl
             << setw(59) << "2. Don't Repeat Any Numbers(each row, column and square) " << endl;
        cout << "Press any key to continue...";
        (void) _getch();
        cout << endl;
    }

    /* bool checkNum(int number)
     {
         for (int i = 1; i < 10; i++)
         {
             if (i == number)
             {
                 return false;
             }
         }
         return true;
     }

     void sudokuGenerator()
     {
         srand(time(NULL));
         int count = 0;

         while (count != 30)
         {
             int i = rand() % 9;
             int j = rand() % 9;
             int number = rand() % 9 + 1;

             if (rowControl(i + 1, number))
             {
                 if (columnControl(j + 1, number))
                 {
                     if (squareControl(i, j, number))
                     {
                         sudokuArray[i][j] = number;
                         count++;
                     }
                 }
             }
         }

         for (int row = 0; row < 9; row++)
         {
             for (int column = 0; column < 9; column++)
             {
                 if (checkNum(sudokuArray[row][column]))
                 {
                     sudokuArray[row][column] = 0;
                 }
             }
         }
     }   muco generator    */

    bool canPlace(int num, int row, int col)
    {
        // Check if the given number already exists in the row or column
        for (int i = 0; i < 9; i++)
        {
            if (sudokuArray[row][i] == num || sudokuArray[i][col] == num)
            {
                return false;
            }
        }

        // Check if the given number already exists in the 3x3 sub-grid
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = startRow; i < startRow + 3; i++)
        {
            for (int j = startCol; j < startCol + 3; j++)
            {
                if (sudokuArray[i][j] == num)
                {
                    return false;
                }
            }
        }

        // The number can be placed at the given position
        return true;
    }

    bool generateUtil(int row, int col)
    {
        if (col == 9)
        {
            col = 0;
            row++;
        }

        if (row == 9)
        {
            return true;
        }

        if (sudokuArray[row][col] != 0)
        {
            return generateUtil(row, col + 1);
        }

        for (int num = 1; num <= 9; num++)
        {
            if (canPlace(num, row, col))
            {
                sudokuArray[row][col] = num;
                if (generateUtil(row, col + 1))
                {
                    return true;
                }

                sudokuArray[row][col] = 0;
            }
        }

        // No solution found
        return false;
    }

    void generate()
    {
        memset(sudokuArray, 0, sizeof sudokuArray);

        generateUtil(0, 0);
    }

    void sudokuDifficulty(int num)
    {
        int count = 0;

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                sudokuDiff[i][j] = sudokuArray[i][j];
            }
        }

        if (num == 1)
        {
            while (count != 81 - 36)
            {
                int i = rand() % 9;
                int j = rand() % 9;

                if (sudokuDiff[i][j] != 0)
                {
                    sudokuDiff[i][j] = 0;
                    count++;
                }
            }
        }

        else if (num == 2)
        {
            while (count != 81 - 30)
            {
                int i = rand() % 9;
                int j = rand() % 9;

                if (sudokuDiff[i][j] != 0)
                {
                    sudokuDiff[i][j] = 0;
                    count++;
                }
            }
        }

        if (num == 3)
        {
            while (count != 81 - 23)
            {
                int i = rand() % 9;
                int j = rand() % 9;

                if (sudokuDiff[i][j] != 0)
                {
                    sudokuDiff[i][j] = 0;
                    count++;
                }
            }
        }

        if (num == 4)
        {
            while (count != 81 - 17)
            {
                int i = rand() % 9;
                int j = rand() % 9;

                if (sudokuDiff[i][j] != 0)
                {
                    sudokuDiff[i][j] = 0;
                    count++;
                }
            }
        }

    }

    void displayGame() // Alperen
    {
        cout << "#   1 2 3   4 5 6   7 8 9" << endl
             << "+ | - - - + - - - + - - -" << endl;

        for (int i = 0; i < 9; i++)
        {
            cout << (i + 1) << " | ";

            for (int j = 0; j < 9; j++)
            {

                if (sudokuArray[i][j] == 0)
                {
                    cout << ". ";
                }

                else if (sudokuArray[i][j] != 0)
                {
                    cout << sudokuArray[i][j] << " ";
                }

                if (j == 2 || j == 5)
                {
                    cout << "| ";
                }

                else if (j == 8)
                {
                    cout << endl;
                }
            }

            if (i == 2 || i == 5)
            {
                cout << "  | - - - + - - - + - - -" << endl;
            }
        }
    }

    void displayGame2() // Alperen
    {
        cout << "#   1 2 3   4 5 6   7 8 9" << endl
             << "+ | - - - + - - - + - - -" << endl;

        for (int i = 0; i < 9; i++)
        {
            cout << (i + 1) << " | ";

            for (int j = 0; j < 9; j++)
            {

                if (sudokuDiff[i][j] == 0)
                {
                    cout << ". ";
                }

                else if (sudokuDiff[i][j] != 0)
                {
                    cout << sudokuDiff[i][j] << " ";
                }

                if (j == 2 || j == 5)
                {
                    cout << "| ";
                }

                else if (j == 8)
                {
                    cout << endl;
                }
            }

            if (i == 2 || i == 5)
            {
                cout << "  | - - - + - - - + - - -" << endl;
            }
        }
    }

    bool columnControl(int column, int tnumber)   //Onur
    {
        for (int i = 0; i < 9; i++)
        {

            if (sudokuArray[i][column] == tnumber)
            {
                return false;
            }
        }
        return true;
    }

    bool rowControl(int row, int tnumber) // Mücahit
    {
        for (int i = 0; i < 9; i++)
        {
            if (tnumber == sudokuArray[row][i])
            {
                return false;
            }
        }
        return true;
    }

    bool squareControl(int row, int column, int tnumber) // Alperen
    {

        int Row = row - row % 3;
        int Col = column - column % 3;

        for (int i = Row; i < Row + 3; i++)
        {
            for (int j = column; j < column + 3; j++)
            {
                if (tnumber == sudokuArray[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }

    void inputs(int row, int column, int number)     //Onur
    {
        if (rowControl(row, number))
        {
            if (columnControl(column, number))
            {
                if (squareControl(row, column, number))
                {
                    sudokuArray[row - 1][column - 1] = number;
                }
            }
        }
    }

    void showSolution()      // Mücahit
    {
        for (int r = 0; r < 9; r++)
        {
            if (r == 3)
            {
                cout << " _ ";
            }

            for (int c = 0; c < 9; c++)
            {
                if (c == 3)
                {
                    cout << " | ";
                }
                cout << sudokuArray[r][c] << " ";
            }
            cout << endl;
        }
    }
};

#endif
