#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdlib.h>

const int BLOCK_SIZE = 512;
// a JPEG file can have more than one block

int main(int argc, char *argv[])
{
    //empty spaces are 0s

    typedef uint8_t BYTE;

    if (argc != 2)
    {
        printf("Please enter only 1 argument\n");
        return 1;
    }

    FILE*infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Usage: ./recover file\n");
        return 1;
    }

    FILE*outfile = NULL;
    //alocate memory for the name of the jpegs: 000.jpg\0  (8 characters in total)
    char *outfile_name = malloc(8 * sizeof(char));
    BYTE buffer[BLOCK_SIZE];
    int counter_image = 0;

    while (fread(buffer, 1, BLOCK_SIZE, infile) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & oxf0) == 0xe0 )
        {
            if (counter_image != 0)
            {
                fclose(outfile);
            }

            sprintf(outfile_name, "%03i.jpg", counter_image);
            outfile = fopen(outfile_name,"w");

            if (outfile == NULL)
            {
                printf("Output file not correctly opened"\n);
                return 1;
            }

            fwrite(buffer, 1, BLOCK_SIZE, outfile);

            counter_image++;
        }
        else
        {
            if (buffer[0] == 0)
            {
                continue;
            }
            fwrite(buffer, 1, BLOCK_SIZE, outfile);
        }
    }
    free(outfile_name);
    fclose(infile);
    fclose(outfile);

    return 0;

}