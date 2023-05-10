#include <cs50.h>
#include <stdio.h>

int main (void)
{
    string first_answer = get_string ("What's your name?: ");
    int second_answer = get_int ("What's your age?: ");
    long third_answer = get_long ("What's your phone?: ");
    printf ("%s\n%i\n%i\n", first_answer, second_answer, third_answer);
}