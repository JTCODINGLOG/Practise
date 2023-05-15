#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int d_1 = 0, d_2 = 0, d_3 = 0, d_4 = 0, d_5 = 0, d_6 = 0, d_7 = 0, d_8 = 0, d_9 = 0, d_10 = 0, d_11 = 0, d_12 = 0, d_13 = 0, d_14 = 0, d_15 = 0, d_16 = 0;

    long number;
    do
    {
        number = get_long ("Number: ");
    }
    while (3999999999999 > number);

    //int d_1, d_2, d_3, d_4, d_5, d_6, d_7, d_8, d_9, d_10, d_11, d_12, d_13, d_14, d_15, d_16;

    int d = 1;
    for (long i = 1; i < number ; i = i * 10, d++ )
    {
        int n = number % ( i * 10 ) / i;
        int d_x = n;
        printf ("%i\n", d_x);
    }

    printf ("/n/n/n%i", d_1);

}