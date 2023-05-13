#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //long number = get_long ("Number: ");
    long number;

    number = 4003600000000014 %10;
    printf (" %li \n", number);

    number = 4003600000000014 %100;
    printf (" %li \n", number);

    number = 4003600000000014 %1000000;
    printf (" %li \n", number);

    number = 4003600000000014 %100000000;
    printf (" %li \n", number);

    number12 = 4003600000000014 %10000000000;
    printf (" %li \n", number);

    number = 4003600000000014 %100000000000;
    printf (" %li \n", number);

    number = 4003600000000014 %100000000000000;
    printf (" %li \n", number);


    //American Express 15 digits, starts with 34 or 37
    //MasterCard 16 digits, starts with 51,52,53,54,55
    //Visa 13 or 16, starts with 4

    //Check numbers

    //% 10 to get rest and figure out digit

    //4003600000000014
}