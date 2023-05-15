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
    int total = 0;
    do
    {
    //sum1
    n1 = n % 10;
    sum1 = sum1 + n1;
    n = n / 10;

    //sum2
    n2 = n % 10;
    d1 = n2 % 10;
    d2 = n2 / 10;
    sum2 = sum2 + d1 +d2;
    }
    while ( n > 0);

    total = sum1 + sum2;

    //total last digit
    if (total % 10 != 0)
    {
        printf ("INVALID \n");
        return 0;
    }
}