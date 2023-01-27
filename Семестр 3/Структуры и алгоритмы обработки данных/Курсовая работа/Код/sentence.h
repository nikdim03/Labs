#ifndef SENTENCE_H_
#define SENTENCE_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Определение структуры элемента предложения
typedef struct st_elem {
  // Данные элемента
  char* data;
  // Указатель на следующий элемент предложения
  struct st_elem* next;
} st_elem;

// Определение структуры последовательности
typedef struct st_set {
  // Указатели на первый и текущий элементы последовательности
  st_elem* head;
  st_elem* cur;
} st_set;

st_set st_menu(st_set* listPointer);
void st_print(st_set collection);
void st_clear(st_set* list);
bool st_is_empty(st_set* list);
bool st_is_end(st_set* list);
void st_to_start(st_set* list);
void st_add_elem(st_set* collection, char* data);
void st_shift_forward(st_set* list);
void st_print_next(st_set* list);
void st_change_next(st_set* list, char* data);
void st_delete_next(st_set* list);
char* str_input();

#endif  // SENTENCE_H_