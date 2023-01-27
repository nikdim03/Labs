#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[50], newstr[50];
  int i = 0, g = 0, j = 0;
  FILE* f1;
  f1 = fopen("file1.txt", "r");

  printf("Vvod faila");

  while (str[i] != EOF) {
    str[i] = fgetc(f1);
    if (str[i] != EOF) i++;
  }
  g = strlen(str);

  fclose(f1);

  f1 = fopen("file2.txt", "w");

  for (i = 0; i <= g; i++) {
    if (str[i] == str[i + 1]) {
      while (str[i] != ' ' && i >= 0) {
        i--;
      }
      i++;
      while (str[i] != ' ' && str[i] != '\0') {
        newstr[j] = str[i];
        i++;
        j++;
      }
      newstr[j] = ' ';
    //   j++;
    }
  }

  for (i = 0; i <= j; i++) {
    fputs(&newstr[i], f1);
  }
  newstr[j - 1] = '\0';
  printf("\n\nStroki s 2 podryad idushimi simvolomi:\n\n>");
  puts(newstr);
  fclose(f1);
  return 0;
}
