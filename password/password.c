// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool check
    int lenght = strlen (password);
    for (int i = 0; i < lenght; i++)
    {
        if (isupper ( password[i]))
        {
            return
        }
        else if (islower ( password[i]))
        {
            return l
        }
        else if (isdigit ( password[i]))
        {
            return d
        }
        else if (ispunct ( password[i]))
        {
            return p
        }

    }

    return false;
}
