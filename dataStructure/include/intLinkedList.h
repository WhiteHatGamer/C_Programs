#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedList{
    int data;
    struct LinkedList* next;
}linkedlist_t;

#include <stdbool.h>

// Display List
void PrintList(linkedlist_t* _head);

// Create New Node
linkedlist_t* createNode(int _data);

// Delete a Node From Head
void deleteHead(linkedlist_t** _head);

// Delete a node by value
void deleteNode(linkedlist_t* _head, int _data);

// Insert at head
linkedlist_t* insertHead(linkedlist_t* _head, int _data);

// Insert at End -> linkedlist_t
void insertEnd(linkedlist_t* _head, int _data);

// Insert a Node at an Index startin at 0 -> linkedlist_t
void insertIndex(linkedlist_t* _head, int _data, int index);

// Find Node by value -> bool
bool findNode(linkedlist_t* _head, int _data);

// Update Node -> int
int updateNode(linkedlist_t* _head, int _data, int _newData);

// Merge Linked List -> linkedlist_t
linkedlist_t* mergeList(linkedlist_t* _head1, linkedlist_t* _head2);

// Free Memory
void freeLinkedList(linkedlist_t* _head);

#endif