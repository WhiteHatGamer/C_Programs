#include "stack.h"
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

stack_t* initStack(){
    stack_t* _stack = (stack_t*)malloc(sizeof(stack_t));
    _stack->top = NULL;
    return _stack;
}

void freeStack (stack_t* _stack){
    freeLinkedList(_stack->top);
    free(_stack);
}