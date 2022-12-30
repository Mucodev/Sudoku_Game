#ifndef Sudoku
#define Sudoku

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

class SudokuGame
{
private:
    int sudokuArray[9][9] =    //Simple sudoku puzzle. We use this pattern because if we don't our puzzle that is generated randomly doesn't have any solution
            {
                    {1, 2, 3, 4, 5, 6, 7, 8, 9},
                    {4, 5, 6, 7, 8, 9, 1, 2, 3},
                    {7, 8, 9, 1, 2, 3, 4, 5, 6},
                    {2, 3, 1, 5, 6, 4, 8, 9, 7},
                    {5, 6, 4, 8, 9, 7, 2, 3, 1},
                    {8, 9, 7, 2, 3, 1, 5, 6, 4},
                    {3, 1, 2, 6, 4, 5, 9, 7, 8},
                    {6, 4, 5, 9, 7, 8, 3, 1, 2},
                    {9, 7, 8, 3, 1, 2, 6, 4, 5}
            };

    int sudokuSol[9][9],  //Arrays for Sudoku Solution and deleting function
            sudokuDel[9][9];

    bool columnControl(int column, int tnumber)  // Column control
    {
        for (int i = 0; i < 9; i++)
        {

            if (sudokuArray[i][column - 1] == tnumber)  // if the number is in the column returns false
            {
                return false;
            }
        }
        return true;
    }

    bool rowControl(int row, int tnumber) // Row Control
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

    bool squareControl(int row, int column, int tnumber)  //Square Control, controlling 3x3 sudoku boxes
    {
        int r, c;

        if (row <= 3)  
        {
            r = 3;
        }

        else if (row <= 6)
        {
            r = 6;
        }

        else if (row <= 9)
        {
            r = 9;
        }

        if (column <= 3)
        {
            c = 3;
        }

        else if (column <= 6)
        {
            c = 6;
        }

        else if (column <= 9)
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

protected:
    int score; // Player Score

public:

    SudokuGame() // Default constructor, shows puzzle rules
    {
        cout << setw(50) << "Welcome to Sudoku Game" << endl
             << setw(40)
             << "Rules" << endl
             << endl
             << setw(74) << "1. Input Numbers 1-9 in 'row - column - number' order" << endl
             << setw(78) << "2. Don't Repeat Any Numbers(each row, column and square) " << endl
             << setw(56) << "3. Input 0 only if you want to exit" << endl << endl;
        cout << "Press any key to continue...";
        (void) _getch();
        cout << endl;
    }

    SudokuGame(int difficulty) // overloaded Constructor, generates sudoku puzzle solution
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

        sudokuCopy(sudokuSol, sudokuArray); // copying solution 

        int flag;

        if (difficulty == 1)
        {
            flag = 36;
        }
        else if (difficulty == 2)
        {
            flag = 30;
        }
        else if (difficulty == 3)
        {
            flag = 25;
        }

        while (count != 81 - flag) // placing '0' randomly to create puzzle
        {
            int row = rand() % 9;
            int col = rand() % 9;

            if (sudokuArray[row][col] != 0)
            {
                sudokuArray[row][col] = 0;
                count++;
            }
        }

        sudokuCopy(sudokuDel, sudokuArray); //copying puzzle for delete function
    }

    void nDelete(int row, int column) // If the entered number is zero, substitute "0" for the number that the player wishes to delete. 
    {
        if (sudokuDel[row - 1][column - 1] != sudokuArray[row - 1][column - 1] && sudokuArray[row - 1][column - 1] != 0)
        {
            sudokuArray[row - 1][column - 1] = 0;
        }
    }

    bool inputs(int row, int column, int number) // if the entered number is true, function returns true and places the number right place
    {
        if (number == 0)
        {
            nDelete(row, column);
            return true;
        }

        else if (rowControl(row, number))
        {
            if (columnControl(column, number))
            {
                if (squareControl(row, column, number))
                {
                    if (sudokuArray[row - 1][column - 1] == 0)
                    {
                        sudokuArray[row - 1][column - 1] = number;
                        return true;
                    }
                }
            }
        }

        return false;
    }

    void showSolution() //shows solution
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

    void sudokuCopy(int first[9][9], int second[9][9]) // Array copy function
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                first[i][j] = second[i][j];
            }
        }
    }

    friend ostream &operator<<(ostream &output, SudokuGame &obj) // '<<' operator overload. Displays the puzzle
    {
        output << endl
               << "#   1 2 3   4 5 6   7 8 9" << endl
               << "+ | - - - + - - - + - - -" << endl;

        for (int i = 0; i < 9; i++)
        {
            output << (i + 1) << " | ";

            for (int j = 0; j < 9; j++)
            {

                if (obj.sudokuArray[i][j] == 0)
                {
                    output << ". ";
                }

                else if (obj.sudokuArray[i][j] != 0)
                {
                    output << obj.sudokuArray[i][j] << " ";
                }

                if (j == 2 || j == 5)
                {
                    output << "| ";
                }

                else if (j == 8)
                {
                    output << endl;
                }
            }

            if (i == 2 || i == 5)
            {
                output << "  | - - - + - - - + - - -" << endl;
            }
        }

        return output;
    }
};

class Player : public SudokuGame // Player class inherited from Sudoku Game class 
{
public:
    Player(){}

    fstream file;
    string fname = "scoreboard";

    int ScoreCalculator(int time, int difficulty) //Score calculator
    {
        if (difficulty == 1)
        {
            score = (6000 - time) * 1;
        }

        else if (difficulty == 2)
        {
            score = (6000 - time) * 3;
        }

        else if (difficulty == 3)
        {
            score = (6000 - time) * 5;
        }

        else if (difficulty == 0)
        {
            score = 0;
        }

        return score;
    }

    void setScore(int score, int difficulty, string name) //Writing the scores to the file
    {
        file.open(fname, ios::app);
        if (difficulty == 1)
        {
            file << left << setw(15) << name << left << setw(10) << score << left << setw(10) << "(Easy)" << endl;
        }

        else if (difficulty == 2)
        {
            file << left << setw(15) << name << left << setw(10) << score << left << setw(10) << "(Medium)" << endl;
        }

        else if (difficulty == 3)
        {
            file << left << setw(15) << name << left << setw(10) << score << left << setw(10) << "(Hard)" << endl;
        }
        file.close();
    }

    void showScore(void) //Displays the scores end of the game
    {
        file.open(fname, ios::in);
        cout << "---------------------------------------" << endl;
        cout << setw(25) << "Score Board" << endl;
        cout << "---------------------------------------" << endl;

        string line;
        while (!file.eof())
        {
            getline(file, line);
            cout << line << endl;
        }

        file.close();
    }
};

#endif
