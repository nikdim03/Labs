#include "curs.h"

int main() {
  char choice;
  system("clear");
  do {
    printf("Do you want to start?[y,n]\n\n");
    scanf("%c", &choice);
    system("clear");
    switch (choice) {
      case 'y':
        system("clear");
        st_menu();
        break;
      case 'n':
        system("clear");
        printf("You've successfully exited the program\n\n");
        exit(0);
        break;
      default:
        system("clear");
        printf("Wrong choice. Enter Again.\n\n");
        break;
    }
  } while (choice != 99);
  return 0;
}

//-------------------------------------------DEQUE-------------------------------------------------
void dq_menu() {
  int data, ch;
  dq_init();
  system("clear");
  while (1) {
    printf("\t\t\t\tDEQUE MENU\n");
    printf("1. Insert at front\n2. Insert at rear\n");
    printf("3. Remove at front\n4. Remove at rear\n");
    printf("5. Display\n6. Exit\n");
    printf("Your choice: ");
    scanf("%d", &ch);
    switch (ch) {
      case 1:
        printf("Data to insert: ");
        scanf("%d", &data);
        dq_push_front(data);
        system("clear");
        break;
      case 2:
        printf("Data to insert: ");
        scanf("%d", &data);
        dq_push_back(data);
        system("clear");
        break;
      case 3:
        dq_pop_front();
        system("clear");
        break;
      case 4:
        dq_pop_back();
        system("clear");
        break;
      case 5:
        system("clear");
        dq_display();
        break;
      case 6:
        dq_deinit();
        exit(0);
      default:
        system("clear");
        printf("Wrong input! Try again.\n");
        break;
    }
  }
}

DQ* create_dq(int data) {
  DQ* newnode = (DQ*)malloc(sizeof(DQ));
  newnode->data = data;
  newnode->next = newnode->prev = NULL;
  return newnode;
}

void dq_init() {
  dq_head = create_dq(0);
  dq_tail = create_dq(0);
  dq_head->next = dq_tail;
  dq_tail->prev = dq_head;
}

void dq_deinit() {
  free(dq_head);
  free(dq_tail);
}

void dq_push_front(int data) {
  DQ *newnode, *temp;
  newnode = create_dq(data);
  temp = dq_head->next;
  dq_head->next = newnode;
  newnode->prev = dq_head;
  newnode->next = temp;
  temp->prev = newnode;
}

void dq_push_back(int data) {
  DQ *newnode, *temp;
  newnode = create_dq(data);
  temp = dq_tail->prev;
  dq_tail->prev = newnode;
  newnode->next = dq_tail;
  newnode->prev = temp;
  temp->next = newnode;
}

void dq_pop_front() {
  DQ* temp;
  if (dq_head->next == dq_tail) {
    printf("Queue is empty\n");
  } else {
    temp = dq_head->next;
    dq_head->next = temp->next;
    temp->next->prev = dq_head;
    free(temp);
  }
  return;
}

void dq_pop_back() {
  struct DQ* temp;
  if (dq_tail->prev == dq_head) {
    printf("Queue is empty\n");
  } else {
    temp = dq_tail->prev;
    dq_tail->prev = temp->prev;
    temp->prev->next = dq_tail;
    free(temp);
  }
  return;
}

