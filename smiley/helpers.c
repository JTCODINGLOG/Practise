#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if(image[i][j].rgbtBlue == 0)
            {
                image[i][j].rgbtBlue = 41;
                image[i][j].rgbtGreen = 181;
                image[i][j].rgbtRed = 209;
            }
        }
    }
    return;
    // Change all black pixels to a color of your choosing
}
