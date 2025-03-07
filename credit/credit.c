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

    //checking lenght
    if (i < 13 || i > 16 || i==14)
    {
        printf("INVALID \n");
        return 0;
    }

    //checksum
    long n = number;
    int n1;
    int n2;
    int sum1 = 0;
    int sum2 = 0;
    int d1 = 0;
    int d2 = 0;
    do
    {
    //sum1
    n1 = n % 10;
    n = n / 10;
    sum1 = sum1 + n1;

    //sum2
    n2 = n % 10;
    n = n/10;
    n2 = n2 * 2;
    d1 = n2 % 10;
    d2 = n2 / 10;
    sum2 = sum2 + d1 +d2;
    }
    while ( n > 0);

    int total = sum1 + sum2;

    //total last digit
    if (total % 10 != 0)
    {
        printf ("INVALID \n");
        return 0;
    }

    //find first 2 digits
    long start = number;
    do
    {
        start = start / 10;
    }
    while (start > 100);

    //deciding the type of card
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6 ) && (i == 16))
    {
        printf ("MASTERCARD \n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7) && (i == 15) )
    {
        printf ("AMEX \n");
    }
    else if ((start / 10 == 4) && ( i == 13 || i == 16))
    {
        printf ("VISA \n");
    }
    else
        printf ("INVALID \n");
}