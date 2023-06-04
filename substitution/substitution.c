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
    else if (repeat (argv[1]) == true)
    {
        printf ("Key contains repeated characters\n");
    }
    else
    {
        string plaintext = get_string ("plaintext: ");
    }



}

//check that it is alphabetical
bool alpha (string word)
{
    int sum = 0;
    int n = strlen (word);
    for ( int i = 0; i < n; i++)
    {
        if (isalpha(word[i]))
        {
            sum++;
        }
    }

    if (sum == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//check that any char is repeated
bool repeat (string word)
{
    int sum = 0;
    int n = strlen (word);
    for ( int i = 0; i < n; i++)
    {
        for ( int j = i + 1; j < n; j++)
        {
            if (toupper (word[i]) == toupper(word[j]))
            {
                return true;
            }
        }
    }
    return false;
}