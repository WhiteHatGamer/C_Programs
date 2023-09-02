#include "queue.h"
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue {
    linkedlist_t* front;
    linkedlist_t* rear;
}queue_t;

queue_t* qInit(){
    queue_t* q = (queue_t*)malloc(sizeof(queue_t));
    if (q == NULL){
        // malloc failed 
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

void qEnqueue(queue_t* _queue, void* _data){
    linkedlist_t* tmp = llCreateNode(_data);
    if (tmp == NULL){
        // malloc failed 
        return;
    }
    if (_queue->front == NULL){
        _queue->front = _queue->rear = tmp;
        return;
    }
    _queue->rear->next = tmp;
    _queue->rear = _queue->rear->next;
    return;
}

void* qDequeue(queue_t* _queue){
    if(_queue->front==NULL){
        return NULL;
    }
    if(_queue->front == _queue->rear){
        _queue->rear = NULL;
    }
    void* tmp = _queue->front->data;
    llDeleteHead(&(_queue->front));
    return tmp;
}

void qPrint(queue_t* _queue){
    printf("\nFront: ");
    linkedlist_t *tmp = _queue->front;

    while(tmp != NULL){
        printf("%p <- ", tmp->data);
        tmp = tmp->next;
    }
    printf(":Rear\n");
    return;
}

void qFront(queue_t* _queue){
    printf("Queue Front: %p",_queue->front->data);
    return;
}

void qRear(queue_t* _queue){
    printf("Queue Rear: %p",_queue->rear->data);
    return;
}

bool qIsEmpty(queue_t* _queue){
    if (_queue->front == NULL){
        return true;
    }
    return false;
}

void qFree(queue_t* _queue){
    llFree(_queue->front);
    _queue->front = NULL;
    _queue->rear = NULL;
    free(_queue);
}