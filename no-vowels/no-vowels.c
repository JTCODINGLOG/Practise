// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string input);

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

string replace (string input)
{
    int n = strlen(input);

    for(int i = 0; i < n; i++)
    {
         if (input[i] == 'a')
         {
            input[i] = 6;
         }
         else if (input[i] == 'e')
         {
            input[i] = 3;
         }
         else if (input[i] == 'i')
         {
            input[i] = 1;
         }
         else if (input[i] == 'o')
         {
            input[i] = 0;
         }
    }
    return input;
}