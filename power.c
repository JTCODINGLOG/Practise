#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int ("Size: ");
    }
    while (n < 1);

    int powers[n];
    for (int i = 0; i < n; i++)
    {
        power[i] = 1
        power[i] = 2 * power[i - 1];

        printf( "%i\n", i );
    }
}