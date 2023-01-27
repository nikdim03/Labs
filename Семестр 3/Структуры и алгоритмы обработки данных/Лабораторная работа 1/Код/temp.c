#include <stdio.h>

int main() {
  char str[10000];
  unsigned int i = 0, count = 0;
  while (str[i] != '\n') {
    str[i] = getchar();
    if (str[i] != '\n') i++;
  }
  i--;
  while (str[i] != ' ') {
    count++;
    i--;
  }
  printf("\n%d", count);
  return 0;
}