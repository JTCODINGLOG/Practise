#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool alpha (string word);
bool repeat (string word);

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
    else if (alpha (argv[1]) == false)
    {
        printf ("key must contain just alphabetical characters\n");
    }
    else if (repeat (argv[1]))
    {
        printf ("Key contains repeated characters\n");
    }
    else
    {
        string plaintext = get_string ("plaintext: ");
    }

}

//check is alphabetical
bool alpha (string word)
{
    int sum = 0;
    int n = strlen (word);
    for ( int i = 0; i < n; i++)
    {
        if (isalpha(word[i]))
        {
            word[i] = 1;
            sum += word[i];

        }
        else
        {
            word[i] = 0;
        }
    }

    if (sum == n)
    {
        return true;
    }
    else if (sum != n)
    {
        return false;
    }
}






//check that any char is repeated
bool repeat (string word)
{
    for ( int i = 0, n = strlen (word); i < n; i++)
    {
        for ( int j = i + 1, i < n)
    }
    return ;
}