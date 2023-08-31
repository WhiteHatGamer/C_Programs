#include "intLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

// Display List\Traversal
void IntLLDisplay(intlinkedlist_t* _head){
    intlinkedlist_t *tmp = _head;

    while(tmp != NULL){
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

// Create New Node
intlinkedlist_t* IntLLCreateNode(int _data){
    intlinkedlist_t* result = (intlinkedlist_t*)malloc(sizeof(intlinkedlist_t));
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
void IntLLDeleteHead(intlinkedlist_t** _head){
    if(*_head != NULL){
        intlinkedlist_t* tmp = *_head;
        *_head = (*_head)->next;
        free(tmp);
    }
}

// Delete a node by Value
void IntLLDeleteNode(intlinkedlist_t* _head, int _data){
    if (IntLLFindNode(_head, _data)){
        intlinkedlist_t* tmp = _head;
        while(tmp!=NULL){
            if ((tmp->next)->data == _data)
            {
                IntLLDeleteHead(&(tmp->next));
                return;
            }
            tmp = tmp->next;
        }
    }
    return;
}

// Insert at head
intlinkedlist_t* IntLLInsertHead(intlinkedlist_t* _head, int _data){
    intlinkedlist_t* tmp = IntLLCreateNode(_data);
    tmp->next = _head;
    _head = tmp;
    return tmp;
}

// Insert at end
void IntLLInsertEnd(intlinkedlist_t* _head, int _data){
    intlinkedlist_t* tmp = _head;
    while ((tmp->next) != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = IntLLCreateNode(_data);
    return;
}

// Insert a Node at an Index startin at 0
void IntLLInsertIndex(intlinkedlist_t* _head, int _data, int index){
    intlinkedlist_t* tmp = _head;
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
    intlinkedlist_t* temp = IntLLCreateNode(_data);
    temp->next = tmp->next;
    tmp->next = temp;
    return;
}

// Find a Node
bool IntLLFindNode(intlinkedlist_t* _head, int _data){
    intlinkedlist_t *tmp = _head;

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
int IntLLUpdateNode(intlinkedlist_t* _head, int _data, int _newData){
    intlinkedlist_t* tmp = _head;
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
intlinkedlist_t* IntLLMergeList(intlinkedlist_t* _head1, intlinkedlist_t* _head2){
    intlinkedlist_t* tmp = _head1;
    while (tmp != NULL)
    {
        tmp = tmp->next;
    }
    tmp = _head2;
    return _head1;
}

// Delete/Free Memory
void IntLLFree(intlinkedlist_t* _head){
    intlinkedlist_t* current = _head;
    intlinkedlist_t* next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}