#include <stdio.h>
#include <stdlib.h>

int main() {
  const unsigned N = 5;
  unsigned int count = 0, i = 0, j = 5, len = 0, minLen = 0;
  char *str = (char *)calloc(N, sizeof(char *));
  if (str == NULL) {
    printf("Error allocating memory!");
    exit(1);
  }
  char ch = 0;
  FILE *fp = fopen("3w.txt", "w");

  //   input
  while (str[count] != '\n') {
    if (count < j) {
      str[count] = getchar();
    } else {
      j += N;
      str = (char *)realloc(str, sizeof(char *));
      str[count] = getchar();
    }
    if (str[count] != '\n') count++;
  }

  // write to file
  for (i = 0; i < count; i++) {
    fwrite(str + i, sizeof(char), sizeof(str[i]), fp);
  }
  fclose(fp);
  free(str);

  fp = fopen("3w.txt", "r");

  //   find minLen
  minLen = count;
  while (ch != EOF) {
    ch = getc(fp);
    if (ch != ' ' && ch != EOF) {
      len++;
    } else {
      if (len < minLen && len != 0) minLen = len;
      len = 0;
    }
  }
  fclose(fp);

  //   write to file
  fp = fopen("output.txt", "w");
  fprintf(fp, "%d", minLen);
  fclose(fp);

  //   printf("%d", minLen);
  return 0;
}