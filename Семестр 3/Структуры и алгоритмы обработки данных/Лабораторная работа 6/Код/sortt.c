#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void merge_sort(FILE *in, long left, long right, FILE *out);
void merge(FILE *in1, long left1, long right1, FILE *in2, long left2,
           long right2, FILE *out);
void write_sequence(FILE *in, long left, long right, FILE *out);

int main(int argc, char *argv[]) {
  // Check for correct number of arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
    return 1;
  }
  // Open the input and output files
  FILE *in = fopen(argv[1], "r");
  FILE *out = fopen(argv[2], "w");
  // Check if the files were successfully opened
  if (!in || !out) {
    fprintf(stderr, "Error opening files!\n");
    return 1;
  }
  // Get the size of the input file
  fseek(in, 0, SEEK_END);
  long size = ftell(in);
  fseek(in, 0, SEEK_SET);
  // Sort the input file
  merge_sort(in, 0, size, out);
  // Close the input and output files
  fclose(in);
  fclose(out);
  return 0;
}

void merge_sort(FILE *in, long left, long right, FILE *out) {
  // Check if the file has more than one element
  if (left < right - 1) {
    // Divide the file into two equal parts
    long mid = (left + right) / 2;
    // Create temporary files for the two halves
    FILE *temp1 = tmpfile();
    FILE *temp2 = tmpfile();
    // Sort the two halves of the file
    merge_sort(in, left, mid, temp1);
    merge_sort(in, mid, right, temp2);
    // Merge the two sorted halves into the output file
    merge(temp1, 0, mid - left, temp2, 0, right - mid, out);
    // Close the temporary files
    fclose(temp1);
    fclose(temp2);
  } else {
    // The file has only one element, so we can just write it to the output file
    char value;
    fseek(in, left, SEEK_SET);
    fread(&value, sizeof(char), 1, in);
    printf("%d ", value);
    fwrite(&value, sizeof(char), 1, out);
  }
}

void merge(FILE *in1, long left1, long right1, FILE *in2, long left2,
           long right2, FILE *out) {
  // Keep track of the current position in each half
  long pos1 = left1;
  long pos2 = left2;
  // Read and merge the two halves until one of them is exhausted
  while (pos1 < right1 && pos2 < right2) {
    // Read the next value from each half
    char value1, value2;
    fseek(in1, pos1, SEEK_SET);
    fread(&value1, sizeof(char), 1, in1);
    fseek(in2, pos2, SEEK_SET);
    fread(&value2, sizeof(char), 1, in2);
    // Skip leading non-digit characters
    while (!isdigit(value1) && pos1 < right1) {
      pos1++;
      fseek(in1, pos1, SEEK_SET);
      fread(&value1, sizeof(char), 1, in1);
    }
    while (!isdigit(value2) && pos2 < right2) {
      pos2++;
      fseek(in2, pos2, SEEK_SET);
      fread(&value2, sizeof(char), 1, in2);
    }
    // Compare the numbers represented by the contiguous sequences of digits
    int number1 = 0;
    int number2 = 0;
    while (isdigit(value1)) {
      number1 = number1 * 10 + (value1 - '0');
      pos1++;
      fseek(in1, pos1, SEEK_SET);
      fread(&value1, sizeof(char), 1, in1);
    }
    while (isdigit(value2)) {
      number2 = number2 * 10 + (value2 - '0');
      pos2++;
      fseek(in2, pos2, SEEK_SET);
      fread(&value2, sizeof(char), 1, in2);
    }
    // Write the smaller number to the output file
    if (number1 < number2) {
      fprintf(out, "%d ", number1);
    } else {
      fprintf(out, "%d ", number2);
    }
  }
  // Write the remaining values from the first half
  if (pos1 < right1) {
    fseek(in1, pos1, SEEK_SET);
    char value;
    while (fread(&value, sizeof(char), 1, in1)) {
      fprintf(out, "%c", value);
    }
  }
  // Write the remaining values from the second half
  if (pos2 < right2) {
    fseek(in2, pos2, SEEK_SET);
    char value;
    while (fread(&value, sizeof(char), 1, in2)) {
      fprintf(out, "%c", value);
    }
  }
}

void write_sequence(FILE *in, long left, long right, FILE *out) {
  // Go to the beginning of the sequence
  fseek(in, left, SEEK_SET);
  // Write each value in the sequence to a new line in the output file
  char value;
  while (ftell(in) < right && fread(&value, sizeof(char), 1, in)) {
    fprintf(out, "%c", value);
  }
  fprintf(out, "\n");
}
