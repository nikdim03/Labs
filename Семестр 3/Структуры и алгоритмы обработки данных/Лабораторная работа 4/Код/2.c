#include <stdio.h>
#include <stdlib.h>

// Node of a doubly linked list
struct Node {
  int data;
  // Pointer to next node in DLL
  struct Node *next;
  // Pointer to previous node in DLL
  struct Node *prev;
};

/* Given a reference (pointer to pointer) to the head of a DLL and an int,
 * appends a new node at the end  */
void append(struct Node **head_ref, int new_data, struct Node **end) {
  /* 1. allocate node */
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  if (new_node == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(1);
  }
  struct Node *last = *head_ref; /* used in step 5*/
  /* 2. put in the data  */
  new_node->data = new_data;
  /* 3. This new node is going to be the last node, so make next of it as NULL*/
  new_node->next = NULL;
  /* 4. If the Linked List is empty, then make the new node as head */
  if (*head_ref == NULL) {
    new_node->prev = NULL;
    *head_ref = new_node;
    return;
  }
  /* 5. Else traverse till the last node */
  while (last->next != NULL) last = last->next;
  /* 6. Change the next of last node */
  last->next = new_node;
  /* 7. Make last node as previous of new node */
  new_node->prev = last;
  *end = new_node;
  return;
}
/* Given a node as prev_node, insert a new node after the

 * given node */

void insert_after(struct Node *prev_node, int new_data) {
  /*1. check if the given prev_node is NULL */
  if (prev_node == NULL) {
    printf("the given previous node cannot be NULL");
    return;
  }
  /* 2. allocate new node */
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  if (new_node == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(1);
  }
  /* 3. put in the data  */
  new_node->data = new_data;
  /* 4. Make next of new node as next of prev_node */
  new_node->next = prev_node->next;
  /* 5. Make the next of prev_node as new_node */
  prev_node->next = new_node;
  /* 6. Make prev_node as previous of new_node */
  new_node->prev = prev_node;
  /* 7. Change previous of new_node's next node */
  if (new_node->next != NULL) new_node->next->prev = new_node;
}

/* Function to delete a node in a Doubly Linked List.
   head_ref --> pointer to head node pointer.
   del  -->  pointer to node to be deleted. */
void delete_node(struct Node **head_ref, struct Node *del) {
  /* base case */
  if (*head_ref == NULL || del == NULL) return;
  /* If node to be deleted is head node */
  if (*head_ref == del) *head_ref = del->next;
  /* Change next only if node to be deleted is NOT the last node */
  if (del->next != NULL) del->next->prev = del->prev;
  /* Change prev only if node to be deleted is NOT the first node */
  if (del->prev != NULL) del->prev->next = del->next;
  /* Finally, free the memory occupied by del*/
  free(del);
  return;
}

/* Function to delete the entire linked list */
void delete_list(struct Node **head_ref, struct Node **start,
                 struct Node **end) {
  /* deref head_ref to get the real head */
  struct Node *current = *head_ref;
  struct Node *next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  /* deref head_ref to affect the real head back in the caller. */
  *head_ref = NULL;
  free(*start);
  *end = NULL;
}

// This function prints contents of linked list starting from the given node
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
}

int main() {
  unsigned int i, count = 0, len = 0, minLen = 0;
  char ch = 0;
  /* Start with the empty list */
  struct Node *start = (struct Node *)malloc(sizeof(struct Node));
  struct Node *end = start;

  if (start == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(1);
  }
  struct Node *head = start;
  struct Node *head_for_print = start;
  struct Node *start_copy = start;
  //   input
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

  //   find minLen
  minLen = count;
  while (head != NULL) {
    // printf("%d ", head_ref->data);
    if (head->data != ' ' && head->data != '\n') {
      len++;
    } else {
      if (len < minLen && len != 0) minLen = len;
      len = 0;
    }
    head = head->next;
  }
  if (len < minLen && len != 0) minLen = len;
  delete_list(&start, &start, &end);
  printf("\n%d", minLen);
  return 0;
}