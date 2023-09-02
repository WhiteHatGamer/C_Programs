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


// Free every memory dinamically allocated
void qFree(queue_t* _queue);

#endif