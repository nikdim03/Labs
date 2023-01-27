#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ST {
  char data;
  struct ST* next;
  struct ST* prev;
} ST;

void free_st(ST* head) {
  while (head) {
    ST* temp = head;
    head = head->next;
    free(temp);
  }
  free(head);
}

void remove_element_after(ST* cur, ST* next) {
  if (next->next == NULL) {
    cur->next = NULL;
    free(next);
  } else {
    cur->next = next->next;
    next->next->prev = cur;
    free(next);
  }
}

void remove_element_before(ST* cur, ST* prev) {
  if (prev->prev == NULL) {
    cur->prev = NULL;
    free(prev);
  } else {
    cur->prev = prev->prev;
    prev->prev->next = cur;
    free(prev);
  }
}

ST* create_node(char c) {
  ST* node = (ST*)malloc(sizeof(ST));
  if (node == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(1);
  }
  node->data = c;
  node->next = NULL;
  node->prev = NULL;
  return node;
}
void insert_after(char c, ST* cur, ST* end) {
  ST* node = (ST*)malloc(sizeof(ST));
  if (node == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(1);
  }
  node->data = c;
  node->prev = cur;
  node->next = cur->next;
  cur->next = node;
  if (node->next) node->next->prev = node;
}
void insert_before(char c, ST* cur, ST* head) {
  ST* node = (ST*)malloc(sizeof(ST));
  if (node == NULL) {
    printf("ERROR ALLOCATING MEMORY");
    exit(0);
  }
  node->data = c;
  node->next = cur;
  node->prev = cur->prev;
  cur->prev = node;
  if (node->prev) node->prev->next = node;
  if (node->prev == NULL) head = node;
}
void print_list_begin(ST* head, ST* cur) {
  while (head) {
    if (cur == head) {
      if (head->data == ' ') {
        printf("\033[3;45;32m");
        printf("%c", head->data);
        printf("\033[0m");
        head = head->next;
      } else {
        printf("\033[36m\033[1m");
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
void print_list_end(ST* end, ST* cur) {
  while (end) {
    if (cur == end) {
      if (end->data == ' ') {
        printf("\033[3;45;30m");
        printf("%c", end->data);
        printf("\033[0m");
        end = end->prev;
      } else {
        printf("\033[35m\033[1m");
        printf("%c", end->data);
        printf("\033[0m");
        end = end->prev;
      }
    } else {
      printf("%c", end->data);
      end = end->prev;
    }
  }
  printf("\n");
}

void menu() {
  int int_choice, sl = 0;
  ST* head = NULL;
  ST* cur = NULL;
  ST* end = NULL;
  while (true) {
    if (head != NULL) {
      printf("\n");
      print_list_begin(head, cur);
      printf("\n");
      print_list_end(end, cur);
      printf("\n");
    }
    printf("1. Start working with the list\n");
    printf("2. Clear\n");
    printf("3. Check if empty\n");
    printf("4. Set pointer to start\n");
    printf("5. Set pointer to end\n");
    printf("6. Check if pointer in the end\n");
    printf("7. Check if pointer in the start\n");
    printf("8. Shift pointer to the right\n");
    printf("9. Shift pointer to the left\n");
    printf("10. Print after pointer\n");
    printf("11. Print before pointer\n");
    printf("12. Remove after pointer\n");
    printf("13. Remove before pointer\n");
    printf("14. Return after pointer\n");
    printf("15. Return before pointer\n");
    printf("16. Modify before pointer\n");
    printf("17. Modify after pointer\n");
    printf("18. Add before pointer\n");
    printf("19. Add after pointer\n");
    printf("20. Print the list\n");
    printf("21. Stop working with the list\n");
    printf("22. Exit the program\n");
    scanf("%d", &int_choice);
    system("clear");
    switch (int_choice) {
      case 1:
        if (sl) {
          printf("\nYou've already started working with the list\n\n");
        } else {
          sl = 1;
          printf("\nYou've started working with the list\n\n");
        }
        break;
      case 2:
        if (sl) {
          if (head == NULL) {
            printf("\nThe list is empty\n\n");
          } else {
            free_st(head);
            cur = NULL;
            end = NULL;
            head = NULL;
            printf("\nYou've cleared the list\n\n");
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 3:
        if (sl) {
          if (head == NULL) {
            printf("\nThe list is empty\n\n");
          } else {
            printf("\nThe list is not empty\n");
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 4:
        if (sl) {
          if (head == NULL) {
            printf("\nEmpty list\n\n");
          } else {
            if (cur == head) {
              printf("\nThe pointer is already in the starting position\n");
            } else {
              cur = head;
              printf("\nYou set the pointer to starting position\n");
            }
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 5:
        if (sl) {
          if (head == NULL) {
            printf("\nEmpty list\n\n");
          } else {
            if (cur == end) {
              printf("\nThe pointer is already in the end\n");
            } else {
              cur = end;
              printf("\nYou set the pointer to the ending position\n");
            }
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 6:
        if (sl) {
          if (cur == NULL) {
            printf("\nEmpty list\n\n");
          } else {
            if (cur->next == NULL) {
              printf("\nThe pointer is in the end\n");
            } else {
              printf("\nThe pointer is not in the end\n");
            }
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 7:
        if (sl) {
          if (cur == NULL) {
            printf("\nEmpty list\n\n");
          } else {
            if (cur->prev == NULL) {
              printf("\nThe pointer is in the start\n");
            } else {
              printf("\nThe pointer is not in the start\n");
            }
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 8:
        if (sl) {
          if (cur == NULL) {
            printf("\nEmpty list\n\n");
          } else {
            if (cur->next == NULL) {
              printf("\nThe pointer is in the end\n");
            } else {
              printf("\nYou shifted the pointer to the right\n");
              cur = cur->next;
            }
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 9:
        if (sl) {
          if (cur == NULL) {
            printf("\nEmpty list\n\n");
          } else {
            if (cur->prev == NULL) {
              printf("\nThe pointer is in the start\n");
            } else {
              printf("\nYou shifted the pointer to the left\n");
              cur = cur->prev;
            }
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 10:
        if (sl) {
          if (cur == NULL) {
            printf("\nEmpty list\n\n");
          } else {
            if (cur->prev == NULL) {
              printf("\nThe pointer is in the start\n");
            } else {
              printf("\nThe element before the pointer: ");
              printf("%c\n", cur->prev->data);
            }
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 11:
        if (sl) {
          if (cur == NULL) {
            printf("\nEmpty list\n\n");
          } else {
            if (cur->next == NULL) {
              printf("\nThe pointer is in the end\n");
            } else {
              printf("\nThe element after the pointer: ");
              printf("%c\n", cur->next->data);
            }
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 12:
        if (sl) {
          if (cur == NULL) {
            printf("\nEmpty list\n\n");
          } else {
            if (cur->next == NULL) {
              printf("\nThe pointer is in the end\n");
            } else {
              remove_element_after(cur, cur->next);
              if (cur->next == NULL) {
                end = cur;
              }
              printf("\nYou've deleted the character after the pointer\n");
            }
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 13:
        if (sl) {
          if (cur == NULL) {
            printf("\nEmpty list\n\n");
          } else {
            if (cur->prev == NULL) {
              printf("\nThe pointer is in the start\n");
            } else {
              remove_element_before(cur, cur->prev);
              if (cur->prev == NULL) head = cur;
              printf("\nYou've deleted the character before the pointer\n");
            }
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 14:
        if (sl) {
          if (cur == NULL) {
            printf("\nEmpty list\n\n");
          } else {
            if (cur->next == NULL) {
              printf("\nThe pointer is in the end\n");
            } else {
              printf("\nThe character you have entered: ");
              printf("%c\n", cur->next->data);
              remove_element_after(cur, cur->next);
              if (cur->next == NULL) end = cur;
            }
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 15:
        if (sl) {
          if (cur == NULL) {
            printf("\nEmpty list\n\n");
          } else {
            if (cur->prev == NULL) {
              printf("\nThe pointer is in the start\n");
            } else {
              printf("\nThe character you have entered: ");
              printf("%c\n", cur->prev->data);
              remove_element_before(cur, cur->prev);
              if (cur->prev == NULL) {
                head = cur;
              }
            }
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 16:
        if (sl) {
          if (head == NULL) {
            printf("\nEmpty list\n\n");
          } else {
            if (cur->prev == NULL) {
              printf("\nThe pointer is in the start\n");
            } else {
              char ch;
              printf("\nEnter the character you want to insert instead: ");
              ch = getchar();
              if (ch == '\n') ch = getchar();
              cur->prev->data = ch;
              system("clear");
              printf(
                  "\nYou've changed the character after the pointer to: %c\n",
                  ch);
            }
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 17:
        if (sl) {
          if (head == NULL) {
            printf("\nEmpty list\n\n");
          } else {
            if (cur->next == NULL) {
              printf("\nThe pointer is in the end\n");
            } else {
              char ch;
              printf("\nEnter the character you want to insert instead: ");
              ch = getchar();
              if (ch == '\n') ch = getchar();
              cur->next->data = ch;
              system("clear");
              printf(
                  "\nYou've changed the character after the pointer to: %c\n",
                  ch);
            }
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 18:
        if (sl) {
          char ch;
          printf("\nEnter 1 character: ");
          ch = getchar();
          if (ch == '\n') {
            ch = getchar();
          }
          if (head == NULL) {
            head = create_node(ch);
            cur = head;
            end = head;
          } else {
            insert_before(ch, cur, head);
            if (head->prev) {
              head = head->prev;
            }
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 19:
        if (sl) {
          char ch;
          printf("\nEnter 1 character: ");
          ch = getchar();
          if (ch == '\n') {
            ch = getchar();
          }
          if (head == NULL) {
            head = create_node(ch);
            cur = head;
            end = head;
          } else {
            insert_after(ch, cur, end);
            if (end->next) {
              end = end->next;
            }
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 20:
        if (sl) {
          if (head == NULL) {
            printf("\nEmpty list\n\n");
          } else {
          }
        } else {
          printf("You haven't started working with the list yet\n\n");
        }
        break;
      case 21:
        if (!sl) {
          printf("\nYou haven't started working with the list yet\n\n");
        } else {
          sl = 0;
          free_st(head);
          head = NULL;
          cur = NULL;
          end = NULL;
          printf("\nYou've finished working with the list\n\n");
        }
        break;
      case 22:
        if (sl) {
          printf(
              "\nYou can't exit the program yet as you haven't finished "
              "working with the list!\n\n");
        } else {
          system("clear");
          printf("\nYou've successfully exited the program\n");
          exit(0);
        }
        break;
      default:
        printf("\nWrong choice. Enter Again:\n\n");
        break;
    }
  }
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