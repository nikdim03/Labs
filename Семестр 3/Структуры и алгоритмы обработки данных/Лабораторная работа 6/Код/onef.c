#include <stdio.h>
#include <stdlib.h>

// Function to merge two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  // Create temp arrays
  int L[n1], R[n2];

  // Copy data to temp arrays L[] and R[]
  for (i = 0; i < n1; i++) L[i] = arr[l + i];
  for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

  // Merge the temp arrays back into arr[l..r]
  i = 0;  // Initial index of first subarray
  j = 0;  // Initial index of second subarray
  k = l;  // Initial index of merged subarray
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of L[], if there are any
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of R[], if there are any
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Function to sort an array using merge sort
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // Find the middle point
    int m = l + (r - l) / 2;

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted halves
    merge(arr, l, m, r);
  }
}

// Function to print an array
void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) printf("%d ", arr[i]);
  printf("\n");
}
int main() {
  // Open the file in read mode
  FILE* file = fopen("array.txt", "r");

  // Check if the file was successfully opened
  if (file == NULL) {
    printf("Error opening file!\n");
    return 1;
  }

  // Declare an array to store the elements read from the file
  int arr[100];  // max size of the array is 100
  int size = 0;  // size of the array

  // Read the elements of the array from the file
  int element;
  while (fscanf(file, "%d", &element) == 1) {
    arr[size] = element;
    size++;
  }
  // Close the file
  fclose(file);
  printf("Given array is \n");
  printArray(arr, size);

  mergeSort(arr, 0, size - 1);

  printf("\nSorted array is \n");
  printArray(arr, size);

  return 0;
}
