#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            if(pixel.rgbtBlue == 0)
            {
                pixel.rgbtBlue = 41;
                pixel.rgbtGreen = 181;
                pixel.rgbtRed = 209;
            }
        }
    }

    // Change all black pixels to a color of your choosing
}
