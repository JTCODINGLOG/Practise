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
    for (int i = 1, j = 0; j < n; i = i*2, j++)
    {
        printf( "%i\n", i );
    }
}