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

    while (fread(buffer, 1, BLOCK_SIZE, infile) == BLOCK_SIZE)
    {   /*the four first bytes have to be 0xff, 0xd8, oxff, oxe*/
        if (buffer[0] = ff && buffer[1] == d8 && buffer[2] == ff &&)
        {
            fclose(/*old JPEG file*/)
            FILE*outfile = fopen(/*allocate room for image*/,"w");
            fwrite(buffer, 1, BLOCK_SIZE, outfile);
        }
    }

    fclose(infile);
    fclose(outfile);

}