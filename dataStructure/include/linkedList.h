#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedList{
    void* data;
    struct LinkedList* next;
}linkedlist_t;


// Display List
void llDisplay(linkedlist_t* _head);

// Create New Node
linkedlist_t* llCreateNode(void* _data);


// Insert at head
linkedlist_t* llInsertHead(linkedlist_t* _head, void* _data);

// Insert at End -> linkedlist_t
void llInsertEnd(linkedlist_t* _head, void* _data);

// Insert a Node at an Index startin at 0 -> linkedlist_t
void llInsertIndex(linkedlist_t* _head, void* _data, int index);


// Free Memory
void llFree(linkedlist_t* _head);

#endif