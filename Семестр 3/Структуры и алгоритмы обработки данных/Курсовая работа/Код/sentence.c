#include "sentence.h"

// Функция для отображения меню для работы с предложением
st_set st_menu(st_set* sentence_ptr) {
  int choice = 0;
  struct st_set sentence;
  if (sentence_ptr != NULL) {
    sentence = *sentence_ptr;
  } else {
    sentence.cur = NULL;
    sentence.head = NULL;
  }
  system("clear");
  do {
    // Выводим заголовок меню с цветным текстом
    printf(
        "\033[38;5;196mМ\033[38;5;202mЕ\033[38;5;208mН\033[38;5;214mЮ\033[38;5;"
        "220m "
        "\033[38;5;226mП\033[38;5;190mР\033[38;5;154mЕ\033[38;5;118mД\033[38;5;"
        "82mЛ\033[38;5;46mО\033[38;5;47mЖ\033[38;5;48mЕ\033[38;5;49mН\033[38;5;"
        "50mИ\033[38;5;51mЯ\033[38;5;52m "
        "(\033[38;5;53mL\033[38;5;54mV\033[38;5;55mL\033[38;5;56m "
        "\033[38;5;57m3\033[38;5;58m)\033[0m\n");
    // Выводим варианты действий, которые может выполнить пользователь
    printf("Выберите пункт меню\n");
    printf("1. Очистить\n");
    printf("2. Проверить на пустоту\n");
    printf("3. Установить указатель на начало\n");
    printf("4. Проверить, находится ли указатель в конце\n");
    printf("5. Переместить указатель вперед\n");
    printf("6. Вывести следующий элемент\n");
    printf("7. Удалить следующий элемент\n");
    printf("8. Извлечь следующий элемент\n");
    printf("9. Изменить следующий элемент\n");
    printf("10. Добавить элемент после указателя\n");
    printf("11. Вывести предложение\n");
    printf("12. Вернуться в стартовое меню\n");
    // Если предложение не пустое, вывести его
    printf("\nПредложение: \n");
    if (sentence.head != NULL)
      st_print(sentence);
    else
      // Иначе сообщить о том, что предложение пусто
      printf("Предложение пусто\n");
    // Считываем выбор пользователя
    scanf("%d", &choice);
    // В зависимости от выбора выполняем соответствующую операцию
    switch (choice) {
      case 1:
        // Очистка предложения
        system("clear");
        // Если предложение не пустое, выполняем очистку
        if (sentence.head != NULL) st_clear(&sentence);
        // Ждем нажатия Enter для возврата в меню
        printf("Готово! Нажмите Enter, чтобы вернуться\n");
        if (getchar() == '\n') getchar();
        break;
      case 2:
        system("clear");
        st_is_empty(&sentence);
        printf("Готово! Нажмите Enter, чтобы вернуться\n");
        if (getchar() == '\n') getchar();
        break;
      case 3:
        system("clear");
        st_to_start(&sentence);
        printf("Готово! Нажмите Enter, чтобы вернуться\n");
        if (getchar() == '\n') getchar();
        break;
      case 4:
        system("clear");
        if (sentence.head != NULL) {
          st_is_end(&sentence);
          printf("Готово! Нажмите Enter, чтобы вернуться\n");
        } else {
          printf("Ошибка, пустое предложение\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 5:
        system("clear");
        if (sentence.head != NULL) {
          if (sentence.cur->next != NULL) {
            st_shift_forward(&sentence);
            printf("Готово! Нажмите Enter, чтобы вернуться\n");
          } else
            printf("Ошибка, конец предложения");
        } else {
          printf("Ошибка, пустое предложение\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 6:
        system("clear");
        if (sentence.head != NULL) {
          if (sentence.cur->next != NULL) {
            st_print_next(&sentence);
            printf("Готово! Нажмите Enter, чтобы вернуться\n");
          } else
            printf("Ошибка, конец предложения");
        } else {
          printf("Ошибка, пустое предложение\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 7:
        system("clear");
        if (sentence.head != NULL) {
          if (sentence.cur->next != NULL) {
            st_delete_next(&sentence);
            printf("Готово! Нажмите Enter, чтобы вернуться\n");
          } else
            printf("Ошибка, конец предложения");
        } else {
          printf("Ошибка, пустое предложение\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 8:
        system("clear");
        if (sentence.head != NULL) {
          if (sentence.cur->next != NULL) {
            st_print_next(&sentence);
            st_delete_next(&sentence);
            printf("Готово! Нажмите Enter, чтобы вернуться\n");
          } else
            printf("Ошибка, конец предложения");
        } else {
          printf("Ошибка, пустое предложение\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 9:
        system("clear");
        if (sentence.head != NULL) {
          if (sentence.cur->next != NULL) {
            char* inputChangeElement;
            inputChangeElement = str_input();
            st_change_next(&sentence, inputChangeElement);
            printf("Готово! Нажмите Enter, чтобы вернуться\n");
          } else
            printf("Ошибка, конец предложения\n");
        } else {
          printf("Ошибка, пустое предложение\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 10:
        system("clear");
        getchar();
        char* inputElement = str_input();
        st_add_elem(&sentence, inputElement);
        printf("Готово! Нажмите Enter, чтобы вернуться\n");
        getchar();
        break;
      case 11:
        system("clear");
        if (sentence.head != NULL) {
          st_print(sentence);
          printf("Готово! Нажмите Enter, чтобы вернуться\n");
        } else {
          printf("Ошибка, пустое предложение\n");
        }
        if (getchar() == '\n') getchar();
        break;
      case 12:
        break;
      default:
        system("clear");
        printf("Неправильный ввод! Попробуйте снова\n");
        break;
    }
  } while (choice != 12);
  system("clear");
  return sentence;
}

// Функция, выводящая содержимое предложения
void st_print(st_set sentence) {
  // Указатель на текущий элемент предложения
  st_elem* node = sentence.head;
  // Если элементы в предложении есть
  if (node != NULL) {
    // Цикл перебора элементов
    while (true) {
      // Указатель на текущий символ
      char* ptr;
      // Поиск длины строки
      for (ptr = node->data; *ptr; ++ptr)
        ;
      // Цикл вывода символов строки
      for (int i = 0; i < ptr - node->data; i++) {
        // Если текущий элемент является текущим в предложении
        if (node == sentence.cur)
          // Вывод символа с подсветкой
          printf("\033[0;34m%c\033[0m", node->data[i]);
        else
          // Вывод символа
          printf("%c", node->data[i]);
      }
      // Вывод пробела
      printf(" ");
      // Переход к следующему элементу
      node = node->next;
      // Если следующего элемента нет, выходим из цикла
      if (node == NULL) {
        // Переход на новую строку
        printf("\n");
        break;
      }
    }
  } else
    // Переход на новую строку
    printf("\n");
}

// Функция, удаляющая следующий элемент после текущего в предложении
void st_delete_next(st_set* sentence) {
  // Если у следующего элемента есть следующий
  if (sentence->cur->next->next != 0) {
    // Указатель на элемент для удаления
    st_elem* to_delete = sentence->cur->next;
    // Установка указателя на следующий элемент у текущего элемента
    sentence->cur->next = sentence->cur->next->next;
    // Освобождение памяти, выделенной под элемент
    free(to_delete);
  } else {
    // Установка указателя на следующий элемент у текущего элемента в NULL
    sentence->cur->next = NULL;
  }
}

// Функция, очищающая предложение (удаляющая все элементы)
void st_clear(st_set* sentence) {
  // Указатель на первый элемент предложения
  st_elem* node = sentence->head;
  // Указатель на элемент для удаления
  st_elem* to_delete = node;
  // Если элементы в предложении есть
  if (node != NULL) {
    // Цикл удаления элементов
    while (node->next != NULL) {
      // Запоминаем элемент для удаления
      to_delete = node;
      // Переходим к следующему элементу
      node = node->next;
      // Освобождение памяти, выделенной под элемент
      free(to_delete);
    }
  }
  // Установка указателя на первый элемент в NULL
  sentence->head = NULL;
  // Установка указателя на текущий элемент в NULL
  sentence->cur = NULL;
}

// Функция, проверяющая, является ли предложение пустым
bool st_is_empty(st_set* sentence) {
  // Если первый элемент предложения равен NULL
  if (sentence->head == NULL) {
    // Вывод сообщения о том, что предложение пусто
    printf("Предложение пусто\n");
    // Возврат значения true
    return true;
  } else {
    // Вывод сообщения о том, что предложение не пустое
    printf("Предложение не пустое\n");
    // Возврат значения false
    return false;
  }
}

// Функция, проверяющая, является ли указатель на текущий элемент в конце
// предложения
bool st_is_end(st_set* sentence) {
  // Если у текущего элемента нет следующего
  if (sentence->cur->next == NULL) {
    // Вывод сообщения о том, что указатель в конце
    printf("Указатель в конце\n");
    // Возврат значения true
    return true;
  } else {
    // Вывод сообщения о том, что указатель не в конце
    printf("Указатель не в конце\n");
    // Возврат значения false
    return false;
  }
}

// Функция, устанавливающая указатель на первый элемент предложения
void st_to_start(st_set* sentence) {
  // Установка указателя на первый элемент предложения
  sentence->cur = sentence->head;
}

// Функция, добавляющая элемент в предложение после текущего
void st_add_elem(st_set* sentence, char* data) {
  // Создание указателя на элемент типа st_elem
  struct st_elem* cur;
  // Выделение памяти под элемент
  cur = (struct st_elem*)malloc(sizeof(struct st_elem));
  // Проверка, успешно ли выделена память
  if (cur == NULL) {
    // Вывод сообщения об ошибке и завершение программы
    printf("Ошибка, NULL\n");
    exit(1);
  }
  // Запись данных в элемент
  cur->data = data;
  // Установка указателя на следующий элемент равным NULL
  cur->next = NULL;
  // Если предложение пустое
  if (sentence->head == NULL) {
    // Устанавливаем указатель на первый элемент равным текущему элементу
    sentence->head = cur;
    // Устанавливаем указатель на текущий элемент равным текущему элементу
    sentence->cur = cur;
  }
  // Если текущий элемент не является хвостом последовательности, то
  // устанавливаем указатель на следующий элемент текущего элемента на новый
  // элемент
  if (sentence->cur->next == NULL) {
    sentence->cur->next = cur;
  } else {
    // Иначе устанавливаем указатель на следующий элемент нового элемента
    cur->next = sentence->cur->next;
    sentence->cur->next = cur;
  }
}

// Функция, сдвигающая указатель на текущий элемент вперед на один элемент
void st_shift_forward(st_set* sentence) {
  // Проверка, что указатель на текущий элемент не равен NULL
  if (sentence->cur != NULL) {
    // Сдвиг указателя на текущий элемент вперед на один элемент
    sentence->cur = sentence->cur->next;
  }
}

// Функция, выводящая на экран следующий элемент после текущего указателя
void st_print_next(st_set* sentence) {
  // Вывод сообщения о следующем элементе
  printf("Следующий элемент: ");
  // Указатель на текущую позицию в строке
  char* ptr;
  // Цикл для нахождения длины строки
  for (ptr = sentence->cur->next->data; *ptr; ++ptr)
    ;
  // Цикл для вывода символов строки
  for (int i = 0; i < ptr - sentence->cur->next->data; i++) {
    // Вывод символа
    printf("%c", sentence->cur->next->data[i]);
  }
  // Переход на новую строку после вывода строки
  printf("\n");
}

// Функция, изменяющая следующий элемент после текущего указателя
void st_change_next(st_set* sentence, char* data) {
  // Изменение данных следующего элемента
  sentence->cur->next->data = data;
}

// Функция для ввода слова с клавиатуры
char* str_input() {
  printf("Введите слово\n");
  // Счетчик для хранения размера строки
  size_t count = 0;
  // Буфер для хранения символа, введенного с клавиатуры
  char buffer = getchar();
  char* str = NULL;  // Указатель на строку, которую будем возвращать
  // Выделение памяти под первый символ строки
  str = (char*)malloc(sizeof(char));
  // Проверка на ошибку выделения памяти
  if (str == NULL) {
    printf("Ошибка, NULL\n");
    exit(1);
  }
  // Цикл для считывания символов с клавиатуры, пока не будет нажат Enter
  while (buffer != '\n' && buffer != '\0' && buffer != ' ') {
    // Запись введенного символа в строку
    str[count] = buffer;
    // Инкремент счетчика размера строки
    count++;
    // Считываем символы, пока они не равны переводу строки или концу файл
    buffer = getchar();
    // Выделяем память под ещё один символ
    str = (char*)realloc(str, sizeof(char) * count + 1);
    // Проверка на ошибку выделения памяти
    if (str == NULL) {
      printf("Ошибка, NULL\n");
      exit(1);
    }
  }
  // Добавляем нулевой символ в конец строки
  str[count] = '\0';
  // Возвращаем считанное слово
  return str;
}