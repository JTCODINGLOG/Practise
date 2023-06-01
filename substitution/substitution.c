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
    else if (strlen(argv[1]) != 26 && argc == 2)
    {
        printf ("Key must contain 26 characters\n");
    }
    else
    {
        printf ("Usage: ./substitution key\n");
    }

}

//check is alphabetical
bool alpha (word)
{
    for ( int i = 0, n = strlen (word); i < n; i++)
    {
        if (isalpha(word[i]))
        else
        {
            return printf ("This is not an alphabetical key")
        }

    }
}