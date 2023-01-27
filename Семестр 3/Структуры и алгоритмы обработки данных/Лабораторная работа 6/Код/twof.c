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

// Function to sort an array using 2-phase merge sort
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // Find the middle point
    int m = l + (r - l) / 2;
    // Divide the array into two subarrays and sort them
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    // Merge the sorted subarrays
    int i = l;
    int j = m + 1;
    int k = 0;
    int temp[r - l + 1];
    while (i <= m && j <= r) {
      if (arr[i] <= arr[j])
        temp[k++] = arr[i++];
      else
        temp[k++] = arr[j++];
    }
    // Copy the remaining elements of the first subarray, if there are any
    while (i <= m) temp[k++] = arr[i++];
    // Copy the remaining elements of the second subarray, if there are any
    while (j <= r) temp[k++] = arr[j++];
    // Copy the sorted subarray back to the original array
    for (i = l, j = 0; i <= r; i++, j++) arr[i] = temp[j];
  }
}

// Function to print an array
void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) printf("%d ", arr[i]);
  printf("\n");
}

// Driver program to test above functions
int main() {
  // Read array from file
  int arr[100];
  int i, size;
  FILE *fp;
  fp = fopen("array.txt", "r");
  if (fp == NULL) {
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }
  i = 0;
  while (fscanf(fp, "%d", &arr[i]) != EOF) {
    i++;
  }
  size = i;
  fclose(fp);

  printf("Given array is \n");
  printArray(arr, size);
  mergeSort(arr, 0, size - 1);
  printf("\nSorted array is \n");
  printArray(arr, size);
  return 0;
}
