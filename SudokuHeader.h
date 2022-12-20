#ifndef Sudoku
#define Sudoku

#include <iostream>
#include <vector>
#include <iomanip>
#include <conio.h>

using namespace std;

class SudokuGame
{
private:
    int sudokuArray[9][9] =
        {
            {0, 0, 6, 5, 0, 8, 4, 0, 0},
            {5, 2, 0, 0, 0, 1, 0, 0, 0},
            {0, 7, 8, 0, 0, 0, 0, 0, 1},
            {0, 0, 4, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 2, 3, 0, 0, 5},
            {0, 5, 0, 0, 9, 0, 6, 0, 0},
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0}};
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
        (void)_getch();
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

    bool columnControl(int column, int tnumber)   //Onur
    {
        for (int i = 0; i < 9; i++)
        {
            if (tnumber == sudokuArray[i][column])
            {
                cout << "False" << endl;
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
                cout << "False" << endl;
                return false;
            }
        }
        return true;
    }

    bool squareControl(int row, int column, int tnumber) // Alperen
    {
        int r, c;

        if (row < 3)
        {
            r = 3;
        }

        else if (row < 6)
        {
            r = 6;
        }

        else if (row < 9)
        {
            r = 9;
        }

        if (column < 3)
        {
            c = 3;
        }

        else if (column < 6)
        {
            c = 6;
        }

        else if (column < 9)
        {
            c = 9;
        }

        for (int i = (r - 3); i < r; i++)
        {
            for (int j = (c - 3); j < c; j++)
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
	if(rowControl(row, number) && columnControl(column, number) && squareControl(row, column, number))
	{
			sudokuArray[row][column] = number;
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
