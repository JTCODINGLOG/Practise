#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int height;
    do
    {
         height = get_int ("Height: \n");
    }
    while (height<1 || height>8);

    switch (height)
    {
        case 1: printf("#");
        case 2: printf("##");
        case 3: printf("###");
        case 4: printf("####");
        case 5: printf("#####");
        case 6: printf("######");
        case 7: printf("#######");
        case 8: printf("########");
            break;
    }



}