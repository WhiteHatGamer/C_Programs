#include "linkedList.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// Create New Node
linkedlist_t* llCreateNode(void* _data){
    linkedlist_t* result = (linkedlist_t*)malloc(sizeof(linkedlist_t));
    if (result != NULL){
        result->data = _data;
        result->next = NULL;
    }
    else{
        // Null Validation
        return NULL;
    }
    return result;
}
