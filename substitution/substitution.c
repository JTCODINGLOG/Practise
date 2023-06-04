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
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf ("Key must contain 26 characters\n");
        return 1;
    }

    if (alpha (argv[1]) == false)
    {
        printf ("key must contain just alphabetical characters\n");
        return 1;
    }

    if (repeat (argv[1]) == true)
    {
        printf ("Key contains repeated characters\n");
        return 1;
    }

    string plaintext = get_string ("plaintext: ");
//ENCRYPTATION - NEW
    for (int i = 0, n = strlen (plaintext); i < n; i++ )
    {
        if (isupper(plaintext[i]))
        {
            int pos = plaintext[i]-65;
            plaintext[i] = argv[1][pos];
        }

        else if (islower(plaintext[i]))
        {
            int pos = plaintext[i]-97;
            plaintext[i] = (argv[1][pos]);
        }
    }

    printf ("%s\n", plaintext);
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

//get text and encrypt it - OLD



    //char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    //for (int i = 0, n = strlen (plaintext); i < n; i++ )
    //{
      //  int j = 0;
        //do
        //{
          //  j++;
        //}
        //while (plaintext[i] != alphabet[j]);

        //plaintext[i] = argv[1][j];
    //}

    //printf ("%s\n", plaintext);

//}