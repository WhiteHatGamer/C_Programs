#ifndef INT_LINKEDLIST_H
#define INT_LINKEDLIST_H

typedef struct IntLinkedList{
    int data;
    struct IntLinkedList* next;
}intlinkedlist_t;

#include <stdbool.h>

// Display List
void IntLLDisplay(intlinkedlist_t* _head);

// Create New Node
intlinkedlist_t* IntLLCreateNode(int _data);

// Delete a Node From Head
void IntLLDeleteHead(intlinkedlist_t** _head);

// Delete a node by value
void IntLLDeleteNode(intlinkedlist_t* _head, int _data);

// Insert at head
intlinkedlist_t* IntLLInsertHead(intlinkedlist_t* _head, int _data);

// Insert at End -> intlinkedlist_t
void IntLLInsertEnd(intlinkedlist_t* _head, int _data);

// Insert a Node at an Index startin at 0 -> intlinkedlist_t
void IntLLInsertIndex(intlinkedlist_t* _head, int _data, int index);

// Find Node by value -> bool
bool IntLLFindNode(intlinkedlist_t* _head, int _data);

// Update Node -> int
int IntLLUpdateNode(intlinkedlist_t* _head, int _data, int _newData);

// Merge Linked List -> intlinkedlist_t
intlinkedlist_t* IntLLMergeList(intlinkedlist_t* _head1, intlinkedlist_t* _head2);

// Free Memory
void IntLLFree(intlinkedlist_t* _head);

#endif