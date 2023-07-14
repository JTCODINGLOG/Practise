#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    int vote;
}
candidate;

int main(void)
{
    candidate president = get_candidate("Enter a candidate: ")
}

candidate get_candidate (string prompt)
{
    print("%s\n", prompt);

    candidate c;
    c.name = get_string("Enter a name: ");
    c.vote = get_int("Enter a number of votes: ");
}