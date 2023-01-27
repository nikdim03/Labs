#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void merge(FILE *input1, FILE *input2, FILE *output);
void merge_sort(FILE *input, FILE *output, int n);
void print_file(FILE *fp);

int main() {
  // Open the file for reading
  FILE *fp = fopen("numbers.txt", "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file");
    return 1;
  }

  // Determine the number of integers in the file
  int n = 0;
  int x;
  while (fscanf(fp, "%d", &x) == 1) {
    n++;
  }
  // Reset the file pointer to the beginning of the file
  rewind(fp);

  // Open a temporary file for writing
  FILE *temp = tmpfile();
  if (temp == NULL) {
    fprintf(stderr, "Error creating temporary file");
    return 1;
  }

  // Sort the numbers in the file
  merge_sort(fp, temp, n);

  // Print the sorted numbers
  rewind(temp);
  print_file(temp);

  // Close the files
  fclose(fp);
  fclose(temp);

  return 0;
}

void merge(FILE *input1, FILE *input2, FILE *output) {
  int x, y;

  // Read the first number from each input file
  fscanf(input1, "%d", &x);
  fscanf(input2, "%d", &y);

  // While both input files are not empty, compare the numbers and
  // write the smaller one to the output file
  while (!feof(input1) && !feof(input2)) {
    if (x <= y) {
      fprintf(output, "%d\n", x);
      fscanf(input1, "%d", &x);
    } else {
      fprintf(output, "%d\n", y);
      fscanf(input2, "%d", &y);
    }
  }

  // Write the remaining numbers from the non-empty input file to the output
  // file
  while (!feof(input1)) {
    fprintf(output, "%d\n", x);
    fscanf(input1, "%d", &x);
  }
  while (!feof(input2)) {
    fprintf(output, "%d\n", y);
    fscanf(input2, "%d", &y);
  }
}

void merge_sort(FILE *input, FILE *output, int n) {
  if (n <= 1) return;

  // Split the input file in half
  int middle = n / 2;
  int x;
  FILE *input1 = tmpfile();
  FILE *input2 = tmpfile();
  if (input1 == NULL || input2 == NULL) {
    fprintf(stderr, "Error creating temporary file");
    return;
  }
  for (int i = 0; i < middle; i++) {
    fscanf(input, "%d", &x);
    fprintf(input1, "%d\n", x);
  }
  for (int i = middle; i < n; i++) {
    fscanf(input, "%d", &x);
    fprintf(input2, "%d\n", x);
  }

  // Sort the two halves
  merge_sort(input1, output, middle);
  merge_sort(input2, output, n - middle);

  // Merge the sorted halves
  rewind(input1);
  rewind(input2);
  merge(input1, input2, output);

  // Close the temporary files
  fclose(input1);
  fclose(input2);
}

void print_file(FILE *fp) {
  int x;
  while (fscanf(fp, "%d", &x) == 1) {
    printf("%d ", x);
  }
  printf("\n");
}
