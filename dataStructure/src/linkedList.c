#include "linkedList.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Display List\Traversal
void llDisplay(linkedlist_t* _head){
    linkedlist_t *tmp = _head;

    while(tmp != NULL){
        printf("%p -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

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

// Delete a node from the beginning
void llDeleteHead(linkedlist_t** _head){
    if(*_head != NULL){
        linkedlist_t* tmp = *_head;
        *_head = (*_head)->next;
        free(tmp);
    }
}

