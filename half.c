#include <stdio.h>
#include <cs50.h>

float bill = get_float ("Bill before tax and tip: ");
float tax = get_float ("Sale Tax Percent: ");
float tip  = get_float ("Tip percent: ");

int main(void)
{

}

float share(bill, tax, tip)
{
    bill = bill * (1+ (tax / 100) );
    bill = bill * (1+ (tip /100) );
    bill = bill / 2;

    return bill;
}
