#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

//TODO: Display List
void PrintList(linkedlist_t* _head){
    linkedlist_t *tmp = _head;

    while(tmp != NULL){
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
//TODO: Create New Node
linkedlist_t* createNode(linkedlist_t** _head, int _data){
    linkedlist_t* result = (linkedlist_t*)malloc(sizeof(linkedlist_t));
    if (result != NULL){
        result->data = _data;
        result->next = NULL;
        *_head = result;
    }
    return result;
}

//TODO: Insert at head
//TODO: Find Node
//TODO: Update Node
