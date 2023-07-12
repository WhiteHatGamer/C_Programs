#ifndef STACK_H
#define STACK H

#define MAX_SIZE 5

#include "linkedList.h"

typedef struct Stack{
    linkedlist_t* top;
}stack_t;

#endif