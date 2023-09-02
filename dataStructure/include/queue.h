#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Queue queue_t;

// Initialize a New Queue
queue_t* qInit();

// Insert a data into queue : qEnqueue
void qEnqueue(queue_t* _queue, void* _data);

// Delete/qDequeue from Queue
void* qDequeue(queue_t* _queue);

// Prints the Queue
void qPrint(queue_t* _queue);

// Prints Front of the queue
void qFront(queue_t* _queue);

// Prints Rear of the Queue
void qRear(queue_t* _queue);

// Checks Whether queue is empty
bool qIsEmpty(queue_t* _queue);

// Free every memory dinamically allocated
void qFree(queue_t* _queue);

#endif