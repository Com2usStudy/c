#include <unistd.h>
#include <stdio.h>

void swap(int *left, int *right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}

void fn_sort(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            int *left = (arr + j);
            int *right = (arr + j + 1);

            if (*right < *left)
            {
                swap(left, right);
            }
        }
    }
}