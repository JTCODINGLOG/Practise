#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (strlen(argv[1]) == 26 && argc == 2)
    {
        string plaintext = get_string ("plaintext: ");
    }
    if else (strlen(argv[1]) != 26 && argc == 2)
    {
        printf ("Key must contain 26 characters\n");
    }
    else (argc == 1 || argc > 2)
    {
        printf ("Usage: ./substitution key\n")
    }

}

//check is alphabetical
bool alpha (word)
{
    do

    for ( int i = 0, n = strlen (word); i < n; i++)
    {
        if (isalpha(word[i]))

        else
        {
            return False
        }

    }
}