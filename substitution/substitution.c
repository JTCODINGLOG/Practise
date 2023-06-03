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
    bool x;
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
        x = true;
    }
    else
    {
        x = false;
    }
    return x;
}






//check that any char is repeated
bool repeat (string word)
{
    int sum = 0;
    int n = strlen (word);
    printf ("%s\n", word);
    for ( int i = 0; i < n; i++)
    {
        for ( int j = i + 1; j < n; j++)
        {
            if (word[i] == word[j])
            {
                printf ("%i %i gdfgdf %c dfgdg %c", i, j, word[i], word[j]);
                return true;
            }
        }
    }
    return false;
}