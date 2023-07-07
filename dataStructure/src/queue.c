#include "queue.h"
#include "linkedList.h"

#include <stdio.h>
#include <stdlib.h>

queue_t* initQueue(){
    queue_t* q = (queue_t*)malloc(sizeof(queue_t));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(queue_t* _queue, int _data){
    linkedlist_t* tmp = createNode(_data);
    if (_queue->front == NULL){
        _queue->front = _queue->rear = tmp;
        return;
    }
    _queue->rear->next = tmp;
    _queue->rear = _queue->rear->next;
    return;
}

void dequeue(queue_t* _queue){
    if(_queue->front==NULL){
        return;
    }
    if(_queue->front == _queue->rear){
        _queue->rear = NULL;
    }
    deleteHead(&(_queue->front));
    return;
}

void qFront(queue_t* _queue){
    printf("Queue Front: %i",_queue->front->data);
    return;
}

void qRear(queue_t* _queue){
    printf("Queue Rear: %i",_queue->rear->data);
    return;
}

void freeQueue(queue_t* _queue){
    freeLinkedList(_queue->front);
    free(_queue);
}