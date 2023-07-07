#ifndef QUEUE_H
#define QUEUE_H

#include "linkedList.h"

typedef struct Queue{
    linkedlist_t* front;
    linkedlist_t* rear;
}queue_t;

// Initialize a New Queue
queue_t* initQueue();

// Insert a data into queue : Enqueue
void enqueue(queue_t* _queue, int _data);

// Delete/dequeue from Queue
void dequeue(queue_t* _queue);

// Prints the Queue
void qPrint(queue_t* _queue);

// Prints Front of the queue
void qFront(queue_t* _queue);

// Prints Rear of the Queue
void qRear(queue_t* _queue);

// Free every memory dinamically allocated
void freeQueue(queue_t* _queue);

#endif