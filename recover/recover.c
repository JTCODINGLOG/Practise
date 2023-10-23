#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
    FILE*outfile;
    if (infile == NULL)
    {
        printf("Usage: ./recover file\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int counter_image = 0;
    int memo_block = 1;

    while (fread(buffer, 1, BLOCK_SIZE, infile) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & oxf0) == 0xe0 )
        {
            if (counter_image != 0)
            {
                fclose(outfile);
            }

            memo_block = 1;

            int* outfile_ptr[counter_image] = (int*) malloc(memo_block * sizeof(BLOCK_SIZE));
            if (outfile_ptr == NULL)
            {
                printf("Memory not allocated for output file"\n);
                return 1;
            }

            sprintf(outfile_ptr[counter_image], "%03i.jpg", counter_image);

            outfile = fopen(outfile_ptr,"w");
            fwrite(buffer, 1, BLOCK_SIZE, outfile);

            counter_image++;
            memo_block++;
        }
        else
        {
            fread(buffer, 1, BLOCK_SIZE, infile);
            int* outfile_ptr[counter_image] = (int*) malloc(memo_block * sizeof(BLOCK_SIZE));
            fwrite(buffer, 1, BLOCK_SIZE, outfile);
            memo_block++;
        }
    }

    fclose(infile);
    fclose(outfile);

}