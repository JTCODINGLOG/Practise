#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i, int n = strlen(s); i < n; i++)
    {
            printf("%c", toupper(s[i]));
    }
    printf("\n");
}