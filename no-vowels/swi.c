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

    for(int i = 0; i < n; i++)
    {
         switch (N[i])
         {
            case 'a':
            N[i] = '6';
            break;

            case 'e':
            N[i] = '3';
            break;

            case 'i':
            N[i] = '1';
            break;

            case'o':
            N[i] = '0';
            break;
        }
    return N;
}