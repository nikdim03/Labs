#ifndef DEQUE_H_
#define DEQUE_H_

#include "sentence.h"

// Определение структуры элемента дека
typedef struct dq_elem {
  // Данные элемента
  st_set data;
  // Указатели на следующий и предыдущий элементы дека
  struct dq_elem *next, *prev;
} dq_elem;

// Определение структуры дека
typedef struct dq_set {
  // Указатели на первый, последний и текущий элементы дека
  dq_elem *head, *tail;
  // Глубина дека
  size_t depth;
} dq_set;

dq_set dq_menu(dq_set* dq_ptr);
void dq_get_depth(dq_set* deque);
size_t dq_size(dq_set* deque);
void dq_print(dq_set* deque);
void dq_clear(dq_set* deque);
bool dq_is_empty(dq_set* deque);
void dq_print_first(dq_set* deque);
void dq_print_last(dq_set* deque);
void dq_pop_front(dq_set* deque);
void dq_pop_back(dq_set* deque);
void dq_push_front(dq_set* deque);
void dq_push_back(dq_set* deque);
void dq_change_first(dq_set* deque);
void dq_change_last(dq_set* deque);

#endif  // DEQUE_H_