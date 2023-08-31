#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

// Display List\Traversal
void PrintList(linkedlist_t* _head){
    linkedlist_t *tmp = _head;

    while(tmp != NULL){
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

// Create New Node
linkedlist_t* createNode(int _data){
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
void deleteHead(linkedlist_t** _head){
    if(*_head != NULL){
        linkedlist_t* tmp = *_head;
        *_head = (*_head)->next;
        free(tmp);
    }
}

// Delete a node by Value
void deleteNode(linkedlist_t* _head, int _data){
    if (findNode(_head, _data)){
        linkedlist_t* tmp = _head;
        while(tmp!=NULL){
            if ((tmp->next)->data == _data)
            {
                deleteHead(&(tmp->next));
                return;
            }
            tmp = tmp->next;
        }
    }
    return;
}

// Insert at head
linkedlist_t* insertHead(linkedlist_t* _head, int _data){
    linkedlist_t* tmp = createNode(_data);
    tmp->next = _head;
    _head = tmp;
    return tmp;
}

// Insert at end
void insertEnd(linkedlist_t* _head, int _data){
    linkedlist_t* tmp = _head;
    while ((tmp->next) != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = createNode(_data);
    return;
}

// Insert a Node at an Index startin at 0
void insertIndex(linkedlist_t* _head, int _data, int index){
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
    linkedlist_t* temp = createNode(_data);
    temp->next = tmp->next;
    tmp->next = temp;
    return;
}

// Find a Node
bool findNode(linkedlist_t* _head, int _data){
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
int updateNode(linkedlist_t* _head, int _data, int _newData){
    linkedlist_t* tmp = _head;
    while (tmp != NULL)
    {
        if (tmp->data == _data){
            tmp->data = _newData;
            return 1;
        }
        tmp=tmp->next;
    }
    return 0;
}

// Merge two Linked List
linkedlist_t* mergeList(linkedlist_t* _head1, linkedlist_t* _head2){
    linkedlist_t* tmp = _head1;
    while (tmp != NULL)
    {
        tmp = tmp->next;
    }
    tmp = _head2;
    return _head1;
}

// Delete/Free Memory
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