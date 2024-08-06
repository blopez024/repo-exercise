#include <stdio.h>
#include "sort.h"

void print_array(int arr[], int n)
{
    printf("{ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}

int main(void)
{
    int arr[] = {3, 4, 1, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, n);

    // insert_sort(arr, n);
    // merge_sort(arr, 0, n - 1);
    // quick_sort(arr, 0, n - 1);
    bubble_sort(arr, n);

    print_array(arr, n);
}