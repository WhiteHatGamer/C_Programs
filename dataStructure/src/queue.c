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

