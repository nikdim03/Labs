#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ST {
  char data;
  struct ST* next;
} ST;

ST* create_st(char ch) {
  ST* node = (ST*)malloc(sizeof(ST));
  if (node == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(1);
  }
  node->data = ch;
  node->next = NULL;
  return node;
}
void st_insert_after(char c, ST* cur) {
  ST* node = (ST*)malloc(sizeof(ST));
  if (node == NULL) {
    printf("No data!");
    exit(0);
  }
  node->data = c;
  node->next = cur->next;
  cur->next = node;
}
void st_print_list(ST* head, ST* cur) {
  while (head) {
    if (cur == head) {
      if (head->data == ' ') {
        printf("\033[106m");
        printf("%c", head->data);
        printf("\033[0m");
        head = head->next;
      } else {
        printf("\033[96m");
        printf("%c", head->data);
        printf("\033[0m");
        head = head->next;
      }
    } else {
      printf("%c", head->data);
      head = head->next;
    }
  }
  printf("\n");
}
void free_st(ST* head) {
  while (head) {
    ST* temp = head;
    head = head->next;
    free(temp);
  }
}
ST* st_remove_after(ST* one, ST* two) {
  if (one == NULL) {
    one = two;
    two = two->next;
    free(one);
    return (two);
  } else {
    one->next = two->next;
    free(two);
    return (one);
  }
}

void st_start(bool* sl) {
  if (*sl) {
    printf("You've already started working with the list\n\n");
  } else {
    *sl = true;
    printf("You've started working with the list\n\n");
  }
}
void st_clear(ST** head, ST** cur) {
  if (*head == NULL) {
    printf("The list is empty\n\n");
  } else {
    free_st(*head);
    *head = NULL;
    *cur = NULL;
    printf("You've cleared the list\n\n");
  }
}
bool st_is_empty(ST* head) {
  if (head == NULL) {
    printf("The list is empty\n\n");
    return true;
  } else {
    printf("The list is not empty\n\n");
    return false;
  }
}
void st_set_to_start(ST* head, ST** cur) {
  if (head == NULL) {
    printf("Empty list\n\n");
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
    printf("Empty list\n\n");
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
    printf("Empty list\n\n");
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
    printf("Empty list\n\n");
  } else {
    if (cur->next == NULL) {
      printf("The pointer is in the end\n\n");
    } else {
      printf("The element after the pointer: ");
      printf("%c\n\n", cur->next->data);
    }
  }
}
void st_remove_elem(ST** cur) {
  if (*cur == NULL) {
    printf("Empty list\n\n");
  } else {
    if ((*cur)->next == NULL) {
      printf("The pointer is in the end\n\n");
    } else {
      *cur = st_remove_after(*cur, (*cur)->next);
      printf("You've deleted the character after the pointer\n\n");
    }
  }
}
void st_return_after(ST** cur) {
  if (cur == NULL) {
    printf("Empty list\n\n");
  } else {
    if ((*cur)->next == NULL) {
      printf("The pointer is in the end\n\n");
    } else {
      printf("The character you have entered: ");
      printf("%c\n\n", (*cur)->next->data);
      *cur = st_remove_after(*cur, (*cur)->next);
    }
  }
}
void st_modify_after(ST* head, ST** cur) {
  if (head == NULL) {
    printf("Empty list\n\n");
  } else {
    if ((*cur)->next == NULL) {
      printf("The pointer is in the end\n\n");
    } else {
      char ch;
      printf("\nEnter the character you want to insert instead: ");
      ch = getchar();
      if (ch == '\n') ch = getchar();
      (*cur)->next->data = ch;
      system("clear");
      printf("\nYou've changed the character after the pointer to: %c\n", ch);
    }
  }
}
void st_add_after(ST** head, ST** cur) {
  char ch;
  printf("Enter 1 character: \n\n");
  ch = getchar();
  if (ch == '\n') ch = getchar();
  if (*head == NULL) {
    *head = create_st(ch);
    *cur = *head;
  } else {
    st_insert_after(ch, *cur);
  }
}
void st_stop(ST** head, ST** cur, bool* sl) {
  if (!*sl) {
    printf("You haven't started working with the list yet\n\n");
  } else {
    *sl = 0;
    free_st(*head);
    *head = NULL;
    *cur = NULL;
    printf("\nYou've finished working with the list\n\n");
  }
}
void exit_program(bool sl) {
  if (sl) {
    printf(
        "\nYou can't exit the program yet as you haven't finished "
        "working with the list!\n\n");
  } else {
    system("clear");
    printf("\nYou've successfully exited the program\n\n");
    exit(0);
  }
}

void menu() {
  bool sl = false;
  int int_choice;
  ST* head = NULL;
  ST* cur = NULL;
  do {
    printf("1. Start working with the list\n");
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
    printf("12. Print the list\n");
    printf("13. Stop working with the list\n");
    printf("14. Exit the program\n");
    if (head != NULL) {
      st_print_list(head, cur);
      printf("\n\n");
    }
    scanf("%d", &int_choice);
    system("clear");
    switch (int_choice) {
      case 1:
        st_start(&sl);
        break;
      case 2:
        if (sl)
          st_clear(&head, &cur);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 3:
        if (sl)
          st_is_empty(head);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 4:
        if (sl)
          st_set_to_start(head, &cur);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 5:
        if (sl) {
          st_is_end(cur);
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 6:
        if (sl)
          st_shift_right(&cur);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 7:
        if (sl)
          st_print_after(cur);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 8:
        if (sl)
          st_remove_elem(&cur);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 9:
        if (sl)
          st_return_after(&cur);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 10:
        if (sl)
          st_modify_after(head, &cur);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 11:
        if (sl)
          st_add_after(&head, &cur);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 12:
        if (sl) {
          if (head == NULL)
            printf("Empty list\n\n");
          else
            st_print_list(head, cur);
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 13:
        st_stop(&head, &cur, &sl);
        break;
      case 14:
        exit_program(sl);
        break;
      default:
        printf("Wrong choice. Enter Again.\n\n");
        break;
    }
  } while (int_choice != 99);
}

int main() {
  char char_choice;
  do {
    printf("Do you want to start?[y,n]\n\n");
    scanf("%c", &char_choice);
    system("clear");
    switch (char_choice) {
      case 'y':
        system("clear");
        menu();
        break;
      case 'n':
        system("clear");
        printf("\nYou've successfully exited the program\n\n");
        exit(0);
        break;
      default:
        printf("Wrong choice. Enter Again.\n\n");
        break;
    }
  } while (char_choice != 99);
  return 0;
}