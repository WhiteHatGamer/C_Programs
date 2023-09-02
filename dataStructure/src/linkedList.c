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

// Insert at end
void llInsertEnd(linkedlist_t* _head, void* _data){
    linkedlist_t* tmp = _head;
    while ((tmp->next) != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = llCreateNode(_data);
    return;
}

// Insert a Node at an Index startin at 0
void llInsertIndex(linkedlist_t* _head, void* _data, int index){
    linkedlist_t* tmp = _head;
    int current = 2; //because adding to previous node
    if (index<0){
        printf("Negative Indexing not yet supported");
        return;
    }
    while (current < index)
    {
        if (tmp == NULL){
            printf("Index Out of Bound...\n");
            return;
        }
        current++;
        tmp = tmp->next;
    }
    linkedlist_t* temp = llCreateNode(_data);
    temp->next = tmp->next;
    tmp->next = temp;
    return;
}

// Find a Node
bool llFindNode(linkedlist_t* _head, void* _data){
    linkedlist_t *tmp = _head;

    while (tmp != NULL)
    {
        if(tmp->data == _data){
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

// Update a Node
bool llUpdateNode(linkedlist_t* _head, void* _data, void* _newData){
    linkedlist_t* tmp = _head;
    while (tmp != NULL)
    {
        if (tmp->data == _data){
            tmp->data = _newData;
            return true;
        }
        tmp=tmp->next;
    }
    return false;
}

// Merge two Linked List
linkedlist_t* llMerge(linkedlist_t* _head1, linkedlist_t* _head2){
    linkedlist_t* tmp = _head1;
    while (tmp != NULL)
    {
        tmp = tmp->next;
    }
    tmp = _head2;
    return _head1;
}
