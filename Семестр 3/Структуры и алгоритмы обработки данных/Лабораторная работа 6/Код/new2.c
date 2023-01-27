#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void merge_sort(FILE *input_file, FILE *output_file, FILE *temp_file_1,
                FILE *temp_file_2, long start, long end);
void merge(FILE *temp_file_1, FILE *temp_file_2, FILE *input_file,
           FILE *output_file, long start, long mid, long end);

int main() {
  /* Open the input and output files */
  FILE *input_file = fopen("input.txt", "r");
  FILE *output_file = fopen("output.txt", "w");
  /*Check if the files were successfully opened*/
  if (input_file == NULL || output_file == NULL) {
    perror("Error opening files");
    return 1;
  }
  /*Open the temporary files */
  FILE *temp_file_1 = tmpfile();
  FILE *temp_file_2 = tmpfile();
  /*Check if the temporary files were successfully opened*/
  if (temp_file_1 == NULL || temp_file_2 == NULL) {
    perror("Error opening temporary files");
    return 1;
  }
  /*Call the merge sort function*/
  merge_sort(input_file, output_file, temp_file_1, temp_file_2, 0, 5);
  /*Close the temporary files*/
  fclose(temp_file_1);
  fclose(temp_file_2);
  /*Close the input and output files */
  fclose(input_file);
  fclose(output_file);
  return 0;
}

void merge_sort(FILE *input_file, FILE *output_file, FILE *temp_file_1,
                FILE *temp_file_2, long start, long end) {
  /*Check if there is only one element in the sequence*/
  if (start >= end - 1) {
    return;
  }
  /*Calculate the middle point*/
  long mid = (start + end) / 2;
  /*Recursively sort the first half of the sequence*/
  merge_sort(input_file, output_file, temp_file_1, temp_file_2, start, mid);
  /* Recursively sort the second half of the sequence*/
  merge_sort(input_file, output_file, temp_file_1, temp_file_2, mid, end);
  /*Merge the two sorted halves */
  merge(temp_file_1, temp_file_2, input_file, output_file, start, mid, end);
}

void merge(FILE *temp_file_1, FILE *temp_file_2, FILE *input_file,
           FILE *output_file, long start, long mid, long end) {
  /*Seek to the start of the input file*/
  fseek(input_file, start * 2, SEEK_SET);
  /*Initialize the indices for the input file*/
  long i = start;
  long j = mid;
  /*Merge the two halves of the sequence*/
  while (i < mid && j < end) {
    /*Read the current elements from the input file*/
    int left, right;
    fscanf(input_file, "%d", &left);
    fseek(input_file, j * 2, SEEK_SET);
    fscanf(input_file, "%d", &right);
    /*Check which element is smaller*/
    if (left <= right) {
      /*Write the smaller element to the temporary file*/
      fprintf(temp_file_1, "%d ", left);
      i++;
    } else {
      /*Write the smaller element to the temporary file*/
      fprintf(temp_file_1, "%d ", right);
      j++;
    }
  }
  /*Write the remaining elements from the left half of the sequence to the
   * temporary file*/
  while (i < mid) {
    fseek(input_file, i * 2, SEEK_SET);
    int left;
    fscanf(input_file, "%d", &left);
    fprintf(temp_file_1, "%d ", left);
    i++;
  }
  /*Write the remaining elements from the right half of the sequence to the
  temporary file*/
  while (j < end) {
    fseek(input_file, j * 2, SEEK_SET);
    int right;
    fscanf(input_file, "%d", &right);
    fprintf(temp_file_1, "%d ", right);
    j++;
  }
  /*Write the sorted elements from the temporary file back to the input file*/
  rewind(temp_file_1);
  fseek(input_file, start * 2, SEEK_SET);
  int element;
  while (fscanf(temp_file_1, "%d", &element) == 1) {
    fprintf(input_file, "%d ", element);
  }
  /*Write the sorted elements from the input file to the output file*/
  fseek(input_file, start * 2, SEEK_SET);
  while (fscanf(input_file, "%d", &element) == 1) {
    fprintf(output_file, "%d ", element);
  }
  /* Add a newline character after each modified sequence */
  fprintf(output_file, "\n");
}
