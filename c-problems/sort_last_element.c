#include <stdio.h>

// size = 5
//  0, 1, 2, 3, 4
// {1, 2, 4, 5, 3}

void sort_last_element(int arr[], int size)
{

    int key = arr[size - 1];

    int i = size - 2;

    while (i >= 0 && arr[i] > key)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = key;
}

void print_arr(int arr[], int size)
{
    printf("{");
    for (int i = 0; i < size; i++)
    {
        printf("%2d", arr[i]);
    }
    printf(" }\n");
}

int main(void)
{
    int arr[] = {1, 2, 4, 5, 3};
    int size = sizeof(arr) / sizeof(int);

    print_arr(arr, size);
    sort_last_element(arr, size);
    print_arr(arr, size);
}