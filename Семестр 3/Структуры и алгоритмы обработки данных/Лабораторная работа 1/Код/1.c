#include <stdio.h>

int main() {
  unsigned int i = 0, count = 0, len = 0, minLen = 0;
  char str[100];

  //   input
  while (str[count] != '\n') {
    str[count] = getchar();
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
  printf("%d", minLen);
  return 0;
}