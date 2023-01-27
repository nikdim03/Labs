#include <stdio.h>
#include <string.h>

int main() {
  unsigned int i = 0, count = 0, len = 0, minLen = 0;
  char str[100];

  //   input
  gets(str);

  //   find minLen
  count = strlen(str);
  minLen = count;
   for (i = 0; i <= count; i++) {
    if (str[i] != ' ' && str[i] != '\0') {
      len++;
    } else {
      if (len < minLen && len != 0) minLen = len;
      len = 0;
    }
  }
  printf("%d", minLen);
  return 0;
}