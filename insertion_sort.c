

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int n);

void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n - 1; i++)
    {
    int value = arr[i];
    int hole = i;
    while (hole > 0 && arr[hole - 1] > value)
    {
        arr[hole] = arr[hole - 1];
        hole = hole - 1;
    }
    arr[hole] = value;
    }
}

int main()
{
    int arr[50] = {5,4,3,2,1};
    insertion_sort(arr, 6);
    for (int i = 0; i < 5; i++)
    {
        printf("%d, ", arr[i]);
    }
    return 0;
}