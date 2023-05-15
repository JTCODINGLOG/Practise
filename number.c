#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number;
    do
    {
        number = get_long ("Number: ");
    }
    while (3999999999999 > number);

    int d_1, d_2
    int d = 1;
    for (long i = 1; i < number ; i = i * 10, d++ )
    {
        int n = number % ( i * 10 ) / i;
        d_x = n;
        printf ("%i\n", d_x);
    }

    printf ("%i", d_1);

}