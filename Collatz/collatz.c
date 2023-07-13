#include <stdio.h>
#include <cs50>

int collatz (int n)
{
    int steps = 0;

    if (n == 1)
        {
            steps =+ 1;
            return 0;
        }
    else if (n % 2 == 0)
        {
            steps =+ 2;
            collatz(n/2);
        }


    else
    collatz (3*n + 1);
}

int main(void)
{

}