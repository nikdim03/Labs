#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

//добавить в конец
void append(struct Node **head_ref, int new_data, struct Node **end) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  if (new_node == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(1);
  }
  struct Node *last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL) {
    new_node->prev = NULL;
    *head_ref = new_node;
    return;
  }
  while (last->next != NULL) last = last->next;
  last->next = new_node;
  new_node->prev = last;
  *end = new_node;
  return;
}
//добавить после (для середины)
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
  new_node->prev = prev_node;
  if (new_node->next != NULL) new_node->next->prev = new_node;
}

//удалить элемент
void delete_node(struct Node **head_ref, struct Node *del) {
  if (*head_ref == NULL || del == NULL) return;
  if (*head_ref == del) *head_ref = del->next;
  if (del->next != NULL) del->next->prev = del->prev;
  if (del->prev != NULL) del->prev->next = del->next;
  free(del);
  return;
}

//удалить лист
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

//вывод
void print_list(struct Node *node) {
  struct Node *last;
  printf("\nTraversal in forward direction \n");
  while (node != NULL) {
    printf("%c", node->data);
    last = node;
    node = node->next;
  }
  printf("\nTraversal in reverse direction \n");
  while (last != NULL) {
    printf("%c", last->data);
    last = last->prev;
  }
  printf("\n");
}

int main() {
  unsigned int i, count = 0;
  char ch = 0;
  struct Node *start = (struct Node *)malloc(sizeof(struct Node));
  struct Node *end = start;
  if (start == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(1);
  }
  struct Node *head = start;
  struct Node *head_for_print = start;
  struct Node *start_copy = start;

  while (ch != '\n') {
    ch = getchar();
    if (ch != '\n') {
      append(&head, ch, &end);
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
  delete_node(&start_copy, head_for_print);
  printf("\n");
  head_for_print = start;
  print_list(head_for_print);
  printf("\n");
  struct Node *head0 = start->next;
  head = start->next->next;
  while (head != NULL) {
    if (head0->data == head->data) {
      while (head0->data != ' ' && head0 != start) {
        head0 = head0->prev;
      }
      head0 = head0->next;
      while (head0->data != ' ' && head0->data != '\n') {
        printf("%c", head0->data);
        head0 = head0->next;
        if (head0 == NULL) break;
      }
      if (head0 == NULL)
        break;
      else
        printf(" ");
      while (head != head0->next) {
        head = head->next;
      }
    }
    head = head->next;
    head0 = head0->next;
  }
  delete_list(&start);
  free(start);
  end = NULL;
  return 0;
}
