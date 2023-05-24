#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int ("Size: ");

    int powers[n];
    for (int i = 1, j = 0; j < n; i = i*2, j++)
    {
        printf( "%i\n", i );
    }
}