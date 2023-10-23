#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int BLOCK_SIZE = 512;
// a JPEG file can have more than one block

int main(int argc, char *argv[])
{
    //empty spaces are 0.

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

    BYTE buffer[BLOCK_SIZE];
    int counter_image = 0;
    int memo_block = 1;

    while (fread(buffer, 1, BLOCK_SIZE, infile) == BLOCK_SIZE)
    {
        fread(buffer, 1, BLOCK_SIZE, infile);
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & oxf0) == 0xe0 )
        {
            if (counter_image = 0)
            {
                int* outfile_ptr = (int*) malloc(memo_block * sizeof(BLOCK_SIZE));
                if (outfile_ptr == NULL)
                {
                    printf("Memory not allocated for output file"\n);
                    return 1;
                }
                counter_image++;
                sprintf(outfile_ptr, "%03i.jpg", counter_image);

                FILE*outfile = fopen(outfile_ptr,"w");
                fwrite(buffer, 1, BLOCK_SIZE, outfile);

            }
            else
            {
                fclose(/*old JPEG file*/);
                sprintf(counter, "03i.jpg", 2);
                FILE*outfile = fopen(/*add more room for image*/,"w");
                fwrite(buffer, 1, BLOCK_SIZE, outfile);
                counter++;
            }
        }
        else ( /*not the start of a new jpeg, keep writing the data of the image*/)
    }

    fclose(infile);
    fclose(outfile);

}