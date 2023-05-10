#include <cs50.h>
#include <stdio.h>

int main (void)
{
    string first_answer = get_string ("What's your name?: ");
    int second_answer = get_int ("What's your age?: ");
    string third_answer = get_string ("What's your phone?: ");
    printf ("Age is %s\nName is %i\nPhone number is %s\n", first_answer, second_answer, third_answer);
}