#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedList{
    void* data;
    struct LinkedList* next;
}linkedlist_t;


// Create New Node
linkedlist_t* createNode(void* _data);


// Insert at head
linkedlist_t* insertHead(linkedlist_t* _head, void* _data);

// Insert at End -> linkedlist_t
void insertEnd(linkedlist_t* _head, void* _data);

// Insert a Node at an Index startin at 0 -> linkedlist_t
void insertIndex(linkedlist_t* _head, void* _data, int index);


#endif