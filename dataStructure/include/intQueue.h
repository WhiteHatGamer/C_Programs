#ifndef INT_QUEUE_H
#define INT_QUEUE_H

#include "intLinkedList.h"

typedef struct IntQueue intqueue_t;

// Initialize a New Queue
intqueue_t* intQInit();

// Insert a data into queue : Enqueue
void intQEnqueue(intqueue_t* _queue, int _data);

// Delete/intQDequeue from Queue
int intQDequeue(intqueue_t* _queue);

// Prints the Queue
void intQDisplay(intqueue_t* _queue);

// Prints Front of the queue
void intQFront(intqueue_t* _queue);

// Prints Rear of the Queue
void intQRear(intqueue_t* _queue);

// Checks Whether queue is empty
bool intQIsEmpty(intqueue_t* _queue);

// Free every memory dinamically allocated
void intQFree(intqueue_t* _queue);

#endif