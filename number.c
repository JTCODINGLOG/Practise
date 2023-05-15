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
    n2 = number %100/10;
    printf ("%i", n2);

}