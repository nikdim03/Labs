#ifndef QUEUE_H_
#define QUEUE_H_

#include "sentence.h"

typedef struct queueElement {
  st_set data;
  struct queueElement* next, *prev;  // = NULL
} queueElement;

typedef struct queueCollection {
  queueElement* head;
  queueElement* tail;
} queueCollection;

void QueueDeleteAll(queueCollection* queue);
void QueueDeleteTail(queueCollection* queue);
void QueueCheckEmpty(queueCollection* queue);
int QueueSize(queueCollection* queue);
void QueueAddElement(queueCollection* queue);
void QueueWatchTail(queueCollection* queue);
void QueueInsert(queueCollection* queue);
void QueueChangeTail(queueCollection* queue);
void QueuePrint(queueCollection* queue);
queueCollection QueueMenu(queueCollection* queuePointer);

#endif  // QUEUE_H_