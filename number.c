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



    for (long i = 1, int d = 1; i < number ; i = i * 10, d++ )
    {
        int n = number % ( i * 10 ) / i;
        int d_x = n
    }


    ;

}