#include "queue.h"
#include "linkedList.h"

queue_t* initQueue(){
    queue_t* q = (queue_t*)malloc(sizeof(queue_t));
    q->front = q->rear = NULL;
    return q;
}



void freeQueue(queue_t* _queue){
    freeLinkedList(_queue->front);
}