#include <cs50.h>
#include <stdio.h>

int main (void)
{
    string name = get_string ("What's your name?: ");
    int age = get_int ("What's your age?: ");
    string phonenumber = get_string ("What's your phone?: ");
    printf ("Name is %s\nName is %i\nPhone number is %s\n", name, age, phonenumber);
}