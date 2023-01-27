#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
  int data;
  struct Node *next;
};

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
void append(struct Node **head_ref, int new_data) {
  /* 1. allocate node */
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  if (new_node == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(1);
  }
  struct Node *last = *head_ref; /* used in step 5*/
  /* 2. put in the data  */
  new_node->data = new_data;
  /* 3. This new node is going to be the last node, so make next
        of it as NULL*/
  new_node->next = NULL;
  /* 4. If the Linked List is empty, then make the new node as head */
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  /* 5. Else traverse till the last node */
  while (last->next != NULL) last = last->next;
  /* 6. Change the next of last node */
  last->next = new_node;
  return;
}

/* Given a node prev_node, insert a new node after the given
prev_node */
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

  /* 3. put in the data */
  new_node->data = new_data;
  /* 4. Make next of new node as next of prev_node */
  new_node->next = prev_node->next;
  /* 5. move the next of prev_node as new_node */
  prev_node->next = new_node;
}

void delete_node(struct Node *head, struct Node *to_delete) {
  // When node to be deleted is head node
  if (head == to_delete) {
    /* Copy the data of next node to head */
    head->data = head->next->data;
    // store address of next node
    to_delete = head->next;
    // Remove the link of next node
    head->next = head->next->next;
    // free memory
    free(to_delete);
    return;
  }
  // When not first node, follow the normal deletion process
  // find the previous node
  struct Node *prev = head;
  while (prev->next != NULL && prev->next != to_delete) prev = prev->next;
  // Check if node really exists in Linked List
  if (prev->next == NULL) {
    printf("\n Given node is not present in Linked List");
    return;
  }
  // Remove node from Linked List
  prev->next = prev->next->next;
  // Free memory
  free(to_delete);
  return;
}

/* Function to delete the entire linked list */
void delete_list(struct Node **head_ref) {
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
}

// This function prints contents of linked list starting from head
void print_list(struct Node *node) {
  while (node != NULL) {
    printf("%c", node->data);
    node = node->next;
  }
  printf("\n");
}

int main() {
  unsigned int i, count = 0, len = 0, minLen = 0;
  char ch = 0;
  /* Start with the empty list */
  struct Node *start = (struct Node *)malloc(sizeof(struct Node));
  if (start == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(1);
  }
  struct Node *head = start;
  struct Node *head_for_print = start;
  struct Node *start_copy = start;

  // struct Node head_ref = *head;
  // struct Node *head_ref = head;
  //   input
  while (ch != '\n') {
    ch = getchar();
    if (ch != '\n') {
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

  //   find minLen
  minLen = count;
  while (head != NULL) {
    if (head->data != ' ' && head->data != '\n') {
      len++;
    } else {
      if (len < minLen && len != 0) minLen = len;
      len = 0;
    }
    head = head->next;
  }
  if (len < minLen && len != 0) minLen = len;
  delete_list(&start);
  free(start);
  printf("%d", minLen);
  return 0;
}