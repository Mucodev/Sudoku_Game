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
 {0, 0, 5, 2, 0, 6, 3, 0, 0}
}; 
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
		cout << setw(50) << "Welcome to Sudoku Game" << endl << setw(40)
			<< "Rules" << endl << endl << setw(20) << "1. Use Numbers 1-9" << endl
			<< setw(59) << "2. Don't Repeat Any Numbers(each row, column and square) " << endl;
		cout << "Press any key to continue...";
		(void)_getch();
	}
	void displayGame(); //Alperen
	bool columnControl(); //Onur
	bool rowControl(int row,int tnumber) // Mücahit
	{
		for (int i = 0; i < 9; i++)
		{
			if (sudokuArray[9*row + i] == tnumber)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	bool squareControl(); //Alperen
	void inputs(int number); //Onur
	void showSolution() // Mücahit
	{
		for (int r = 0; r < 9; r++)
		{
			for (int c = 0; c < 9; c++)
			{
				cout << sudokuArray[r * 9 + c] << " ";
			}
			cout << endl;
		}
	}
};



#endif#
