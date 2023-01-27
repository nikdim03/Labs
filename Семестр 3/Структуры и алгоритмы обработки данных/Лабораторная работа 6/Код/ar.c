#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void merge(int *array, int *temp_left, int *temp_right, int left, int middle,
           int right);
void merge_sort(int *array, int *temp_left, int *temp_right, int left,
                int right);
void print_array(int *array, int n);

int main() {
  // Test array
  int array[] = {38, 27, 43, 3, 9, 82, 10};
  int n = sizeof(array) / sizeof(array[0]);

  // Allocate memory for temporary arrays
  int *temp_left = malloc(n * sizeof(int));
  int *temp_right = malloc(n * sizeof(int));
  if (temp_left == NULL || temp_right == NULL) {
    fprintf(stderr, "Error allocating memory");
    return 1;
  }
  // Sort the array
  merge_sort(array, temp_left, temp_right, 0, n - 1);
  // Print the sorted array
  print_array(array, n);
  // Free the memory
  free(temp_left);
  free(temp_right);

  return 0;
}

void merge(int *array, int *temp_left, int *temp_right, int left, int middle,
           int right) {
  // Copy both halves into the temp arrays
  for (int i = left; i <= middle; i++) {
    temp_left[i] = array[i];
  }
  for (int i = middle + 1; i <= right; i++) {
    temp_right[i] = array[i];
  }

  int i = left;
  int j = middle + 1;
  int k = left;

  // Copy the smallest values from either the left or the right side back
  // to the original array
  while (i <= middle && j <= right) {
    if (temp_left[i] <= temp_right[j]) {
      array[k] = temp_left[i];
      i++;
    } else {
      array[k] = temp_right[j];
      j++;
    }
    k++;
  }

  // Copy the rest of the left side of the array into the target array
  while (i <= middle) {
    array[k] = temp_left[i];
    k++;
    i++;
  }

  // Output the array after each iteration of the merge function
  print_array(array, k);
}

void merge_sort(int *array, int *temp_left, int *temp_right, int left,
                int right) {
  if (left < right) {
    // Get the middle point
    int middle = (left + right) / 2;

    // Sort the first and second halves
    merge_sort(array, temp_left, temp_right, left, middle);
    merge_sort(array, temp_left, temp_right, middle + 1, right);

    // Merge the sorted halves
    merge(array, temp_left, temp_right, left, middle, right);
  }
}

void print_array(int *array, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}