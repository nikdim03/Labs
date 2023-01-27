#include <stdio.h>

void main() {
  char c, str[50], newstr[50];
  int i = 0, g = 0, j = 0;

  printf("Vvedite stroku:\n\n>");
  while (str[i] != '\n') {
    str[i] = getchar();
    if (str[i] != '\n') {
      i++;
      g++;
    }
  }
  for (i = 0; i <= g; i++) {
    if (str[i] == str[i + 1]) {
      while (str[i] != ' ' && i >= 0) {
        i--;
      }
      i++;
      while (str[i] != ' ' && str[i] != '\n') {
        newstr[j] = str[i];
        i++;
        j++;
      }
      newstr[j] = ' ';
      j++;
    }
  }
  j--;
  for (i = 0; i <= j; i++) {
    printf("%c", newstr[i]);
  }
}