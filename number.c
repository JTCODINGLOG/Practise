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
    int n3;
    n3 = (number %1000 - number %100)/100;
    printf ("%i", n3);

}