#include <stdio.h>

int getSuperDigit(unsigned __int64, unsigned int);
int getMaxDigitValue(unsigned __int64);
int counter = 0;
int main(int argc, char const *argv[])
{
    unsigned int number, k, sumOfDigits;
    printf("Please enter a number (n=) : ");
    scanf(" %d", &number);
    printf("Please enter repetition factor (k=) : ");
    scanf("%d", &k);
    printf("Super digit of number ");
    for (int i = 0; i < k; i++)
    {
        printf("%d", number);
    }

    sumOfDigits = getSuperDigit(number,k);
    printf(" is %d", sumOfDigits);

    return 0;
}

int getMaxDigitValue(unsigned __int64 number)
{
    int maxDigitValue = 0;
    for (int i = 0; number >= 1; i++)
    {
        number /= 10;
        maxDigitValue++;
    }
    return maxDigitValue;
}

int getSuperDigit(unsigned __int64 number, unsigned int k)
{
    if (number / 10.0 < 1)
    {
        return number;
    }

    int superDigit = 0,
        digit = 0,
        maxDigitValue = getMaxDigitValue(number);

    for (int i = 0; i < maxDigitValue; i++)
    {
        digit = number % 10;
        superDigit += digit;
        number /= 10;
    }
    if (counter == 0)
    {
        superDigit *= k;
        counter++;
    }

    return getSuperDigit(superDigit, k);
}