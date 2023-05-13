#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //long number = get_long ("Number: ");
    long number1;
    long number2;
    long number12;
    long number13;

    number1 = 4003600000000014 %10;

    number2 = 4003600000000014 %100;
    printf ("Numero 2 es %li \n", (number2-number1)/10;



    number12 = 4003600000000014 %100000000000;

    number13 = 4003600000000014 %1000000000000;
    printf ("Numero 13 es %li \n", (number13-number12)/1000000000000;

    long number;

    number = 4003600000000014 / 10000000000000;
    printf (" %li", number);


    //American Express 15 digits, starts with 34 or 37
    //MasterCard 16 digits, starts with 51,52,53,54,55
    //Visa 13 or 16, starts with 4

    //Check numbers

    //% 10 to get rest and figure out digit

    //4003600000000014
}