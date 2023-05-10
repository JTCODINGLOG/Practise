#include <stdio.h>
#include <cs50.h>


float share()
{

    float bill = get_float ("Bill before tax and tip: ");
    float tax = get_float ("Sale Tax Percent: ");
    float tip  = get_float ("Tip percent: ");

    float owned = get_float (bill + tax + tip);
    return (printf ("You will owe %f each", owned));
}
