#include <iostream>
using namespace std;

int numberSudoku = 0;
int arrayToCheckSudoku[10] = {0}; //array for copy parts of sudoku array
int getNumber = 0;
int getColumn = 0;	
int getSquare =0;
	
bool checkRow(int *tab) //checking if we don't have same numbers in a row
{
	int row = 9;
	int firstSudokuNumber = 1;
  	int lastSudokuNumber = 10;
  	
	for(int x = 0; x < row ; x++)
	{
  		for(int x = 0; x < row ; x++)
  		{	
  			numberSudoku =*(tab+x);
  			arrayToCheckSudoku[numberSudoku] = numberSudoku;// arrayToCheckSudoku[1] = 1, arrayToCheckSudoku[2] = 2 etc.
		}
  		for(int x = firstSudokuNumber; x < lastSudokuNumber; x++)
  		{
  	 		if(arrayToCheckSudoku[x] == 0)	//if we get 0 it means we don't have some number from 1 - 9,
  	 		{					
  				return false;
  	 		}
  		}
  		
  		for(int x = firstSudokuNumber; x < lastSudokuNumber; x++)
  		{
  			arrayToCheckSudoku[x] = 0;
  		}
  		
		tab = tab + 9;	 
  	}  	
  	
	  tab = tab - 81; //get pointer at the start of sudoku array	
  	
  	return true;
}

bool checkColumn(int *tab)	
{	
	int column = 9;
	int firstSudokuNumber = 1;
  	int lastSudokuNumber = 10;
		
	for(int x = 0; x < column; x++)
	{
  		for(int x = 0; x < column; x++)
  		{	
  			numberSudoku =*tab;
  			arrayToCheckSudoku[numberSudoku] = numberSudoku;
			getNumber++;	 	

			if(getNumber < 9)
			{
				tab = tab + 9;
			}
  		}
  		
  		getNumber = 0;
  	
  		for(int x = firstSudokuNumber; x < lastSudokuNumber; x++)
  		{
  	 		if(arrayToCheckSudoku[x]==0)
  	 		{	
  				return false;
  	 		}	
  		}
  		
  		for(int x = firstSudokuNumber; x < lastSudokuNumber; x++)
  		{
  			arrayToCheckSudoku[x] = 0;
  		}
  		
  		getColumn++;
  		
  		if(getColumn < column)
		{
			tab = tab - 71; //set pointer at the start of next column
		}
		else
		{
			tab = tab - 80; //set pointer at the start of sudoku array
		}		 
 	}
 	return true;
}

bool checkSquare(int *tab) //check 3X3 square if we have all numbers 1 - 9
{	

	int firstSudokuNumber = 1;
  	int lastSudokuNumber = 10;

	int squareSideSize = 3;
	int squareSize = 9;
	
	for(int x = 0; x < squareSideSize; x++)
	{
		for(int x = 0; x < squareSize; x++)
		{
  			for(int x = 0; x < squareSideSize; x++)
  			{	
  				numberSudoku =*tab;
  				arrayToCheckSudoku[numberSudoku] = numberSudoku;
				getNumber++;
				getSquare++;	 	
			
				if(getNumber < 3)
				{
					tab = tab + 9; // poruszamy sie w dol po kolumnie
				}
				else
				{	
					tab = tab - 17;//idziemy na poczatek nastepnej kolumny	
				}
  			}
  			
  			getNumber = 0;
  			
  			if(getSquare == 9) //uzbieralismy liczby w kwadracie, mozemy sprawdzic czy brakuje jakies liczby (1-9) 
  			{
  				for(int x = firstSudokuNumber; x < lastSudokuNumber; x++)
  				{
  	 				if(arrayToCheckSudoku[x] ==0)
  	 				{	
  						return false;
  	 				}	
  				}
  			
  				for(int x = firstSudokuNumber; x < lastSudokuNumber; x++)
  				{
  					arrayToCheckSudoku[x] = 0;
  				}
				  			
  				getSquare = 0; 
  			}
  		}
  		
  		tab = tab + 18; //17 do przodu z ostatniego cofniecia + jeden w prawo na nastepna kolumne
}

tab = tab - 81;//na poczatek tablicy Sudoku
	
return true;
}

bool checkSudoku(int *tab)
{
	if (checkRow(tab)==false||checkColumn(tab)==false||checkSquare(tab)==false)	
	{
		return false;
	}
	
	return true;
}
 
int main()

{
const int size = 9;
static int sudoku1Correct[size][size] =  
			{ 	
			{ 4,6,7,3,1,5,9,2,8 },
			{ 1,8,2,9,4,6,7,5,3 },
			{ 5,3,9,2,7,8,1,4,6 },
			{ 6,5,3,4,8,7,2,9,1 },
			{ 2,7,8,1,9,3,4,6,5 },
			{ 9,4,1,5,6,2,8,3,7 },
			{ 7,9,6,8,5,4,3,1,2 },
			{ 8,2,4,6,3,1,5,7,9 },
			{ 3,1,5,7,2,9,6,8,4 } 
			};
												
static int sudoku2Correct[9][9] = 
			{
			{ 9,4,6,8,3,2,7,1,5 },
			{ 1,5,2,6,9,7,8,3,4 },
			{ 7,3,8,4,5,1,2,9,6 },
			{ 8,1,9,7,2,6,5,4,3 },
			{ 4,7,5,3,1,9,6,8,2 },
			{ 2,6,3,5,4,8,1,7,9 },
			{ 3,2,7,9,8,5,4,6,1 },
			{ 5,8,4,1,6,3,9,2,7 },
			{ 6,9,1,2,7,4,3,5,8 }
			};										
				 	
int *pSudoku=&sudoku1Correct[0][0];

if (checkSudoku(pSudoku)==true)
{
	cout<<"Test Passed\n";
}
else
{
	cout<<"Test Fail\n";
}
	
pSudoku=&sudoku2Correct[0][0];

if (checkSudoku(pSudoku)==true)
{
	cout<<"Test Passed\n";
}
else
{
	cout<<"Test Fail\n";
}	

	return 0;
}


