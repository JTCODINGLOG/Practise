#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int c_letters(string text);
int c_words(string text);
int c_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    printf("%i and %i and %i\n", c_letters(text), c_words(text), c_sentences(text));

    float L = (float) c_letters(text) / c_words(text) * 100;
    float S = (float) c_sentences(text) / c_words(text) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    printf("%f so %f\n", L, S);

    if (index < 1)
    {
        printf("Before grade 1\n");
        return 0;
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }

    printf("Grade %i\n", index);
    return 0;
}

int c_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int c_words(string text)
{
    int words = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) && (isspace(text[i + 1]) || ispunct(text[i + 1])))
        {
            if (text[i + 1] == '-')
            {
                continue;
            }
            words++;
        }
    }
    return words;
}

int c_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
