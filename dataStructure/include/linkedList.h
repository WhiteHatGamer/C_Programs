#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedList{
    int data;
    struct LinkedList* next;
}linkedlist_t;

//TODO: Display List
void PrintList(linkedlist_t* _head);

//TODO: Create New Node
linkedlist_t* createNode(int _data);

//TODO: Insert at head

//TODO: Find Node

//TODO: Update Node

#endif