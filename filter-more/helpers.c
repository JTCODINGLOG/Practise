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
    RGBTRIPLE buffer;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < round(width/2); j++)
        {
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

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int tot_red = 0;
            int tot_green = 0;
            int tot_blue = 0;
            float counter = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    int x = i + k;
                    int y = j + l;
                    if ( x < 0 || y < 0 || x > (height -1) || y > (width -1))
                    {
                        continue;
                    }
                    tot_red += copy[x][y].rgbtRed;
                    tot_green += copy[x][y].rgbtGreen;
                    tot_blue += copy[x][y].rgbtBlue;

                    counter++;
                }


            }
            image[i][j].rgbtRed = round(tot_red / counter);
            image[i][j].rgbtGreen = round(tot_green / counter);
            image[i][j].rgbtBlue = round(tot_blue / counter);
            //theory: divide each tot between 9 passing the value to the image pixel.
            //problem: not all the pixels have a perfect matrix around
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    int gx_matrix[3][3] = {{-1,0,1}, {-2,0,2}, {-1,0,1}};
    int gy_matrix[3][3] = {{-1,2,1}, {0,0,0}, {1,2,1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int tot_red_gx = 0;
            int tot_green_gx = 0;
            int tot_blue_gx = 0;
            int tot_red_gy = 0;
            int tot_green_gy = 0;
            int tot_blue_gy = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    int x = i + k;
                    int y = j + l;
                    int x_m = k + 1;
                    int y_m = l + 1;
                    if ( x < 0 || y < 0 || x > (height -1) || y > (width -1))
                    {
                        continue;
                    }
                    tot_red_gx += (gx_matrix[x_m][y_m]*copy[x][y].rgbtRed);
                    tot_green_gx += (gx_matrix[x_m][y_m]*copy[x][y].rgbtGreen);
                    tot_blue_gx += (gx_matrix[x_m][y_m]*copy[x][y].rgbtBlue);

                    tot_red_gy += (gy_matrix[x_m][y_m]*copy[x][y].rgbtRed);
                    tot_green_gy += (gy_matrix[x_m][y_m]*copy[x][y].rgbtGreen);
                    tot_blue_gy += (gy_matrix[x_m][y_m]*copy[x][y].rgbtBlue);
                }
            }
            image[i][j].rgbtRed = sqrt(pow(tot_red_gx, 2) + pow(tot_red_gy, 2));
            image[i][j].rgbtGreen = sqrt(pow(tot_green_gx, 2) + pow(tot_green_gy, 2));
            image[i][j].rgbtBlue = sqrt(pow(tot_blue_gx, 2) + pow(tot_blue_gy, 2));

            if (image[i][j].rgbtRed > 255)
            {image[i][j]rgbtRed = 255}
            if (image[i][j].rgbtGreen > 255)
            {image[i][j]rgbtGreen = 255}
            if (image[i][j].rgbtBlue > 255)
            {image[i][j]rgbtBlue = 255}
        }
    }
    return;
}
