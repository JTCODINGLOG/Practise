#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int nstart = get_int ("What is the start size?: ");
    int nend = get_int ("What is the end size?: ");

    do
    {
        {
            int y = 0;
            y = y + 1;
            nstart = nstart *((13/12)^y);
            printf ("The number of years is %i\n", y );

        }
    }
    while (nstart < nend);
}