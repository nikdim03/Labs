#include <stdio.h>
#include <stdlib.h>

// Определение конца блока
short end_range(FILE* f) {
  int tmp;
  tmp = fgetc(f);
  tmp = fgetc(f);
  // Возвращаемся на 2 позиции назад
  if (tmp != '\'')
    fseek(f, -2, 1);
  else
    fseek(f, 1, 1);
  return tmp == '\'' ? 1 : 0;
}

// Сортировки естественным слиянием
void merge_sort() {
  int s1, s2, a1 = 0, a2 = 0, mark = 0;
  FILE *f, *f1, *f2;
  s1 = s2 = 1;
  // Пока в обоих файлах серия не равна нулю
  while (s1 > 0 && s2 > 0) {
    mark = 1;
    s1 = 0;
    s2 = 0;
    f = fopen("base.txt", "r");
    f1 = fopen("f1.txt", "w");
    f2 = fopen("f2.txt", "w");
    // Первое число записываем в f1
    fscanf(f, "%d", &a1);
    if (!feof(f)) {
      fprintf(f1, "%d ", a1);
    }
    // Второе число сравниваем с первым и выбираем файл для записи
    // В случае, если будет найдена упорядоченная последовательность, серия
    // увеличится, а время сортировки уменьшится
    if (!feof(f)) fscanf(f, "%d", &a2);
    while (!feof(f)) {
      if (a2 < a1) {
        switch (mark) {
          case 1: {
            fprintf(f1, "' ");
            mark = 2;
            s1++;
            break;
          }
          case 2: {
            fprintf(f2, "' ");
            mark = 1;
            s2++;
            break;
          }
        }
      }
      // Смена файлов
      if (mark == 1) {
        fprintf(f1, "%d ", a2);
        s1++;
      } else {
        fprintf(f2, "%d ", a2);
        s2++;
      }
      // Теперь будем сравнивать следующий элемент
      a1 = a2;
      fscanf(f, "%d", &a2);
    }
    // Последнее действие после полного прочтения файла, деление серий
    if (s2 > 0 && mark == 2) {
      fprintf(f2, "'");
    }
    if (s1 > 0 && mark == 1) {
      fprintf(f1, "'");
    }
    fclose(f2);
    fclose(f1);
    fclose(f);

    // Сортировка и запись в файл f
    f = fopen("output.txt", "w");
    f1 = fopen("f1.txt", "r");
    f2 = fopen("f2.txt", "r");
    if (!feof(f1)) fscanf(f1, "%d", &a1);
    if (!feof(f2)) fscanf(f2, "%d", &a2);
    short file1, file2;
    // Пока оба файла не закончились
    while (!feof(f1) && !feof(f2)) {
      // В каждом файле ещё есть серии
      file1 = file2 = 0;
      while (!file1 && !file2) {
        if (a1 <= a2) {
          fprintf(f, "%d ", a1);
          // Определяем конец блока
          file1 = end_range(f1);
          fscanf(f1, "%d", &a1);
        } else {
          fprintf(f, "%d ", a2);
          // Определяем конец блока
          file2 = end_range(f2);
          fscanf(f2, "%d", &a2);
        }
      }
      // Если закончился второй файл
      while (!file1) {
        fprintf(f, "%d ", a1);
        file1 = end_range(f1);
        fscanf(f1, "%d", &a1);
      }
      // Если закончился первый файл
      while (!file2) {
        fprintf(f, "%d ", a2);
        file2 = end_range(f2);
        fscanf(f2, "%d", &a2);
      }
    }
    // Возвращаем значения
    file1 = file2 = 0;
    // Записываем оставшиеся значения в файлах
    while (!file1 && !feof(f1)) {
      fprintf(f, "%d ", a1);
      file1 = end_range(f1);
      fscanf(f1, "%d", &a1);
    }
    while (!file2 && !feof(f2)) {
      fprintf(f, "%d ", a2);
      file2 = end_range(f2);
      fscanf(f2, "%d", &a2);
    }
    fclose(f2);
    fclose(f1);
    fclose(f);
  }
  remove("f1.txt");
  remove("f2.txt");
}

int main() {
  char arr[20] = "base.txt";
  int size = 20, choice = 0;
  FILE* f = fopen("base.txt", "r");
  system("clear");
  printf("Array: ");
  while (fgets(arr, size, f) != NULL) printf("%s", arr);
  printf("\n");
  fclose(f);
  merge_sort();
  printf("\nSorted Array: ");
  f = fopen("output.txt", "r");
  while (fgets(arr, size, f) != NULL) printf("%s", arr);
  printf("\n");
  fclose(f);
}
