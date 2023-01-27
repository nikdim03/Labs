#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include "deque.h"

// Определение структуры элемента последовательности
typedef struct sq_elem {
  // Данные элемента
  dq_set data;
  // Указатель на следующий элемент последовательности
  struct sq_elem* next;
} sq_elem;

// Определение структуры последовательности
typedef struct sq_set {
  // Указатели на первый, последний и текущий элементы последовательности
  sq_elem *head, *tail;
  sq_elem* cur;
} sq_set;

void sq_menu(sq_set sequence);
void sq_print(sq_set* sequence);
void sq_clear(sq_set* sequence);
sq_set sq_init();
bool sq_is_empty(sq_set* sequence);
bool sq_is_end(sq_set* sequence);
void sq_to_start(sq_set* sequence);
void sq_add_elem(sq_set* collection);
void sq_shift_forward(sq_set* sequence);
void sq_print_cur(sq_set* sequence);
void sq_change_cur(sq_set* sequence);
void sq_remove_cur(sq_set* sequence);
size_t sq_size(sq_set* sequence);

#endif  // SEQUENCE_H_