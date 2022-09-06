#include <stdio.h> // Standard Library for input and output
#include <stdlib.h> //  Another Library for general functions
#include <stdbool.h> //Includes boolean capabilities for comparisons


// Main function to call the function with the solution that was declared below, the number of spaces for the board can be changed by simply adjusting the board size
// if there is no solution it will simply return false
int main()
{
    solfourqueens();
    return 0;
}

void printboard(int board[4][4])
{
    for (int i = 0; i < 4; i++)// Prints first part of the board
    {
        for (int j = 0; j < 4; j++) // Prints second part of the board
            printf("{ %d }", board[i][j]);// Prints values on the board with the braces to contain the values
        printf("\n");
    }
    printf("\n");
}

// This functions checks for queens within the board it checks the following areas:
// left sides and upper and lower diagonals accordingly
bool isEmpty(int board[4][4], int row, int column)
{
    int i, j;

    for (i = 0; i < column; i++)
        if (board[row][i])
            return false;
    for (i=row, j=column; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;

    for (i=row, j=column; j>=0 && i<4; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function that checks if the queens are present on the board
// if they can be placed or not, if one cannot be places then it is considered to be useless and will be removed
bool recursiveQueen(int board[4][4], int column)
{
    if (column >= 4)
    {
        return true;
    }

    for (int i = 0; i < 4; i++) // Handles the placement of the 1's if a queen can be placed in the position or a 0 if it cannot be placed
    {
        if ( isEmpty(board, i, column) )
        {
            board[i][column] = 1;
            if(recursiveQueen(board, column + 1))//
            return true;
            board[i][column] = 0;
        }
    }
    return false;
}

void solfourqueens()
{
    int board[4][4]; // Declared a second time for the local function
    memset(board, 0, sizeof(board)); // Keeping track of the literal size of the board within the memory

    if (recursiveQueen(board, 0) == false)
    {
        printf("A Solution does not exist");// Lets the user know if a placement does not have a solution
        return false;
    }

   printboard(board);
    return true;
}

