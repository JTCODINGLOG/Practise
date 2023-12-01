#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
         height = get_int ("Height: \n");
    }
    while (height<1 || height>8);

    for (int j = 0; j < height; j++)
    {
        for (int k = height - 1; k > j ; k--)
        {
            printf (" ");
        }

        for (int i=-1; i < j ; i++)
        {
            printf ("#");
        }

        printf ("  ");

         for (int l=-1; l < j ; l++)
        {
            printf ("#");
        }

        printf ("\n");
    }
}