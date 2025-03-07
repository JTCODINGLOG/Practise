// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);
int min(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
    printf("The min value is %i.\n", min(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] > array[i+1])
        {
            int temp = array[i+1];
            array[i+1] = array[i];
            array[i] = temp;
        }
    }
    return array[n-1];
}

int min(int array[], int n)
{
    int min_value = array[0];

    for (int i = 0; i < n; i++)
    {
        if(min_value > array[i])
        {
            min_value = array[i];
        }
    }
    return min_value;
}
