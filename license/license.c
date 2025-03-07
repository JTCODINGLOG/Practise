#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];


    // Create array to store plate numbers
    char plates[8][7];

    //create infile
    char *infile = argv[1];

    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf ("Could not open %s file", infile);
        return 2;
    }

    int idx = 0;

    while (fread(buffer, 1, 7, inptr) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        // Save plate number in array
        for (int i = 0; i < 7; i++)
        {
            plates[idx][i] = buffer[i];
        }

        idx++;
    }



    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }

    fclose(inptr);
    return 0;
}
