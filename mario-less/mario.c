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
        for (int i=0; i > j ; )
        {
            printf ("#");
        }
        printf ("\n");
    }

}