#include <stdio.h>
#include <cs50.h>

int main(void)
{

}

float share()
{

    float bill = get_float ("Bill before tax and tip: ");
    float tax = get_float ("Sale Tax Percent: ");
    float tip  = get_float ("Tip percent: ");

    float owned = (bill +( bill * tax / 100 ))
}