void dq_display() {
  DQ* temp;
  if (dq_head->next == dq_tail) {
    printf("Queue is empty\n");
    return;
  }
  temp = dq_head->next;
  while (temp != dq_tail) {
    printf("%-3d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

//-------------------------------------------SEQUENCE----------------------------------------------
void sq_menu() {
  bool s_sq = false;  // started working with sequence
  int choice;
  SQ* head = NULL;
  SQ* cur = NULL;
  system("clear");
  do {
    printf("\t\t\tSEQUENCE MENU\n");
    printf("1. Start working with the sequence\n");
    printf("2. Clear\n");
    printf("3. Check if empty\n");
    printf("4. Set pointer to start\n");
    printf("5. Check if pointer in the end\n");
    printf("6. Shift pointer to the right\n");
    printf("7. Print after pointer\n");
    printf("8. Remove after pointer\n");
    printf("9. Return after pointer\n");
    printf("10. Modify after pointer\n");
    printf("11. Add after pointer\n");
    printf("12. Print the sequence\n");
    printf("13. Stop working with the sequence\n");
    printf("14. Exit the program\n");
    if (head != NULL) {
      print_sq(head, cur);
      printf("\n\n");
    }
    scanf("%d", &choice);
    system("clear");
    switch (choice) {
      case 1:
        sq_start(&s_sq);
        break;
      case 2:
        if (s_sq)
          sq_clear(&head, &cur);
        else
          printf("You haven't started working with the sequence yet\n\n");
        break;
      case 3:
        if (s_sq)
          sq_is_empty(head);
        else
          printf("You haven't started working with the sequence yet\n\n");
        break;
      case 4:
        if (s_sq)
          sq_set_to_start(head, &cur);
        else
          printf("You haven't started working with the sequence yet\n\n");
        break;
      case 5:
        if (s_sq) {
          sq_is_end(cur);
        } else {
          printf("You haven't started working with the sequence yet\n\n");
        }
        break;
      case 6:
        if (s_sq)
          sq_shift_forward(&cur);
        else
          printf("You haven't started working with the sequence yet\n\n");
        break;
      case 7:
        if (s_sq)
          sq_print_after(cur);
        else
          printf("You haven't started working with the sequence yet\n\n");
        break;
      case 8:
        if (s_sq)
          sq_remove_elem(&cur);
        else
          printf("You haven't started working with the sequence yet\n\n");
        break;
      case 9:
        if (s_sq)
          sq_return_after(&cur);
        else
          printf("You haven't started working with the sequence yet\n\n");
        break;
      case 10:
        if (s_sq)
          sq_modify_after(head, &cur);
        else
          printf("You haven't started working with the sequence yet\n\n");
        break;
      case 11:
        if (s_sq)
          sq_add_after(&head, &cur);
        else
          printf("You haven't started working with the sequence yet\n\n");
        break;
      case 12:
        if (s_sq) {
          if (head == NULL)
            printf("Empty sequence\n\n");
          else
            print_sq(head, cur);
        } else {
          printf("You haven't started working with the sequence yet\n\n");
        }
        break;
      case 13:
        sq_stop(&head, &cur, &s_sq);
        break;
      case 14:
        exit_program(s_sq);
        break;
      default:
        printf("Wrong choice. Enter Again.\n\n");
        break;
    }
  } while (choice != 99);
}

void free_sq(SQ* head) {
  while (head) {
    SQ* temp = head;
    head = head->next;
    free(temp);
    // free_dq
  }
}

SQ* sq_remove_after(SQ* one, SQ* two) {
  if (one == NULL) {
    one = two;
    two = two->next;
    free(one);
    // free_dq
    return two;
  } else {
    one->next = two->next;
    free(two);
    // free_dq
    return one;
  }
}

SQ* create_sq() {
  SQ* node = (SQ*)malloc(sizeof(SQ));
  if (node == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(1);
  }
  node->data = create_dq(0);
  node->next = NULL;
  return node;
}

void print_sq(SQ* head, SQ* cur) {
  while (head) {
    if (cur == head) {
      printf("\033[96m[dq]");
      printf("\033[0m");
      head = head->next;
    } else {
      printf("[dq]");
      head = head->next;
    }
  }
  printf("\n");
}

void sq_start(bool* s_sq) {
  if (*s_sq) {
    printf("You've already started working with the sequence\n\n");
  } else {
    *s_sq = true;
    printf("You've started working with the sequence\n\n");
  }
}

void sq_clear(SQ** head, SQ** cur) {
  if (*head == NULL) {
    printf("The sequence is empty\n\n");
  } else {
    free_sq(*head);
    *head = NULL;
    *cur = NULL;
    printf("You've cleared the sequence\n\n");
  }
}

bool sq_is_empty(SQ* head) {
  if (head == NULL) {
    printf("The sequence is empty\n\n");
    return true;
  } else {
    printf("The sequence is not empty\n\n");
    return false;
  }
}

void sq_set_to_start(SQ* head, SQ** cur) {
  if (head == NULL) {
    printf("Empty sequence\n\n");
  } else {
    if (*cur == head) {
      printf("The pointer is already in the starting position\n\n");
    } else {
      *cur = head;
      printf("You set the pointer to starting position\n\n");
    }
  }
}

bool sq_is_end(SQ* cur) {
  if (cur == NULL) {
    printf("Empty sequence\n\n");
    return true;
  } else {
    if (cur->next == NULL) {
      printf("The pointer is in the end\n\n");
      return true;
    } else {
      printf("The pointer is not in the end\n\n");
      return false;
    }
  }
}

void sq_shift_forward(SQ** cur) {
  if (*cur == NULL) {
    printf("Empty sequence\n\n");
  } else {
    if ((*cur)->next == NULL) {
      printf("The pointer is in the end\n\n");
    } else {
      printf("You shifted the pointer to the right\n\n");
      *cur = (*cur)->next;
    }
  }
}

void sq_print_after(SQ* cur) {
  if (cur == NULL) {
    printf("Empty sequence\n\n");
  } else {
    if (cur->next == NULL)
      printf("The pointer is in the end\n\n");
    else
      //   printf("The element after the pointer: %c\n\n", cur->next->data);
      printf("The element after the pointer: dq\n\n");  // print_dq
  }
}

void sq_remove_elem(SQ** cur) {
  if (*cur == NULL) {
    printf("Empty sequence\n\n");
  } else {
    if ((*cur)->next == NULL) {
      printf("The pointer is in the end\n\n");
    } else {
      *cur = sq_remove_after(*cur, (*cur)->next);
      // remove_dq
      printf("You removed the deque after the pointer\n\n");
    }
  }
}

void sq_return_after(SQ** cur) {
  if (cur == NULL) {
    printf("Empty sequence\n\n");
  } else {
    if ((*cur)->next == NULL) {
      printf("The pointer is in the end\n\n");
    } else {
      //   printf("Character: %c\n\n", (*cur)->next->data);
      printf("Element: dq\n\n");  // print_dq
      *cur = sq_remove_after(*cur, (*cur)->next);
    }
  }
}

void sq_modify_after(SQ* head, SQ** cur) {
  if (head == NULL) {
    printf("Empty sequence\n\n");
  } else {
    if ((*cur)->next == NULL) {
      printf("The pointer is in the end\n\n");
    } else {
      //   dq_menu(1, cur);
      dq_menu();
      system("clear");
      printf(
          "\nYou've changed the sequence after the pointer to: dq\n");  // print_dq
    }
  }
}

void sq_add_after(SQ** head, SQ** cur) {
  if (*head == NULL) {
    *head = create_sq();
    *cur = *head;
  } else {
    SQ* node = (SQ*)malloc(sizeof(SQ));
    if (node == NULL) {
      printf("ERROR ALLOCATING MEMORY");
      exit(1);
    }
    // dq_menu(2, &node);  // node->data = c;
    dq_menu();
    node->next = (*cur)->next;
    (*cur)->next = node;
  }
}

void sq_stop(SQ** head, SQ** cur, bool* s_sq) {
  if (!*s_sq) {
    printf("You haven't started working with the sequence yet\n\n");
  } else {
    *s_sq = false;
    free_sq(*head);
    *head = NULL;
    *cur = NULL;
    printf("\nYou've finished working with the sequence\n\n");
  }
}

//-------------------------------------------SENTENCE----------------------------------------------
void st_menu() {
  bool s_st = false;  // started working with sentence
  int choice;
  ST* head = NULL;
  ST* cur = NULL;
  system("clear");
  do {
    printf("\t\t\tSENTENCE MENU\n");
    printf("1. Start working with the sentence\n");
    printf("2. Clear\n");
    printf("3. Check if empty\n");
    printf("4. Set pointer to start\n");
    printf("5. Check if pointer in the end\n");
    printf("6. Shift pointer to the right\n");
    printf("7. Print after pointer\n");
    printf("8. Remove after pointer\n");
    printf("9. Return after pointer\n");
    printf("10. Modify after pointer\n");
    printf("11. Add after pointer\n");
    printf("12. Print the sentence\n");
    printf("13. Stop working with the sentence\n");
    printf("14. Exit the program\n");
    if (head != NULL) {
      print_st(head, cur);
      printf("\n\n");
    }
    scanf("%d", &choice);
    system("clear");
    switch (choice) {
      case 1:
        st_start(&s_st);
        break;
      case 2:
        if (s_st)
          st_clear(&head, &cur);
        else
          printf("You haven't started working with the sentence yet\n\n");
        break;
      case 3:
        if (s_st)
          st_is_empty(head);
        else
          printf("You haven't started working with the sentence yet\n\n");
        break;
      case 4:
        if (s_st)
          st_set_to_start(head, &cur);
        else
          printf("You haven't started working with the sentence yet\n\n");
        break;
      case 5:
        if (s_st) {
          st_is_end(cur);
        } else {
          printf("You haven't started working with the sentence yet\n\n");
        }
        break;
      case 6:
        if (s_st)
          st_shift_right(&cur);
        else
          printf("You haven't started working with the sentence yet\n\n");
        break;
      case 7:
        if (s_st)
          st_print_after(cur);
        else
          printf("You haven't started working with the sentence yet\n\n");
        break;
      case 8:
        if (s_st)
          st_remove_elem(&cur);
        else
          printf("You haven't started working with the sentence yet\n\n");
        break;
      case 9:
        if (s_st)
          st_return_after(&cur);
        else
          printf("You haven't started working with the sentence yet\n\n");
        break;
      case 10:
        if (s_st)
          st_modify_after(head, &cur);
        else
          printf("You haven't started working with the sentence yet\n\n");
        break;
      case 11:
        if (s_st)
          st_add_after(&head, &cur);
        else
          printf("You haven't started working with the sentence yet\n\n");
        break;
      case 12:
        if (s_st) {
          if (head == NULL)
            printf("Empty sentence\n\n");
          else
            print_st(head, cur);
        } else {
          printf("You haven't started working with the sentence yet\n\n");
        }
        break;
      case 13:
        st_stop(&head, &cur, &s_st);
        break;
      case 14:
        exit_program(s_st);
        break;
      default:
        printf("Wrong choice. Enter Again.\n\n");
        break;
    }
  } while (choice != 99);
}

void free_st(ST* head) {
  while (head) {
    ST* temp = head;
    head = head->next;
    free(temp);
    // free_sq
  }
}

ST* st_remove_after(ST* one, ST* two) {
  if (one == NULL) {
    one = two;
    two = two->next;
    free(one);
    // free_sq
    return two;
  } else {
    one->next = two->next;
    free(two);
    // free_sq
    return one;
  }
}

ST* create_st() {
  ST* node = (ST*)malloc(sizeof(ST));
  if (node == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(1);
  }
  node->data = create_sq();
  node->next = NULL;
  return node;
}

void print_st(ST* head, ST* cur) {
  while (head) {
    if (cur == head) {
      printf("\033[96m[sq]");
      printf("\033[0m");
      head = head->next;
    } else {
      printf("[sq]");
      head = head->next;
    }
  }
  printf("\n");
}

void st_start(bool* s_st) {
  if (*s_st) {
    printf("You've already started working with the sentence\n\n");
  } else {
    *s_st = true;
    printf("You've started working with the sentence\n\n");
  }
}

void st_clear(ST** head, ST** cur) {
  if (*head == NULL) {
    printf("The sentence is empty\n\n");
  } else {
    free_st(*head);
    *head = NULL;
    *cur = NULL;
    printf("You've cleared the sentence\n\n");
  }
}

bool st_is_empty(ST* head) {
  if (head == NULL) {
    printf("The sentence is empty\n\n");
    return true;
  } else {
    printf("The sentence is not empty\n\n");
    return false;
  }
}

void st_set_to_start(ST* head, ST** cur) {
  if (head == NULL) {
    printf("Empty sentence\n\n");
  } else {
    if (*cur == head) {
      printf("The pointer is already in the starting position\n\n");
    } else {
      *cur = head;
      printf("You set the pointer to starting position\n\n");
    }
  }
}

bool st_is_end(ST* cur) {
  if (cur == NULL) {
    printf("Empty sentence\n\n");
    return true;
  } else {
    if (cur->next == NULL) {
      printf("The pointer is in the end\n\n");
      return true;
    } else {
      printf("The pointer is not in the end\n\n");
      return false;
    }
  }
}

void st_shift_right(ST** cur) {
  if (*cur == NULL) {
    printf("Empty sentence\n\n");
  } else {
    if ((*cur)->next == NULL) {
      printf("The pointer is in the end\n\n");
    } else {
      printf("You shifted the pointer to the right\n\n");
      *cur = (*cur)->next;
    }
  }
}

void st_print_after(ST* cur) {
  if (cur == NULL) {
    printf("Empty sentence\n\n");
  } else {
    if (cur->next == NULL)
      printf("The pointer is in the end\n\n");
    else
      //   printf("The element after the pointer: %c\n\n", cur->next->data);
      sq_menu();
    //   printf("The element after the pointer: sq\n\n");  // print_sq
  }
}

void st_remove_elem(ST** cur) {
  if (*cur == NULL) {
    printf("Empty sentence\n\n");
  } else {
    if ((*cur)->next == NULL) {
      printf("The pointer is in the end\n\n");
    } else {
      *cur = st_remove_after(*cur, (*cur)->next);
      // remove_sq
      printf("You removed the sequence after the pointer\n\n");
    }
  }
}

void st_return_after(ST** cur) {
  if (cur == NULL) {
    printf("Empty sentence\n\n");
  } else {
    if ((*cur)->next == NULL) {
      printf("The pointer is in the end\n\n");
    } else {
      //   printf("Character: %c\n\n", (*cur)->next->data);
      printf("Element: sq\n\n");  // print_sq
      *cur = st_remove_after(*cur, (*cur)->next);
    }
  }
}

void st_modify_after(ST* head, ST** cur) {
  if (head == NULL) {
    printf("Empty sentence\n\n");
  } else {
    if ((*cur)->next == NULL) {
      printf("The pointer is in the end\n\n");
    } else {
      //   sq_menu(1, cur);
      sq_menu();
      system("clear");
      printf(
          "\nYou've changed the sequence after the pointer to: sq\n");  // print_sq
    }
  }
}

void st_add_after(ST** head, ST** cur) {
  if (*head == NULL) {
    *head = create_st();
    *cur = *head;
  } else {
    ST* node = (ST*)malloc(sizeof(ST));
    if (node == NULL) {
      printf("ERROR ALLOCATING MEMORY");
      exit(1);
    }
    // sq_menu(2, &node);  // node->data = c;
    sq_menu();
    node->next = (*cur)->next;
    (*cur)->next = node;
  }
}

void st_stop(ST** head, ST** cur, bool* s_st) {
  if (!*s_st) {
    printf("You haven't started working with the sentence yet\n\n");
  } else {
    *s_st = false;
    free_st(*head);
    *head = NULL;
    *cur = NULL;
    printf("\nYou've finished working with the sentence\n\n");
  }
}

void exit_program(bool sf) {
  if (sf) {
    printf(
        "\nYou can't exit the program yet as you haven't finished "
        "working with the some structure!\n\n");
  } else {
    system("clear");
    printf("\nYou've successfully exited the program\n\n");
    exit(0);
  }
}
