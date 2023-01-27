#include <stdio.h>
#include <stdlib.h>

int main() {
  const unsigned int N = 5;
  unsigned int i = 0, j = 5, count = 0, len = 0, minLen = 0;
  char *str = (char *)malloc(N * sizeof(char *));
  if (str == NULL) {
    printf("Error allocating memory!");
    exit(1);
  }

  //   input
  while (str[count] != '\n') {
    if (count < j) {
      str[count] = getchar();
    } else {
      j += N;
      str = (char *)realloc(str, sizeof(char *));
      if (str == NULL) {
        printf("Error allocating memory!");
        exit(1);
      }

      str[count] = getchar();
    }
    if (str[count] != '\n') count++;
  }

  //   find minLen
  minLen = count;
  for (i = 0; i <= count; i++) {
    if (str[i] != ' ' && str[i] != '\n') {
      len++;
    } else {
      if (len < minLen && len != 0) minLen = len;
      len = 0;
    }
  }
  free(str);
  printf("%d", minLen);
  return 0;
}