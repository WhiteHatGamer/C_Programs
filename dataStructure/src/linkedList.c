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

// Delete a node by Value
void llDeleteNode(linkedlist_t* _head, void* _data){
    if (llFindNode(_head, _data)){
        linkedlist_t* tmp = _head;
        while(tmp!=NULL){
            if ((tmp->next)->data == _data)
            {
                llDeleteHead(&(tmp->next));
                return;
            }
            tmp = tmp->next;
        }
    }
    return;
}

// Insert at head
linkedlist_t* llInsertHead(linkedlist_t* _head, void* _data){
    linkedlist_t* tmp = llCreateNode(_data);
    tmp->next = _head;
    _head = tmp;
    return tmp;
}

