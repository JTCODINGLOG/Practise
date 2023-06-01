#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Get and validate de key
int main(int argc, string argv[])
{
    if (argc ==1)
    {
        printf ("Usage: ./substitution key\n");
    }
    else if (strlen(argv[1]) == 26 && argc == 2)
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
bool alpha (string word)
{
    for ( int i = 0, n = strlen (word); i < n; i++)
    {
        if (isalpha(word[i]))
        {
            word[i] = true;
        }
        else
        {
            false;
        }
    }
    return word;
}

//check that any char is repeated
string repeat (string word)
{
    for ( int i = 0, n = strlen (word); i < n; i++)
    {
    
    }
    return ;
}