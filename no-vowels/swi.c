// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string N);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf ("%s\n", replace(argv[1]));
    }
    else
    {
        printf ("please, insert just one command line argument\n");
        return 1;
    }
}

string replace (string N)
{
    int n = strlen(N);

    for(int i = 0; i < n; i)
    {
         switch (N[i])
         {case 1: (N[i] == 'a')
         {
            N[i] = 6;
         }
         else if (N[i] == 'e')
         {
            N[i] = 3;
         }
         else if (N[i] == 'i')
         {
            N[i] = 1;
         }
         else if (N[i] == 'o')
         {
            N[i] = 0;
         }
         return 0;
    }
    return N;
}