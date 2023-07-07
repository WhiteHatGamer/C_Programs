#ifndef QUEUE_H
#define QUEUE_H

#include "linkedList.h"

typedef struct Queue{
    linkedlist_t* front;
    linkedlist_t* rear;
}queue_t;

// Initialize a New Queue
queue_t* initQueue();

void enqueue(queue_t* _queue, int _data);

// Free every memory dinamically allocated
void freeQueue(queue_t* _queue);

#endif