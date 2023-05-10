#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float bill = get_float ("Bill before tax and tip: ");
    float tax = get_float ("Sale Tax Percent: ");
    float tip  = get_float ("Tip percent: ");
}

float share()
{
    float owned = get_float (bill + tax + tip);
    return (printf ("You will owe each"));
}
