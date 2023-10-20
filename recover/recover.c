#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{

    // 0xff, 0xd8, oxff, oxesomething.
    //512 bytes until a new JPEG is found.
    //empty spaces are 0.

    typedef uint8_t BYTE;

    FILE*file = fopen(argv[1], "r");


    int BLOCK_SIZE = 512;

    BYTE buffer;

    while (fread(buffer, 1, BLOCK_SIZE, file))
    {

    }

}