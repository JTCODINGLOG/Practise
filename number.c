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

    int n2;
    n2 = (number %100 - number %10)/10;
    printf ("Numero 2 es %i \n", n2);
}