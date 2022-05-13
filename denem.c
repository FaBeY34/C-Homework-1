#include <stdio.h>

const int ROW = 32;
const int COL = 63;

void initializeMatrix(char matrix[ROW][COL]);
void createTriangle(char matrix[ROW][COL], int startRow, int startCol, int length);
void printTriangles(char matrix[ROW][COL]);
void makeOnes(char matrix[ROW][COL], int startRow, int startCol, int length, int iteration);

// base case is iteration 0 and at each iteration length divides.This function creates three triangle for each triangle using the length at that time(original left and right triangles)
int main(void)
{
    // taking input from user
    unsigned int number;
    printf("Please enter a number of iteration: ");
    scanf("%u", &number);
    while (number >= 5)
    {
        printf("Number must be less than 5, enter again: ");
        scanf("%u", &number);
    }

    char matrix[ROW][COL];
    // initializing matrix with full of '_'.
    initializeMatrix(matrix);

    // the function that will create ones as triangle
    makeOnes(matrix, 0, COL / 2, ROW, number);

    // printing triangle matrix
    printTriangles(matrix);
    return 0;
}
// initializing our matrix with full of underscore.
void initializeMatrix(char matrix[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            matrix[i][j] = '_';
        }
    }
}

void makeOnes(char matrix[ROW][COL], int startRow, int startCol, int length, int iteration)
{
    if (iteration == 0)
    {
        createTriangle(matrix, startRow, startCol, length);
    }
    else
    {
        makeOnes(matrix, startRow, startCol, length / 2, iteration - 1);
        makeOnes(matrix, startRow + length / 2, startCol - length / 2, length / 2, iteration - 1);
        makeOnes(matrix, startRow + length / 2, startCol + length / 2, length / 2, iteration - 1);
    }
}

void printTriangles(char matrix[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

// this function arrange the matrix  according to row col and length of each triangle one by one.
void createTriangle(char matrix[ROW][COL], int startRow, int startCol, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = startCol - i; j <= startCol + i; j++)
        {
            matrix[startRow + i][j] = '1';
        }
    }
}
