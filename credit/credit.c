#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number;
    do
    {
        number = get_long ("Number: ");
    }
    while (3999999999999 > number > 10000000000000000);

    //number extraction
    int n1;


    int n2;
    n2 = (number %100 - number %10)/10;
    printf ("Numero 2 es %li \n", n2);


    //long number = get_long ("Number: ");
    long number1;
    long number2;
    long number12;
    long number13;
    long number2d;
    long number13d;


    number1 = 4003600000000014 %10;
    number2 = 4003600000000014 %100;
    number2d = (number2-number1)/10;
    printf ("Numero 2 es %li \n", number2d);



    number12 = 4003600000000014 %1000000000000;
    number13 = 4003600000000014 %10000000000000;
    number13d = (number13-number12)/1000000000000;
    printf ("Numero 13 es %li \n", number13d);




    //American Express 15 digits, starts with 34 or 37
    //MasterCard 16 digits, starts with 51,52,53,54,55
    //Visa 13 or 16, starts with 4

    //Check numbers

    //% 10 to get rest and figure out digit

    //4003600000000014
}