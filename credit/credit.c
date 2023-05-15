#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get number
    long number = get_long ("Number: ");

    //counting
    int i = 0;
    long c = number;
    while (c > 0)
    {
        c = c/10;
        i++;
    }



    //number extraction
    //int n1;
    //n1 = number %10;
    //int n2;
    //n2 = number %100/10;


    //American Express 15 digits, starts with 34 or 37
    //MasterCard 16 digits, starts with 51,52,53,54,55
    //Visa 13 or 16, starts with 4

    //Check numbers

    //% 10 to get rest and figure out digit

    //4003600000000014
}