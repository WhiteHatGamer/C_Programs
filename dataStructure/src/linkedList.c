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
linkedlist_t* createNode(int _data){
    linkedlist_t* result = (linkedlist_t*)malloc(sizeof(linkedlist_t));
    if (result != NULL){
        result->data = _data;
        result->next = NULL;
    }
    return result;
}

//TODO: Insert at head
linkedlist_t* insertHead(linkedlist_t* _head, int _data){
    linkedlist_t* tmp = (linkedlist_t*)malloc(sizeof(linkedlist_t));
    tmp->data = _data;
    tmp->next = _head;
    _head = tmp;
    return tmp;
}

//Delete a nodfe from the beginning
void deleteHead(linkedlist_t** _head){
    if(*_head != NULL){
        linkedlist_t* tmp = *_head;
        *_head = (*_head)->next;
        free(tmp);
    }
}
//TODO: Find Node
//TODO: Update Node

//TODO: IMP: Delete/Free Memory
void freeLinkedList(linkedlist_t* _head){
    linkedlist_t* current = _head;
    linkedlist_t* next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}