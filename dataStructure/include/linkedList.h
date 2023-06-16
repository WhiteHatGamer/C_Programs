#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedList{
    int data;
    struct LinkedList* next;
}linkedlist_t;

//Display List
void PrintList(linkedlist_t* _head);

//Create New Node
linkedlist_t* createNode(int _data);

//Delete a Node From Head
void deleteHead(linkedlist_t** _head);

//TODO: Insert at head

//TODO: Find Node

//TODO: Update Node

//Free Memory
void freeLinkedList(linkedlist_t* _head);

#endif