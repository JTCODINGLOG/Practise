#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Get and validate de key
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf ("Usage: ./substitution key\n");
    }
    else if (strlen(argv[1]) != 26)
    {
        printf ("Key must contain 26 characters\n");
    }
    else if (alpha (argv[1]))
    else if


    else
    {
        string plaintext = get_string ("plaintext: ");
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