#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters (string text);
int count_words (string text);
int count_sentences (string text);

string main(void)
{
    string text = get_string("Text: ");
    printf ("%i letters and %i words and %i sentences.\n", count_letters(text), count_words(text), count_sentences(text));
}



int c_letters (string text)
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


int count_words (string text)
{
    int word_counter = 0;
    for (int i = 0; i <strlen(text); i++)
    {
        if (isalpha(text[i]) && (isspace(text[i+1]) || ispunct(text[i+1])))
        {
            if (text[i+1] == '-')
            {
                continue;
            }
            word_counter++;
        }
    }
    return word_counter;
}


int count_sentences (string text)
{
    int sentence_counter = 0;
    for (int i = 0; i <strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_counter++;
        }
    }
    return sentence_counter;
}