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

void push(stack_t* _stack, int _data){
    if(_stack->top == NULL){
        _stack->top = createNode(_data);
        return;
    }
    _stack->top = insertHead(_stack->top, _data);
}

void freeStack (stack_t* _stack){
    freeLinkedList(_stack->top);
    _stack->top = NULL;
    free(_stack);
}