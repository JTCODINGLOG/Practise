#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get size of grid
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);

    //Prints grid of bricks
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf ("#");
        }
        printf ("\n");
    }
}
