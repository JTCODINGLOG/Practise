#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int conv = 0;
int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO


    int index = strlen(input) - 1;


    if (index < 0)
    {
        return conv;
    }
    for (int i = index; i >= 0; i--)
    {
        int conv = input[i] - 48;
        input[i] = '\0';
    }




}