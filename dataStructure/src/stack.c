#include "stack.h"
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

stack_t* initStack(){
    stack_t* _stack = (stack_t*)malloc(sizeof(stack_t));
    if(!_stack){
        // Null Validation
        return NULL;
    }
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

void pop(stack_t* _stack){
    if (_stack->top == NULL){
        // Stack Empty;
        return;
    }
    else{
        linkedlist_t* tmp = _stack->top;
        _stack->top = _stack->top->next;
        free(tmp);
        return;
    }
}

void printStack(stack_t* _stack){
    printf("\n---\n");
    linkedlist_t* tmp = _stack->top;
    while (tmp!= NULL){
        printf("%d\n",tmp->data);
        tmp = tmp->next;
    }
    printf("---\n\n");
    return;
}

void freeStack (stack_t* _stack){
    freeLinkedList(_stack->top);
    _stack->top = NULL;
    free(_stack);
}