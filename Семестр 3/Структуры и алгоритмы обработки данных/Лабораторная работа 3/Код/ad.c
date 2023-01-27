#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int k = 5, i = 0, j = 0, n = 0, kol = 0;
  char *s = NULL;
  FILE *fp = fopen("t1.txt", "w");
  s = (char *)calloc(k, sizeof(char *));

  //   input
  while (s[i] != '\n') {
    if (i < j) {
      s[i] = getchar();
    } else {
      j += k;
      s = (char *)realloc(s, sizeof(char *));
      s[i] = getchar();
    }
    if (s[i] != '\n') i++;
  }
  
  // write to file
  for (i = 0; i < j; i++) {
    fwrite(s + i, sizeof(char), sizeof(s[i]), fp);
  }
  free(s);
  fclose(fp);

  // read from file
  fp = fopen("t1.txt", "r");
  s = (char *)calloc(n, sizeof(char *));

  while (s[i] != '\n') s[i] = getc(fp);

  for (i = 0; i < n; i++)
    if (s[i] == '+' && s[i + 1] >= '0' && s[i + 1] <= '9') {
      j = i;
      for (i = j; i <= n; i++) s[i] = s[i + 1];
      i = j;
      kol++;
    }
  for (i = 1; i < (n - kol); i++) {
    fprintf(fp, "%c", s[i]);
  }
  return 0;
}