#include <stdio.h>
#include <cs50.h>

int collatz (int n)
{
    int steps = 0;

    if (n == 1)
    {
        steps += 1;
        printf ("%i", steps);
        return 0;
    }
    else if (n % 2 == 0)
    {
        steps += 2;
        collatz(n/2);
    }
    else
    {
        steps += 3;
        collatz (3*n + 1);
    }

    return 1;
}

int main(void)
{
    int number;
    number = get_int ("Write a number: ");
    int collatz (int number);
}