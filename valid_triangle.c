#include <stdio.h>
#include <cs50.h>

char valid_triangle (float a, float b, float c);

int main(void)
{
    float side_a = get_float ("Insert side a: ");
    float side_b = get_float ("Insert side b: ");
    float side_c = get_float ("Insert side c: ");

    char valid_triangle (float a, float b, float c);

}

char valid_triangle (float a, float b, float c)
{
    if (a>0 && b>0 && c>0)
    {
        if (a + b >= c || a + c >= b || b +c >= a)
        {
            char x = printf ("Y");
            return x;
        }
        else
        {
            char y = printf ("N");
            return y;
        }
    }
    else
    {
        char y = printf ("N");
        return y;
    }

}
