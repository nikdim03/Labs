#include "sequence.h"

// Функция для отображения меню для работы с последовательностью
void sq_menu(sq_set sequence) {
  int choice = 0, st_choice = 0;
  // Очищаем экран
  system("clear");
  do {
    // Выводим заголовок меню с цветным текстом
    printf(
        "\033[38;5;196mМ\033[38;5;202mЕ\033[38;5;208mН\033[38;5;"
        "214mЮ\033[38;5;220m "
        "\033[38;5;226mП\033[38;5;190mО\033[38;5;154mС\033[38;5;"
        "118mL\033[38;5;82mЕ\033[38;5;46mД\033[38;5;47mО\033[38;5;"
        "48mВ\033[38;5;49mА\033[38;5;50mТ\033[38;5;51mЕ\033[38;5;"
        "52mЛ\033[38;5;53mЬ\033[38;5;54mН\033[38;5;55mО\033[38;5;"
        "56mС\033[38;5;57mТ\033[38;5;58mИ\033[38;5;59m "
        "(\033[38;5;60mL\033[38;5;61mV\033[38;5;62mL\033[38;5;63m "
        "\033[38;5;64m1\033[38;5;65m)\033[0m\n");
    // Выводим варианты действий, которые может выполнить пользователь
    printf("Выберите пункт меню\n");
    printf("1. Очистить\n2. Проверить на путоту\n");
    printf("3. Установить указатель на начало\n");
    printf("4. Проверить, является ли указатель концом последовательности\n");
    printf("5. Переместить указатель вперед\n");
    printf("6. Вывести текущий элемент\n");
    printf("7. Изменить текущий элемент\n");
    printf("8. Извлечь элемент после указателя\n");
    printf("9. Добавить элемент после указателя\n");
    printf("10. Вывести последовательность\n");
    printf("11. Вывести текущий элемент и переместить указатель вперед\n");
    printf("12. Удалить последовательность и выйти\n");
    printf("\nПоследовательность содержит %zu элементов\n", sq_size(&sequence));
    // Если последовательность не пустая, вывести ее элементы
    if (sequence.head != NULL) {
      printf("Последовательность: \n");
      sq_print(&sequence);
    }
    // Считываем выбор пользователя
    scanf("%d", &choice);
    // В зависимости от выбора выполняем соответствующую операцию
    switch (choice) {
      case 1:
        // Очистка последовательности
        system("clear");
        // Если последовательность не пустая, выполняем очистку
        if (sequence.head != NULL) sq_clear(&sequence);
        printf("Готово! Нажмите Enter, чтобы вернуться\n");
        // Ждем нажатия Enter для возврата в меню
        if (getchar() == '\n') getchar();
        break;
      case 2:
        system("clear");
        sq_is_empty(&sequence);
        printf("Готово! Нажмите Enter, чтобы вернуться\n");
        if (getchar() == '\n') getchar();
        break;
      case 3:
        system("clear");
        sq_to_start(&sequence);
        printf("Готово! Нажмите Enter, чтобы вернуться\n");
        if (getchar() == '\n') getchar();
        break;
      case 4:
        system("clear");
        if (sequence.head != NULL) {
          sq_is_end(&sequence);
          printf("Готово! Нажмите Enter, чтобы вернуться\n");
        } else {
          printf("Ошибка, пустая последовательность\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 5:
        system("clear");
        if (sequence.head != NULL) {
          if (sequence.cur->next != NULL) {
            sq_shift_forward(&sequence);
            printf("Готово! Нажмите Enter, чтобы вернуться\n");
          } else {
            printf("Ошибка, конец последовательности");
          }
        } else {
          printf("Ошибка, пустая последовательность");
        }
        if (getchar() == '\n') getchar();
        break;
      case 6:
        system("clear");
        if (sequence.head != NULL) {
          sq_print_cur(&sequence);
          printf("Готово! Нажмите Enter, чтобы вернуться\n");
        } else {
          printf("Ошибка, пустая последовательность\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 7:
        system("clear");
        if (sequence.head != NULL) {
          sq_change_cur(&sequence);
          printf("Готово! Нажмите Enter, чтобы вернуться\n");
        } else {
          printf("Ошибка, пустая последовательность\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 8:
        system("clear");
        if (sequence.head != NULL) {
          sq_print_cur(&sequence);
          sq_remove_cur(&sequence);
          printf("Готово! Нажмите Enter, чтобы вернуться\n");
        } else {
          printf("Ошибка, пустая последовательность\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 9:
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
          printf("1. Создать дек\n");
          printf("2. Вернуться в меню последовательности\n");
          scanf("%d", &st_choice);
          switch (st_choice) {
            case 1:
              sq_add_elem(&sequence);
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
        system("clear");
        break;
      case 10:
        system("clear");
        if (sequence.head != NULL) {
          sq_print(&sequence);
          printf("Готово! Нажмите Enter, чтобы вернуться\n");
        } else {
          printf("Ошибка, пустая последовательность\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 11:
        system("clear");
        if (sequence.head != NULL) {
          if (sequence.cur->next != NULL) {
            dq_print(&sequence.cur->data);
            sq_shift_forward(&sequence);
            printf("Готово! Нажмите Enter, чтобы вернуться\n");
          } else {
            printf("Ошибка, конец последовательности");
          }
        } else {
          printf("Ошибка, пустая последовательность\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 12:
        if (sequence.head != NULL) sq_clear(&sequence);
        break;
      default:
        system("clear");
        printf("Неправильный ввод! Попробуйте снова\n");
        break;
    }
  } while (choice != 12);
  system("clear");
}

// Функция для вывода элементов последовательности
void sq_print(sq_set* sequence) {
  // Указатель на текущий элемент последовательности
  sq_elem* cur = sequence->head;
  // Счетчик элементов
  size_t count = 0;
  // Пока указатель не равен NULL, выводим текущий элемент
  while (cur != NULL) {
    // Выводим номер элемента и указатель на текущий элемент, если нужно
    printf("[\033[0;32m%zu\033[0m]:", count);
    if (cur == sequence->cur) printf("\033[0;32m<--\033[0m");
    printf("\n");
    // Выводим содержимое элемента
    dq_print(&cur->data);
    // Увеличиваем счетчик
    count++;
    // Переходим к следующему элементу
    cur = cur->next;
  }
}

// Функция для удаления текущего элемента из последовательности
void sq_remove_cur(sq_set* sequence) {
  // Если текущего элемента нет, то ничего удалять не нужно
  if (sequence->cur == NULL) return;
  // Указатель на текущий элемент
  sq_elem* node = sequence->head;
  // Указатель на предыдущий элемент
  sq_elem* prev = NULL;
  // Пока указатель не равен NULL и текущий элемент не равен текущему элементу
  // последовательности, ищем текущий элемент
  while (node != NULL && node != sequence->cur) {
    prev = node;
    node = node->next;
  }
  // Текущий элемент не найден в последовательности
  if (node == NULL) return;
  // Отсоединяем текущий элемент от последовательности
  // Текущий элемент является головой последовательности
  if (prev == NULL)
    sequence->head = node->next;
  else
    prev->next = node->next;
  // Текущий элемент является хвостом последовательности
  if (node->next == NULL) sequence->tail = prev;
  // Очищаем данные в текущем элементе и освобождаем память
  dq_clear(&node->data);
  free(node);
  // Обновляем указатель на текущий элемент
  sequence->cur = sequence->head;
}

// Функция для очистки последовательности
void sq_clear(sq_set* sequence) {
  // Указатель на голову последовательности
  sq_elem* node = sequence->head;
  // Указатель на элемент для удаления
  sq_elem* to_delete = node;
  // Пока у элемента есть следующий, удаляем текущий элемент
  while (node->next != NULL) {
    to_delete = node;
    node = node->next;
    // Очищаем данные в элементе и освобождаем память
    dq_clear(&to_delete->data);
    free(to_delete);
  }
  // Удаляем последний элемент
  dq_clear(&node->data);
  free(node);
  // Обнуляем указатели в последовательности
  sequence->head = NULL;
  sequence->cur = NULL;
  sequence->tail = NULL;
}

// Функция для инициализации последовательности
sq_set sq_init() {
  // Создаем последовательность
  sq_set sequence;
  // Обнуляем указатели
  sequence.cur = NULL;
  sequence.head = NULL;
  sequence.tail = NULL;
  // Возвращаем последовательность
  return sequence;
}

// Функция для проверки, является ли последовательность пустой
bool sq_is_empty(sq_set* sequence) {
  // Если голова последовательности равна NULL, последовательность пуста
  if (sequence->head == NULL) {
    printf("Последовательность пуста\n");
    return true;
  } else {
    // Иначе последовательность не пустая
    printf("Последовательность не пустая\n");
    return false;
  }
}

// Функция для проверки, является ли текущий элемент концом последовательности
bool sq_is_end(sq_set* sequence) {
  // Если у текущего элемента нет следующего, он является концом
  // последовательности
  if (sequence->cur->next == NULL) {
    printf("Указатель находится в конце последовательности\n");
    return true;
  } else {
    // Иначе текущий элемент не является концом последовательности
    printf("Указатель не находится в конце последовательности\n");
  }
  // Возвращаем false
  return false;
}

// Функция для установки указателя на начало последовательности
void sq_to_start(sq_set* sequence) {
  // Устанавливаем указатель на голову последовательности
  sequence->cur = sequence->head;
}

// Функция для добавления элемента в конец последовательности
void sq_add_elem(sq_set* sequence) {
  // Выделяем память под новый элемент
  sq_elem* cur = (struct sq_elem*)malloc(sizeof(struct sq_elem));
  // Если память не была выделена, выводим сообщение об ошибке и завершаем
  // программу
  if (cur == NULL) {
    printf("Ошибка, NULL\n");
    exit(1);
  }
  // Инициализируем данные в элементе
  cur->data = dq_menu(NULL);
  // Устанавливаем указатель на следующий элемент в NULL
  cur->next = NULL;
  // Если в последовательности нет элементов
  if (sequence->head == NULL) {
    // То новый элемент становится первым, текущим и последним в
    // последовательности
    sequence->head = cur;
    sequence->cur = cur;
    sequence->tail = cur;
  } else {
    // В противном случае, новый элемент становится последним в
    // последовательности
    sequence->tail->next = cur;
    sequence->tail = cur;
  }
}

// Функция перемещения текущего указателя на следующий элемент в
// последовательности
void sq_shift_forward(sq_set* sequence) {
  // Перемещение текущего указателя на следующий элемент
  sequence->cur = sequence->cur->next;
}

// Функция вывода текущего элемента последовательности
void sq_print_cur(sq_set* sequence) {
  // Вывод текущего элемента
  dq_print(&sequence->cur->data);
}

// Функция изменения текущего элемента последовательности
void sq_change_cur(sq_set* sequence) {
  // Изменение данных текущего элемента
  sequence->cur->data = dq_menu(&sequence->cur->data);
}

// Функция, возвращающая размер последовательности
size_t sq_size(sq_set* sequence) {
  // Указатель на текущий элемент последовательности
  sq_elem* cur = sequence->head;
  // Счетчик элементов в последовательности
  size_t count = 0;
  // Пока текущий элемент существует
  while (cur != NULL) {
    // Переход к следующему элементу
    cur = cur->next;
    // Увеличение счетчика
    count++;
  }
  // Возвращение размера последовательности
  return count;
}
