#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters (string text);

int main(void)
{
    string text = get_string("Text: ");
    printf ("%i\n", count_letters(text));
}

int count_letters (string text)
{
    int letter_counter = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letter_counter++;
        }
    }
    return letter_counter;
}