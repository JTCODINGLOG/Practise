#include <cs50.h>
#include <stdio.h>

int main (void)
{
    char first_name = get_string ("What's your name?: ");
    printf (first_name);
}