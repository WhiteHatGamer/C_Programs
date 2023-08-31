#include "intQueue.h"
#include "intLinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct IntQueue {
    intlinkedlist_t* front;
    intlinkedlist_t* rear;
}intqueue_t;

intqueue_t* intQInit(){
    intqueue_t* q = (intqueue_t*)malloc(sizeof(intqueue_t));
    if (q == NULL){
        // malloc failed 
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

void intQEnqueue(intqueue_t* _queue, int _data){
    intlinkedlist_t* tmp = IntLLCreateNode(_data);
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

int intQDequeue(intqueue_t* _queue){
    if(_queue->front==NULL){
        return INT_MIN;
    }
    if(_queue->front == _queue->rear){
        _queue->rear = NULL;
    }
    int tmp = _queue->front->data;
    IntLLDeleteHead(&(_queue->front));
    return tmp;
}

void intQDisplay(intqueue_t* _queue){
    printf("\nFront: ");
    intlinkedlist_t *tmp = _queue->front;

    while(tmp != NULL){
        printf("%d <- ", tmp->data);
        tmp = tmp->next;
    }
    printf(":Rear\n");
    return;
}

void intQFront(intqueue_t* _queue){
    printf("Queue Front: %i",_queue->front->data);
    return;
}

void intQRear(intqueue_t* _queue){
    printf("Queue Rear: %i",_queue->rear->data);
    return;
}

bool intQIsEmpty(intqueue_t* _queue){
    if (_queue->front == NULL){
        return true;
    }
    return false;
}

void intQFree(intqueue_t* _queue){
    IntLLFree(_queue->front);
    _queue->front = NULL;
    _queue->rear = NULL;
    free(_queue);
}