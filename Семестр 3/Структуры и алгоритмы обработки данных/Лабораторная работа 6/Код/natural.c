#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

void merge(int* a, int p, int q, int r) {
  int i, j, k;
  int n1 = q - p + 1;
  int n2 = r - q;
  int* L = malloc(sizeof(int) * (n1 + 1));
  int* R = malloc(sizeof(int) * (n2 + 1));

  for (i = 0; i < n1; i++) {
    L[i] = a[p + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = a[q + 1 + j];
  }

  L[n1] = MAX_SIZE;
  R[n2] = MAX_SIZE;
  i = 0;
  j = 0;

  for (k = p; k <= r; k++) {
    if (L[i] <= R[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = R[j];
      j++;
    }
  }

  free(L);
  free(R);
}

void merge_sort(int* a, int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
  }
}

int main() {
  int a[] = {5, 2, 4, 7, 1, 3, 2, 6};
  int n = sizeof(a) / sizeof(a[0]);
  printf("Given array is \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  merge_sort(a, 0, n - 1);

  printf("\nSorted array is \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}