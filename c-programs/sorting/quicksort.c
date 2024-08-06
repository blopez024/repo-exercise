#include "sort.h"

int partition(int arr[], int low, int high)
{
    // Choose the pivot
    int pivot = arr[high];

    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements on the left side. Elements from low to
    // i are smaller after every iteration
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            // Swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Move pivot after smaller elements and
    i++;

    // Swap
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    // Return its position
    return i;
}

// The QuickSort function implementation
void quick_sort(int arr[], int low, int high)
{

    if (low <= high)
    {

        // partition_index is the partition return index of pivot
        int partition_index = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
}