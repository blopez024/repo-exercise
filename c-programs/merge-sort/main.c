#include <stdio.h>
#define LENGTH 30

void print_array(int arr[], int length);
void print_visual(int arr[], int length);
void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int middle, int right);

int main(void) {

  int arr[] = {17, 3, 28, 5,  24, 14, 10, 26, 13, 21, 1,  7,  19, 9,  11,
               30, 2, 20, 15, 8,  23, 4,  29, 12, 16, 27, 22, 25, 18, 6};
  int length = sizeof(arr) / sizeof(arr[0]);

  printf("Initial array:\n");
  print_array(arr, length);
  print_visual(arr, length);
  printf("-----------------------------------\n");

  merge_sort(arr, 0, length - 1);

  printf("-----------------------------------\n");
  printf("Sorted array:\n");
  print_array(arr, length);
  print_visual(arr, length);

  return 0;
}

void print_array(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%2d ", arr[i]);
  }
  printf("\n");
}

void print_visual(int arr[], int length) {
  int max = 0;
  for (int i = 0; i < length; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  for (int height = max; height > 0; height--) {
    for (int i = 0; i < length; i++) {
      if (arr[i] >= height) {
        printf(" * ");
      } else {
        printf("   ");
      }
    }
    printf("\n");
  }

  for (int i = 0; i < length; i++) {
    printf("---");
  }
  printf("\n");

  for (int i = 0; i < length; i++) {
    printf("%2d ", arr[i]);
  }
  printf("\n\n");
}

void merge_sort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    printf("Merging: left=%d, mid=%d, right=%d\n", left, mid, right);
    merge(arr, left, mid, right);
    print_array(arr, LENGTH);
    print_visual(arr, LENGTH);
  }
}

void merge(int arr[], int l, int m, int r) {

  // left array
  int n1 = m - l + 1;
  int left[n1];
  for (int i = 0; i < n1; i++) {
    left[i] = arr[l + i];
  }

  // right array
  int n2 = r - m;
  int right[n2];
  for (int j = 0; j < n2; j++) {
    right[j] = arr[m + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = l;

  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = left[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = right[j];
    j++;
    k++;
  }
}
