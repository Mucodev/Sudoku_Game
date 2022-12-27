#ifndef Sudoku
#define Sudoku

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
    int sudokuArray[9][9] =
            {
                    {1,2,3,  4,5,6,  7,8,9},
                    {4,5,6,  7,8,9,  1,2,3},
                    {7,8,9,  1,2,3,  4,5,6},
                    {2,3,1,  5,6,4,  8,9,7},
                    {5,6,4,  8,9,7,  2,3,1},
                    {8,9,7,  2,3,1,  5,6,4},
                    {3,1,2,  6,4,5,  9,7,8},
                    {6,4,5,  9,7,8,  3,1,2},
                    {9,7,8,  3,1,2,  6,4,5}
            };

    int sudokuSol[9][9];
public:
    SudokuGame()
    {
        cout << setw(50) << "Welcome to Sudoku Game" << endl
             << setw(40)
             << "Rules" << endl
             << endl
             << setw(20) << "1. Use Numbers 1-9" << endl
             << setw(59) << "2. Don't Repeat Any Numbers(each row, column and square) " << endl;
        cout << "Press enter to continue...";
        (void)_getch();
        cout << endl;
    }

    void sudokuGenerator(int difficulty)
    {
        srand(time(NULL));
        int count = 0;

        for (int a = 0; a < 9; a++)
        {
            int randn = rand() % 9 + 1;

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (sudokuArray[i][j] == a + 1)
                    {
                        sudokuArray[i][j] = randn;
                    }
                    else if (sudokuArray[i][j] == randn)
                    {
                        sudokuArray[i][j] = a + 1;
                    }
                }
            }
        }

        for (int row = 0; row < 9; row++)
        {
            for (int column = 0; column < 9; column++)
            {
                sudokuSol[row][column] = sudokuArray[row][column];
            }
        }

        int flag;

        if (difficulty == 1) //Easy
        {
            flag = 36;
        }
        else if (difficulty == 2)//Medium
        {
            flag = 30;
        }
        else if (difficulty == 3)
        {
            flag = 25;
        }

        while (count != 81 - flag)
        {
            int row = rand() % 9;
            int col = rand() % 9;

            if (sudokuArray[row][col] != 0)
            {
                sudokuArray[row][col] = 0;
                count++;
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

    bool columnControl(int column, int tnumber)   //Onur
    {
        for (int i = 0; i < 9; i++)
        {

            if (sudokuArray[i][column - 1] == tnumber)
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
            if (tnumber == sudokuArray[row - 1][i])
            {
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

    bool inputs(int row, int column, int number)     //Onur
    {
        if (rowControl(row, number))
        {
            if (columnControl(column, number))
            {
                if (squareControl(row, column, number))
                {
                    sudokuArray[row - 1][column - 1] = number;
                    return true;
                }
            }
        }

        return false;
    }

    void showSolution()      // Mücahit
    {
        cout << "#   1 2 3   4 5 6   7 8 9" << endl
             << "+ | - - - + - - - + - - -" << endl;

        for (int row = 0; row < 9; row++)
        {
            cout << (row + 1) << " | ";

            for (int column = 0; column < 9; column++)
            {

                cout << sudokuSol[row][column] << " ";

                if (column == 2 || column == 5)
                {
                    cout << "| ";
                }

                else if (column == 8)
                {
                    cout << endl;
                }
            }

            if (row == 2 || row == 5)
            {
                cout << "  | - - - + - - - + - - -" << endl;
            }
        }
    }
};

#endif
