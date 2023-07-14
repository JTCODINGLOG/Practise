#include <cs50.h>
#include <stdio.h>

int factorial (int number);

int main(void)
{

}

int factorial (int number)
{
    if (number == 1)
    {
        return 1;
    }
    else
    {
        number * factorial(number-1)
    }
}