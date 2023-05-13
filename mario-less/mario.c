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

    switch (height+)
    {
        case 8: printf("#\n");
        case 7: printf("##\n");
        case 6: printf("###\n");
        case 5: printf("####\n");
        case 4: printf("#####\n");
        case 3: printf("######\n");
        case 2: printf("#######\n");
        case 1: printf("########\n");
            break;
    }



}