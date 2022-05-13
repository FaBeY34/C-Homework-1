#include <stdio.h>
int getExponent(int);
void drawTriangle(int);

int main(int argc, char const *argv[])
{
    unsigned int number;
    printf("Please enter a number: ");
    scanf("%u", &number);
    while (number >= 5)
    {
        printf("Number must be less than 5, enter again: ");
        scanf("%u", &number);
    }
    drawTriangle(number);
    return 0;
}
int getExponent(int exp)
{
    if (exp == 0)
    {
        return 1;
    }
    return 2 * getExponent(exp - 1);
}
void drawTriangle(int number)
{
    int i, j, row = getExponent(5 - number);

    for (int i = 1; i <= row; i++)
    {
        for (j = 1; j <= (row - i); j++)
        {
            printf("_");
        }

        for (j = 1; j <= (2 * i - 1); j++)
        {
            printf("1");
        }

        for (j = 1; j <= (row - i); j++)
        {
            printf("_");
        }

        printf("\n");

    }
    drawTriangle(number);
}