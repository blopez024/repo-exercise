#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge(int arr[], int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // int LEFT[n1];
    // int RIGHT[n2];
    int *LEFT = malloc(n1 * sizeof(int));
    int *RIGHT = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
    {
        LEFT[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        RIGHT[j] = arr[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (LEFT[i] < RIGHT[j])
        {
            arr[k++] = LEFT[i++];
        }
        else
        {
            arr[k++] = RIGHT[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = LEFT[i++];
    }

    while (j < n2)
    {
        arr[k++] = RIGHT[j++];
    }

    free(LEFT);
    free(RIGHT);
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}