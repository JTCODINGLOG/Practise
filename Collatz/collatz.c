#include <stdio.h>
#include <cs50.h>

int collatz (int n)
{
    int steps = 0;

    if (n == 1)
    {
        return 0;
    }
    else if (n % 2 == 0)
    {
        return 1 + collatz(n/2);
    }
    else
    {
        return 1 + collatz (3*n + 1);
    }

    return 1;
}

int main(void)
{
    int number;
    number = get_int ("Write a number: ");
    printf ("to get to 1 we need %i steps\n", collatz (number));

}

