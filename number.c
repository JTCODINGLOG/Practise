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


    //int n1;
    //n1 = number %10;
    //int n2;
    //n2 = number %100/10;
    //int n3;
    //n3 = number %1000/100;


    for (long i = 1; i < number ; i=i*10 )
    {
        int n = number %(i*10) / i;
        int ("n1")
        printf ("number is %i \n", n);
    }
}