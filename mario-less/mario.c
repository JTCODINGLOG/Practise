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

    for (int l = 0; l < height; l++)
    {
        for (int k =7; k > l ; k--)
        {
            printf (".");
        }

        for (int i=-1; i < l ; i++)
        {
            printf ("#");
        }
        printf ("\n");

    }

    for (int j = 0; j < height; j++)
    {
        for (int i=-1; i < j ; i++)
        {
            printf ("#");
        }
        printf ("\n");
    }

}