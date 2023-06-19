#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedList{
    int data;
    struct LinkedList* next;
}linkedlist_t;

// Display List
void PrintList(linkedlist_t* _head);

// Create New Node
linkedlist_t* createNode(int _data);

// Delete a Node From Head
void deleteHead(linkedlist_t** _head);

//TODO: Insert at head
linkedlist_t* insertHead(linkedlist_t* _head, int _data);

//TODO: Insert at End -> linkedlist_t

//TODO: Insert at Index -> linkedlist_t

//TODO: Find Node by value -> bool

//TODO: Update Node -> void

//TODO: Sorting List -> linkedlist_t

//TODO: Merge Linked List -> linkedlist_t

// Free Memory
void freeLinkedList(linkedlist_t* _head);

#endif 