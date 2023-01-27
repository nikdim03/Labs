#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char data;
  struct Node* next;
} Node;

Node* create_node(char ch) {
  Node* node = (Node*)malloc(sizeof(Node));
  if (node == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(1);
  }
  node->data = ch;
  node->next = NULL;
  return node;
}
void insert_after(char c, Node* cur) {
  Node* node = (Node*)malloc(sizeof(Node));
  if (node == NULL) {
    printf("No data!");
    exit(0);
  }
  node->data = c;
  node->next = cur->next;
  cur->next = node;
}
void print_list(Node* head, Node* cur) {
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
void free_list(Node* head) {
  while (head) {
    Node* temp = head;
    head = head->next;
    free(temp);
  }
}
Node* remove_after(Node* one, Node* two) {
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

void start(bool* sl) {
  if (*sl) {
    printf("You've already started working with the list\n\n");
  } else {
    *sl = true;
    printf("You've started working with the list\n\n");
  }
}
void clear(Node** head, Node** cur) {
  if (*head == NULL) {
    printf("The list is empty\n\n");
  } else {
    free_list(*head);
    *head = NULL;
    *cur = NULL;
    printf("You've cleared the list\n\n");
  }
}
bool is_empty(Node* head) {
  if (head == NULL) {
    printf("The list is empty\n\n");
    return true;
  } else {
    printf("The list is not empty\n\n");
    return false;
  }
}
void set_to_start(Node* head, Node** cur) {
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
bool is_end(Node* cur) {
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
void shift_right(Node** cur) {
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
void print_after(Node* cur) {
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
void remove_elem(Node** cur) {
  if (*cur == NULL) {
    printf("Empty list\n\n");
  } else {
    if ((*cur)->next == NULL) {
      printf("The pointer is in the end\n\n");
    } else {
      *cur = remove_after(*cur, (*cur)->next);
      printf("You've deleted the character after the pointer\n\n");
    }
  }
}
void return_after(Node** cur) {
  if (cur == NULL) {
    printf("Empty list\n\n");
  } else {
    if ((*cur)->next == NULL) {
      printf("The pointer is in the end\n\n");
    } else {
      printf("The character you have entered: ");
      printf("%c\n\n", (*cur)->next->data);
      *cur = remove_after(*cur, (*cur)->next);
    }
  }
}
void modify_after(Node* head, Node** cur) {
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
void add_after(Node** head, Node** cur) {
  char ch;
  printf("Enter 1 character: \n\n");
  ch = getchar();
  if (ch == '\n') ch = getchar();
  if (*head == NULL) {
    *head = create_node(ch);
    *cur = *head;
  } else {
    insert_after(ch, *cur);
  }
}
void stop(Node** head, Node** cur, bool* sl) {
  if (!*sl) {
    printf("You haven't started working with the list yet\n\n");
  } else {
    *sl = 0;
    free_list(*head);
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
  Node* head = NULL;
  Node* cur = NULL;
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
      print_list(head, cur);
      printf("\n\n");
    }
    scanf("%d", &int_choice);
    system("clear");
    switch (int_choice) {
      case 1:
        start(&sl);
        break;
      case 2:
        if (sl)
          clear(&head, &cur);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 3:
        if (sl)
          is_empty(head);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 4:
        if (sl)
          set_to_start(head, &cur);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 5:
        if (sl) {
          is_end(cur);
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 6:
        if (sl)
          shift_right(&cur);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 7:
        if (sl)
          print_after(cur);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 8:
        if (sl)
          remove_elem(&cur);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 9:
        if (sl)
          return_after(&cur);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 10:
        if (sl)
          modify_after(head, &cur);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 11:
        if (sl)
          add_after(&head, &cur);
        else
          printf("You haven't started working with the list yet\n\n");
        break;
      case 12:
        if (sl) {
          if (head == NULL)
            printf("Empty list\n\n");
          else
            print_list(head, cur);
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 13:
        stop(&head, &cur, &sl);
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