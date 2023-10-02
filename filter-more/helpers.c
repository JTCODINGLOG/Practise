#include <math.h>
#include "helpers.h"


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < round(width/2); j++)
        {
            RGBTRIPLE buffer;
            buffer = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    return;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            if((i != 0) && (i != height-1) && (j != 0) && (j != width-1))
            {
                int tot_red = 0;
                int tot_green = 0;
                int tot_blue = 0;

                for (int k = -1; k < 2; k++)
                {
                    for (int l = -1; l < 2; l++)
                    {
                        tot_red += copy[i+k][j+l].rgbtRed;
                        tot_green += copy[i+k][j+l].rgbtGreen;
                        tot_blue += copy[i+k][j+l].rgbtBlue;
                    }
                 }

                 image[i][j].rgbtRed = tot_red / 9;
                 image[i][j].rgbtGreen = tot_green / 9;
                 image[i][j].rgbtBlue = tot_blue / 9;
            }


            //theory: divide each tot between 9 passing the value to the image pixel.
            //problem: not all the pixels have a perfect matrix around


        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
