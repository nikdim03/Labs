#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void merge_sort(FILE *input_file, FILE *output_file, long start, long end);
void merge(FILE *input_file, FILE *output_file, long start, long mid, long end);

int main() {
  /* Open the input and output files */
  FILE *input_file = fopen("input.txt", "r");
  FILE *output_file = fopen("output.txt", "w");
  /* Check if the files were successfully opened */
  if (input_file == NULL || output_file == NULL) {
    perror("Error opening files");
    return 1;
  }
  /* Call the merge sort function */
  merge_sort(input_file, output_file, 0, 5);
  /* Close the files */
  fclose(input_file);
  fclose(output_file);
  return 0;
}

void merge_sort(FILE *input_file, FILE *output_file, long start, long end) {
  /*Check if there is only one element in the sequence*/
  if (start >= end - 1) {
    return;
  }
  /* Calculate the middle point */
  long mid = (start + end) / 2;
  /* Recursively sort the first half of the sequence */
  merge_sort(input_file, output_file, start, mid);
  /* Recursively sort the second half of the sequence */
  merge_sort(input_file, output_file, mid, end);
  /* Merge the two sorted halves */
  merge(input_file, output_file, start, mid, end);
}

void merge(FILE *input_file, FILE *output_file, long start, long mid,
           long end) {
  /*Seek to the start of the file */
  fseek(input_file, start * 2, SEEK_SET);
  /* Initialize the indices for the input file */
  long i = start;
  long j = mid;
  /* Merge the two halves of the sequence */
  while (i < mid && j < end) {
    /* Read the current elements from the input file */
    int left, right;
    fscanf(input_file, "%d", &left);
    fseek(input_file, j * 2, SEEK_SET);
    fscanf(input_file, "%d", &right);
    /* Check which element is smaller */
    if (left <= right) {
      /* Write the smaller element to the output file */
      fprintf(output_file, "%d ", left);
      i++;
    } else {
      /* Write the smaller element to the output file */
      fprintf(output_file, "%d ", right);
      j++;
    }
  }
  /* Write the remaining elements from the left half of the sequence to the
   * output file */
  while (i < mid) {
    fseek(input_file, i * 2, SEEK_SET);
    int left;
    fscanf(input_file, "%d", &left);
    fprintf(output_file, "%d ", left);
    i++;
  }
  /* Write the remaining elements from the right half of the sequence to the
   * output file */
  while (j < end) {
    fseek(input_file, j * 2, SEEK_SET);
    int right;
    fscanf(input_file, "%d", &right);
    fprintf(output_file, "%d ", right);
    j++;
  }
  /* Add a newline character after each modified sequence */
  fprintf(output_file, "\n");
}