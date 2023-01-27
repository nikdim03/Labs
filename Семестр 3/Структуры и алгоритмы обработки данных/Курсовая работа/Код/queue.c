#include "queue.h"

void QueueDeleteAll(queueCollection* queue) {
  queueElement* node = queue->head;
  queueElement* badElement = node;
  while (node->next != NULL) {
    badElement = node;
    node = node->next;
    free(badElement);
  }
  queue->head = NULL;
  queue->tail = NULL;
}

void QueueDeleteTail(queueCollection* queue) {
  queueElement* node = queue->tail;
  if (queue->head != queue->tail) {
    queue->tail = queue->tail->prev;
    queue->tail->next = NULL;
  } else {
    queue->tail = NULL;
    queue->head = NULL;
  }
  st_clear(&node->data);
  free(node);
}

void QueueCheckEmpty(queueCollection* queue) {
  if (queue->head == NULL && queue->tail == NULL)
    printf("Queue is empty\n");
  else if (queue->head != NULL && queue->tail != NULL)
    printf("Queue is not empty\n");
  else
    printf("Error!\n");
}

int QueueSize(queueCollection* queue) {
  queueElement* cur = queue->head;
  int counter = 0;
  while (cur != NULL) {
    cur = cur->next;
    counter++;
  }
  return counter;
}

void QueueAddElement(queueCollection* queue) {
  if (queue->head == NULL) {
    struct queueElement* newElement;
    newElement = (struct queueElement*)malloc(sizeof(struct queueElement));
    if (newElement == NULL) {
      printf("Error, NULL\n");
      exit(1);
    }
    newElement->data = st_menu(NULL);
    newElement->prev = NULL;
    newElement->next = NULL;
    queue->head = newElement;
    queue->tail = queue->head;
  } else {
    struct queueElement* newElement;
    newElement = (struct queueElement*)malloc(sizeof(struct queueElement));
    if (newElement == NULL) {
      printf("Error, NULL\n");
      exit(1);
    }
    newElement->data = st_menu(NULL);
    newElement->next = queue->head;
    newElement->prev = NULL;
    queue->head->prev = newElement;
    queue->head = newElement;
  }
}

void QueueWatchTail(queueCollection* queue) {
  printf("Element: ");
  st_print(queue->tail->data);
}

void QueueInsert(queueCollection* queue) {
  QueueWatchTail(queue);
  QueueDeleteTail(queue);
}

void QueueChangeTail(queueCollection* queue) {
  printf("Started work with first element\n");
  queue->tail->data = st_menu(&queue->tail->data);
}

void QueuePrint(queueCollection* queue) {
  queueElement* cur = queue->head;
  int counter = 0;
  printf("/*| End |*\\ \n");
  while (cur != NULL) {
    printf("    ");
    st_print(cur->data);
    counter++;
    cur = cur->next;
  }
  printf("/*| Start |*\\\n");
}

queueCollection QueueMenu(queueCollection* queuePointer) {
  int menuPointer = 0;
  int buffer;
  int isExist = 0;
  int flagCreate = 0;
  struct queueCollection queue;
  if (queuePointer != NULL) {
    queue = *queuePointer;
  } else {
    queue.head = NULL;
    queue.tail = NULL;
  }
  system("clear");
  while (menuPointer != 9) {
    menuPointer = 0;
    int directionFlag = 0;
    system("clear");
    printf("Queue Menu\n");
    printf("Select menu item\n");
    printf("1. Clear queue\n");
    printf("2. Check empty\n");
    printf("3. Add new element\n");
    printf("4. Insert first element\n");
    printf("5. Watch first element\n");
    printf("6. Delete first element\n");
    printf("7. Change first element\n");
    printf("8. Print queue\n");
    printf("9. Return\n");
    printf("\nQueue contains %d elements\n", QueueSize(&queue));
    if (QueueSize(&queue) != 0) {
      printf("Queue:\n");
      QueuePrint(&queue);
    }
    scanf("%d", &menuPointer);
    buffer = getchar();  // мусор
    switch (menuPointer) {
      case 1:
        system("clear");
        if (queue.head != NULL) {
          QueueDeleteAll(&queue);
        }
        printf("Work done, press enter to return\n");
        buffer = getchar();
        break;
      case 2:
        system("clear");
        QueueCheckEmpty(&queue);
        printf("Work done, press enter to return\n");
        buffer = getchar();
        break;
      case 3:
        flagCreate = 0;
        while (flagCreate != 1 && flagCreate != 2) {
          system("clear");
          printf("You want to make new list and start work with it?\n");
          printf("1. Create list and start work\n");
          printf("2. Return to queue menu\n");
          scanf("%d", &flagCreate);
          if (flagCreate == 1) {
            QueueAddElement(&queue);
            printf("Work done, press enter to return\n");
            buffer = getchar();
          } else if (flagCreate != 2) {
            printf("Input correct number\n");
            buffer = getchar();
            buffer = getchar();
          }
        }
        break;
      case 4:
        system("clear");
        if (queue.tail != NULL) {
          QueueInsert(&queue);
          printf("Work done, press enter to return\n");
        } else
          printf("Error, empty queue\n");
        buffer = getchar();
        break;
      case 5:
        system("clear");
        if (queue.head != NULL) {
          QueueWatchTail(&queue);
          printf("Work done, press enter to return\n");
        } else
          printf("Error, empty queue\n");
        buffer = getchar();
        break;
      case 6:
        system("clear");
        if (queue.tail != NULL) {
          QueueDeleteTail(&queue);
          printf("Work done, press enter to return\n");
        } else
          printf("Error, empty queue\n");
        buffer = getchar();
        break;
      case 7:
        system("clear");
        if (queue.tail != NULL) {
          QueueChangeTail(&queue);
          printf("Work done, press enter to return\n");
        } else
          printf("Error, empty queue\n");
        buffer = getchar();
        break;
      case 8:
        system("clear");
        if (queue.tail != NULL) {
          QueuePrint(&queue);
          printf("Work done, press enter to return\n");
        } else
          printf("Error, empty queue\n");
        buffer = getchar();
        break;
      default:
        system("clear");
        break;
    }
  }
  // if (queue.head != NULL)
  //   QueueDeleteAll(&queue); //если выход
  return queue;
}