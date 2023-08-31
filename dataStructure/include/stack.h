#ifndef STACK_H
#define STACK_H

#define STACK_MAX_SIZE 5

#include "intLinkedList.h"

typedef struct Stack{
    intlinkedlist_t* top;
}stack_t;

// Initialize stack
stack_t* initStack();

// Push to stack
void push(stack_t* _stack, int _data);

// Pop from Stack
void pop(stack_t* _stack);

// Print Stack
void printStack(stack_t* _stack);

// Free stack and other dynamic allocated
void freeStack (stack_t* _stack);

#endif