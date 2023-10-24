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
    // open memory card
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
    bool same_image;
    same_image = false;

    while (fread(buffer, 1, BLOCK_SIZE, infile) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 )
        {
            if (counter_image != 0)
            {
                fclose(outfile);
                same_image = false;
            }

            sprintf(outfile_name, "%03i.jpg", counter_image);
            outfile = fopen(outfile_name,"w");
            if (outfile == NULL)
            {
                free(outfile_name);
                fclose(infile);
                printf("Output file %i not correctly opened\n", counter_image);
                return 2;
            }
            same_image = true;
            counter_image++;
        }
        if else (same_image == false)
        {
            continue;
        }

        fwrite(buffer, 1, BLOCK_SIZE, outfile);
    }


    free(outfile_name);
    fclose(infile);
    fclose(outfile);

    return 0;

}