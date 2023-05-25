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
        if (islower (int low[i]))
        printf ("%s", low[i]);
        else
        printf ("upper");
    }

}