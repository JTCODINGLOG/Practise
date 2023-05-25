#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string low = get_string ("insert string: ");

    int n = strlen (low);

    for(int i = 0; i < n - 1; i++)
    {
        if (islower ( low[i] ))
        {
            if (low[i] < low[i+1])
            {
                printf ("Yes, lowercase and follows alphabetical order\n");
            }
            else
            {
                printf ("No, it does not follow alphabetical order\n");
            }
        }
        else
        {
            printf ("No, there are blocks\n");
        }
        return 0;
    }

}