#include "deque.h"

// Функция для отображения меню для работы с деком
dq_set dq_menu(dq_set* dq_ptr) {
  int choice = 0, st_choice = 0;
  dq_set deque;
  if (dq_ptr != NULL) {
    deque = *dq_ptr;
  } else {
    deque.head = NULL;
    deque.tail = NULL;
  }
  dq_get_depth(&deque);
  system("clear");
  do {
    // Выводим заголовок меню с цветным текстом
    printf(
        "\033[38;5;196mМ\033[38;5;202mЕ\033[38;5;208mН\033[38;5;214mЮ\033[38;5;"
        "220m "
        "\033[38;5;226mД\033[38;5;190mЕ\033[38;5;154mК\033[38;5;118mA\033[38;5;"
        "82m (\033[38;5;46mL\033[38;5;47mV\033[38;5;48mL\033[38;5;49m "
        "\033[38;5;50m2\033[38;5;51m)\033[0m\n");
    // Выводим варианты действий, которые может выполнить пользователь
    printf("Выберите пункт меню\n");
    printf("1. Очистить\n2. Проверить на пустоту\n");
    printf("3. Вывести первый элемент\n");
    printf("4. Вывести последний элемент\n");
    printf("5. Удалить первый элемент\n");
    printf("6. Удалить последний элемент\n");
    printf("7. Извлечь первый элемент\n");
    printf("8. Извлечь последний элемент\n");
    printf("9. Изменить первый элемент\n");
    printf("10. Изменить последний элемент\n");
    printf("11. Добавить в начало\n");
    printf("12. Добавить в конец\n");
    printf("13. Вывести дек\n");
    printf("14. Вернуться в стартовое меню\n");
    // Если дек не пустой, вывести его элементы
    printf("\nДек содержит %zu элементов (глубина = %zu)\n", dq_size(&deque),
           deque.depth);
    if (dq_size(&deque) != 0) {
      printf("Дек:\n");
      dq_print(&deque);
    }
    // Считываем выбор пользователя
    scanf("%d", &choice);
    // В зависимости от выбора выполняем соответствующую операцию
    switch (choice) {
      case 1:
        // Очистка дека
        system("clear");
        // Если дек не пустой, выполняем очистку
        if (deque.head != NULL) dq_clear(&deque);
        // Ждем нажатия Enter для возврата в меню
        printf("Готово! Нажмите Enter, чтобы вернуться\n");
        if (getchar() == '\n') getchar();
        break;
      case 2:
        system("clear");
        dq_is_empty(&deque);
        printf("Готово! Нажмите Enter, чтобы вернуться\n");
        if (getchar() == '\n') getchar();
        break;
      case 3:
        system("clear");
        if (deque.head != NULL) {
          dq_print_first(&deque);
          printf("Готово! Нажмите Enter, чтобы вернуться\n");
        } else {
          printf("Ошибка, пустой дек\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 4:
        system("clear");
        if (deque.head != NULL) {
          dq_print_last(&deque);
          printf("Готово! Нажмите Enter, чтобы вернуться\n");
        } else {
          printf("Ошибка, пустой дек\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 5:
        system("clear");
        if (deque.tail != NULL) {
          dq_pop_front(&deque);
          printf("Готово! Нажмите Enter, чтобы вернуться\n");
        } else {
          printf("Ошибка, пустой дек\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 6:
        system("clear");
        if (deque.tail != NULL) {
          dq_pop_back(&deque);
          printf("Готово! Нажмите Enter, чтобы вернуться\n");
        } else {
          printf("Ошибка, пустой дек\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 7:
        system("clear");
        if (deque.head != NULL) {
          dq_print_first(&deque);
          dq_pop_front(&deque);
          printf("Готово! Нажмите Enter, чтобы вернуться\n");
        } else {
          printf("Ошибка, пустой дек\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 8:
        system("clear");
        if (deque.head != NULL) {
          dq_print_last(&deque);
          dq_pop_back(&deque);
          printf("Готово! Нажмите Enter, чтобы вернуться\n");
        } else {
          printf("Ошибка, пустой дек\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 9:
        system("clear");
        if (deque.tail != NULL) {
          dq_change_first(&deque);
          printf("Готово! Нажмите Enter, чтобы вернуться\n");
        } else {
          printf("Ошибка, пустой дек\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 10:
        system("clear");
        if (deque.tail != NULL) {
          dq_change_last(&deque);
          printf("Готово! Нажмите Enter, чтобы вернуться\n");
        } else {
          printf("Ошибка, пустой дек\n");
        }
        if (getchar() == '\n') getchar();
        break;

        break;
      case 11:
        system("clear");
        do {
          printf(
              "\033[38;5;196mС\033[38;5;202mТ\033[38;5;208mA\033[38;5;"
              "214mР\033[38;5;220mТ\033[38;5;226mО\033[38;5;190mВ\033[38;5;"
              "154mО\033["
              "38;5;118mЕ\033[38;5;82m "
              "\033[38;5;47mМ\033[38;5;82mЕ\033[38;5;118mН\033[38;5;154mЮ\033["
              "0m\n");
          printf("Выберите пункт меню\n");
          printf("1. Создать предложение\n");
          printf("2. Вернуться в меню дека\n");
          scanf("%d", &st_choice);
          switch (st_choice) {
            case 1:
              if (dq_size(&deque) < deque.depth) {
                dq_push_front(&deque);
              } else {
                system("clear");
                printf("Ошибка, достигнуто максимальное значение глубины\n");
                if (getchar() == '\n') getchar();
              }
              break;
            case 2:
              break;
            default:
              system("clear");
              printf("Неправильный ввод! Попробуйте снова\n");
              if (getchar() == '\n') getchar();
              break;
          }
        } while (st_choice != 2);
        break;
      case 12:
        system("clear");
        do {
          printf(
              "\033[38;5;196mС\033[38;5;202mТ\033[38;5;208mA\033[38;5;"
              "214mР\033[38;5;220mТ\033[38;5;226mО\033[38;5;190mВ\033[38;5;"
              "154mО\033["
              "38;5;118mЕ\033[38;5;82m "
              "\033[38;5;47mМ\033[38;5;82mЕ\033[38;5;118mН\033[38;5;154mЮ\033["
              "0m\n");
          printf("Выберите пункт меню\n");
          printf("1. Создать предложение\n");
          printf("2. Вернуться в меню дека\n");
          scanf("%d", &st_choice);
          switch (st_choice) {
            case 1:
              if (dq_size(&deque) < deque.depth) {
                dq_push_back(&deque);
              } else {
                system("clear");
                printf("Ошибка, достигнуто максимальное значение глубины\n");
                if (getchar() == '\n') getchar();
              }
              break;
            case 2:
              break;
            default:
              system("clear");
              printf("Неправильный ввод! Попробуйте снова\n");
              if (getchar() == '\n') getchar();
              break;
          }
        } while (st_choice != 2);
        break;
      case 13:
        system("clear");
        if (deque.tail != NULL) {
          dq_print(&deque);
          printf("Готово! Нажмите Enter, чтобы вернуться\n");
        } else {
          printf("Ошибка, пустой дек\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 14:
        break;
      default:
        system("clear");
        printf("Неправильный ввод! Попробуйте снова\n");
        if (getchar() == '\n') getchar();
        break;
    }
  } while (choice != 14);
  system("clear");
  return deque;
}

// Функция, запрашивающая у пользователя глубину дека и валидирующая ввод
void dq_get_depth(dq_set* deque) {
  // Глубина дека
  size_t depth;
  // Буфер для ввода строки
  char input[10];
  // Очистка экрана
  system("clear");
  // Бесконечный цикл
  while (true) {
    // Запрос глубины дека у пользователя
    printf("Введите глубину дека (целое положительное число):\n");
    // Очистка буфера stdin
    getchar();
    // Чтение строки с консоли
    fgets(input, sizeof(input), stdin);
    // Проверка, что введено целое положительное число
    if (sscanf(input, "%zu", &depth) == 1 && depth > 0) {
      // Если введено корректное число, то устанавливаем глубину дека и выходим
      // из цикла
      deque->depth = depth;
      break;
    } else {
      // Иначе, очищаем экран и сообщаем об ошибке
      system("clear");
      printf("Неправильный ввод! Попробуйте снова\n");
      // Очистка буфера stdin
      getchar();
    }
  }
}

// Функция, возвращающая размер дека
size_t dq_size(dq_set* deque) {
  // Указатель на текущий элемент дека
  dq_elem* cur = deque->head;
  // Счетчик элементов в деке
  size_t count = 0;
  // Пока текущий элемент существует
  while (cur != NULL) {
    // Переход к следующему элементу
    cur = cur->next;
    // Увеличение счетчика
    count++;
  }
  // Возвращение размера дека
  return count;
}

// Функция, очищающая дек
void dq_clear(dq_set* deque) {
  // Указатель на текущий элемент дека
  dq_elem* node = deque->head;
  // Указатель на элемент для удаления
  dq_elem* to_delete = node;
  // Пока текущий элемент не является последним в деке
  while (node->next != NULL) {
    // Сохраняем указатель на текущий элемент для удаления
    to_delete = node;
    // Переход к следующему элементу
    node = node->next;
    // Освобождение памяти, занятой текущим элементом
    free(to_delete);
  }
  // Обнуление указателей на первый и последний элементы дека
  deque->head = NULL;
  deque->tail = NULL;
}

// Функция, проверяющая, пуст ли дек
bool dq_is_empty(dq_set* deque) {
  // Если оба указателя на начало и конец дека равны NULL, то дек пуст
  if (deque->head == NULL && deque->tail == NULL) {
    // Сообщение об отсутствии элементов в деке
    printf("Дек пуст\n");
    // Возвращение результата
    return true;
  } else if (deque->head != NULL && deque->tail != NULL) {
    // Сообщение о наличии элементов в деке
    printf("Дек не пустой\n");
  }
  // Возвращение результата
  return false;
}

// Функция, выводящая первый элемент дека
void dq_print_first(dq_set* deque) {
  // Вывод названия элемента
  printf("Первый элемент: ");
  // Вывод данных элемента
  st_print(deque->tail->data);
}

// Функция, выводящая последний элемент дека
void dq_print_last(dq_set* deque) {
  // Вывод названия элемента
  printf("Последний элемент: ");
  // Вывод данных элемента
  st_print(deque->head->data);
}

// Функция, удаляющая первый элемент дека
void dq_pop_front(dq_set* deque) {
  // Указатель на элемент для удаления
  dq_elem* to_delete = deque->head;
  // Если в деке больше одного элемента
  if (deque->head != deque->tail) {
    // Переустанавливаем указатель на первый элемент дека
    deque->head = deque->head->next;
    // Обнуляем указатель на предыдущий элемент у нового первого элемента
    deque->head->prev = NULL;
  } else {
    // Иначе голова и хвост дека становятся равными NULL
    deque->head = NULL;
    deque->tail = NULL;
  }
  // Очищаем данные в элементе
  st_clear(&to_delete->data);
  // Освобождаем память
  free(to_delete);
}

// Функция для удаления элемента из хвоста дека
void dq_pop_back(dq_set* deque) {
  // Сохраняем указатель на удаляемый элемент
  dq_elem* to_delete = deque->tail;
  // Если у удаляемого элемента есть предыдущий, устанавливаем хвост дека на
  // этот элемент
  if (deque->head != deque->tail) {
    deque->tail = deque->tail->prev;
    deque->tail->next = NULL;
  } else {
    // Иначе голова и хвост дека становятся равными NULL
    deque->tail = NULL;
    deque->head = NULL;
  }
  // Очищаем данные в удаляемом элементе и освобождаем память
  st_clear(&to_delete->data);
  free(to_delete);
}

// Функция для добавления элемента в начало дека
void dq_push_front(dq_set* deque) {
  // Выделяем память для нового элемента
  dq_elem* new_elem = (struct dq_elem*)malloc(sizeof(dq_elem));
  // Если память не удалось выделить, выводим сообщение об ошибке и завершаем
  // программу
  if (new_elem == NULL) {
    printf("Ошибка, NULL\n");
    exit(1);
  }
  // Инициализируем данные в новом элементе
  new_elem->data = st_menu(NULL);
  new_elem->prev = NULL;
  // Если хвост дека равен NULL, значит дек пуст. Устанавливаем голову и хвост
  // дека на новый элемент
  if (deque->tail == NULL) {
    new_elem->next = NULL;
    deque->tail = new_elem;
    deque->head = deque->tail;
  } else {
    // Иначе устанавливаем указатель на предыдущий элемент
    new_elem->prev = deque->tail;
    deque->tail->next = new_elem;
    deque->tail = new_elem;
  }
}

// Функция для добавления элемента в конец дека
void dq_push_back(dq_set* deque) {
  // Выделяем память для нового элемента
  dq_elem* new_elem = (struct dq_elem*)malloc(sizeof(dq_elem));
  // Если память не удалось выделить, выводим сообщение об ошибке и завершаем
  // программу
  if (new_elem == NULL) {
    printf("Ошибка, NULL\n");
    exit(1);
  }
  // Инициализируем данные в новом элементе
  new_elem->data = st_menu(NULL);
  new_elem->next = NULL;
  // Если голова дека равна NULL, значит дек пуст. Устанавливаем голову и хвост
  // дека на новый элемент
  if (deque->head == NULL) {
    new_elem->prev = NULL;
    deque->head = new_elem;
    deque->tail = deque->head;
  } else {
    // Иначе устанавливаем указатель на следующий элемент текущего хвоста на
    // новый элемент
    new_elem->next = deque->head;
    deque->head->prev = new_elem;
    deque->head = new_elem;
  }
}

// Функция, выводящая содержимое дека
void dq_print(dq_set* deque) {
  // Указатель на текущий элемент дека
  dq_elem* cur = deque->head;
  // Вывод названия конца дека
  printf("\033[38;5;15m\033[48;5;1mКОНЕЦ\033[0m\n");
  // Цикл перебора элементов дека
  while (cur != NULL) {
    // Отступ элемента от края
    printf(" ");
    // Вывод данных текущего элемента
    st_print(cur->data);
    // Переход к следующему элементу
    cur = cur->next;
  }
  // Вывод названия начала дека
  printf("\033[38;5;15m\033[48;5;1mНАЧАЛО\033[0m\n");
}

// Функция, изменяющая первый элемент дека
void dq_change_first(dq_set* deque) {
  // Изменение данных первого элемента
  deque->tail->data = st_menu(&deque->tail->data);
}

// Функция, изменяющая последний элемент дека
void dq_change_last(dq_set* deque) {
  // Изменение данных последнего элемента
  deque->head->data = st_menu(&deque->head->data);
}