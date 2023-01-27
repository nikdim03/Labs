#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};
// добавить в конец
void append(struct Node **head_ref, int new_data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  if (new_node == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(1);
  }
  struct Node *last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  while (last->next != NULL) last = last->next;
  last->next = new_node;
  return;
}

// добавить после (для середины)
void insert_after(struct Node *prev_node, int new_data) {
  if (prev_node == NULL) {
    printf("the given previous node cannot be NULL");
    return;
  }
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  if (new_node == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(1);
  }
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// удалить элемент
void delete_node(struct Node *head, struct Node *to_delete) {
  if (head == to_delete) {
    head->data = head->next->data;
    to_delete = head->next;
    head->next = head->next->next;
    free(to_delete);
    return;
  }
  struct Node *prev = head;
  while (prev->next != NULL && prev->next != to_delete) prev = prev->next;
  if (prev->next == NULL) {
    printf("\n Given node is not present in Linked List");
    return;
  }
  prev->next = prev->next->next;
  free(to_delete);
  return;
}

// удалить лист
void delete_list(struct Node **head_ref) {
  struct Node *current = *head_ref;
  struct Node *next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  *head_ref = NULL;
}

// вывод
void print_list(struct Node *node) {
  while (node != NULL) {
    printf("%c", node->data);
    node = node->next;
  }
  printf("\n");
}

int main() {
  unsigned int i, count = 0, count_spaces = 0, countprint = 0;
  char ch = 0;
  struct Node *start = (struct Node *)malloc(sizeof(struct Node));
  if (start == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(1);
  }
  struct Node *head = start;
  struct Node *head_for_print = start;
  struct Node *start_copy = start;
  struct Node *p1 = start;
  struct Node *p2 = start;
  struct Node *p3 = start;

  while (ch != '\n') {
    ch = getchar();
    if (ch != '\n') {
      if (ch == ' ') count_spaces++;
      append(&head, ch);
      count++;
    }
  }
  for (i = 0; i < count / 2; i++) {
    head_for_print = head_for_print->next;
  }
  printf("\nInput a character to insert in the middle\n");
  ch = getchar();
  count++;
  insert_after(head_for_print, ch);
  head_for_print = start;
  print_list(head_for_print);
  for (i = 0; i <= count / 2; i++) {
    head_for_print = head_for_print->next;
  }
  delete_node(start_copy, head_for_print);
  printf("\n");
  head_for_print = start;
  print_list(head_for_print);

  // обработка
  p1 = p1->next->next;
  p2 = p2->next;
  p3 = p3->next;
  while (p1->data == ' ' && p2->data == ' ') {
    p1 = p1->next;
    p2 = p2->next;
    p3 = p3->next;
  }
  if(p3->data == ' ') {
    p1 = p1->next;
    p2 = p2->next;
    p3 = p3->next;
  }
  while (p1 != NULL) {
    if (p3 != NULL) {
      if (p1->data != ' ') {
        if (p1->data == p2->data) {
          while (p3->data != ' ') {
            printf("%c", p3->data);
            p3 = p3->next;
            countprint++;
            if (p3 == NULL) break;
          }
          if (p3 == NULL) break;
          if (count_spaces > 1) printf(" ");
          if (p3->data == ' ') p3 = p3->next;
          while (p2->data != ' ') {
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == NULL) break;
          }
        } else {
          p1 = p1->next;
          p2 = p2->next;
        }
      } else {
        p1 = p1->next;
        p2 = p2->next;
        while (p3->data != ' ') {
          p3 = p3->next;
          if (p3 == NULL) break;
        }
        p3 = p3->next;
      }
    }
  }
  if(countprint == 0) {
    printf("\nNone");
  }
  delete_list(&start);
  free(start);
  return 0;
}
