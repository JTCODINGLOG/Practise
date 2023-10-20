#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    //512 bytes until a new JPEG is found.
    //empty spaces are 0.

    typedef uint8_t BYTE;

    FILE*infile = fopen(argv[1], "r");

    FILE*outfile = fopen(/*allocate room for image*/,"w");

    BYTE buffer[BLOCK_SIZE];

    while (fread(buffer, 1, BLOCK_SIZE, infile))
    {
        if (/*the four first bytes have to be 0xff, 0xd8, oxff, oxe*/)
        {
            fwrite(buffer, 1, BLOCK_SIZE, outfile);
        }
    }

    fclose(infile);
    fclose(outfile);

}