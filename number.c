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
}