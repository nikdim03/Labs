#include <stdio.h>

int main() {
  unsigned int count = 1000, len = 0, minLen = 0;
  char ch = 0;
  FILE *fp = fopen ("3r.txt", "r");

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

//   write in file
  fp = fopen ("3w.txt", "w");
  fprintf(fp, "%d", minLen);
  fclose(fp);

//   printf("%d", minLen);
  return 0;
}