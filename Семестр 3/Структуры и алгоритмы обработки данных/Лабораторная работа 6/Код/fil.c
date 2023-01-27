#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void merge(FILE *array, FILE *temp_left, FILE *temp_right, int left, int middle,
           int right);
void merge_sort(FILE *array, FILE *temp_left, FILE *temp_right, int left,
                int right);
void print_array(FILE *array, int n);

int main() {
  // Open the file containing the array
  FILE *array = fopen("array.txt", "r");
  if (array == NULL) {
    fprintf(stderr, "Error opening file");
    return 1;
  }

  // Get the size of the array
  int n;
  fscanf(array, "%d", &n);

  // Allocate memory for temporary files
  FILE *temp_left = tmpfile();
  FILE *temp_right = tmpfile();
  if (temp_left == NULL || temp_right == NULL) {
    fprintf(stderr, "Error creating temporary files");
    return 1;
  }

  // Sort the array
  merge_sort(array, temp_left, temp_right, 0, n - 1);

  // Print the sorted array
  print_array(array, n);

  // Close the files
  fclose(array);
  fclose(temp_left);
  fclose(temp_right);

  return 0;
}

void merge(FILE *array, FILE *temp_left, FILE *temp_right, int left, int middle,
           int right) {
  // Copy both halves into the temp files
  rewind(array);
  fseek(array, sizeof(int), SEEK_SET);  // Skip the first line (size of array)
  rewind(temp_left);
  rewind(temp_right);
  int x;
  for (int i = 0; i < left; i++) {
    fscanf(array, "%d", &x);
  }
  for (int i = left; i <= middle; i++) {
    fscanf(array, "%d", &x);
    fprintf(temp_left, "%d\n", x);
  }
  for (int i = middle + 1; i <= right; i++) {
    fscanf(array, "%d", &x);
    fprintf(temp_right, "%d\n", x);
  }

  int i = left;
  int j = middle + 1;
  int k = left;

  // Copy the smallest values from either the left or the right side back
  // to the original array
  rewind(temp_left);
  rewind(temp_right);
  while (i <= middle && j <= right) {
    fscanf(temp_left, "%d", &x);
    int y;
    fscanf(temp_right, "%d", &y);
    if (x <= y) {
      fseek(array, (k - 1) * sizeof(int) + sizeof(int),
            SEEK_SET);  // Skip the first line (size of array)
      fprintf(array, "%d\n", x);
      i++;
    } else {
      fseek(array, (k - 1) * sizeof(int) + sizeof(int),
            SEEK_SET);  // Skip the first line (size of array)
      fprintf(array, "%d\n", y);
      j++;
    }
    k++;
  }
  // Copy the rest of the left side of the array into the target array
  rewind(temp_left);
  while (i <= middle) {
    fscanf(temp_left, "%d", &x);
    fseek(array, (k - 1) * sizeof(int) + sizeof(int),
          SEEK_SET);  // Skip the first line (size of array)
    fprintf(array, "%d\n", x);
    k++;
    i++;
  }

  // Output the array after each iteration of the merge function
  print_array(array, k);
}

void merge_sort(FILE *array, FILE *temp_left, FILE *temp_right, int left,
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

void print_array(FILE *array, int n) {
  rewind(array);
  fseek(array, sizeof(int), SEEK_SET);  // Skip the first line (size of array)
  int x;
  for (int i = 0; i < n; i++) {
    fscanf(array, "%d", &x);
    printf("%d ", x);
  }
  printf("\n");
}
