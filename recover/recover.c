#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int BLOCK_SIZE = 512;
// a JPEG file could have more than one block

int main(int argc, char *argv[])
{
    //empty spaces are 0.

    typedef uint8_t BYTE;

    FILE*infile = fopen(argv[1], "r");

    BYTE buffer[BLOCK_SIZE];
    int counter = 0;

    while (fread(buffer, 1, BLOCK_SIZE, infile) == BLOCK_SIZE)
    {   /*the four first bytes have to be 0xff, 0xd8, oxff, oxe*/
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & oxf0) == 0xe0 )
        {
            fclose(/*old JPEG file*/)
            sprintf(counter, "03i.jpg", 2)
            FILE*outfile = fopen(/*allocate room for image*/,"w");
            fwrite(buffer, 1, BLOCK_SIZE, outfile);
            counter++;
        }
    }

    fclose(infile);
    fclose(outfile);

}