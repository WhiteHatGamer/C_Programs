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

// Delete a Node From Head
void llDeleteHead(linkedlist_t** _head);

// Delete a node by value
void llDeleteNode(linkedlist_t* _head, void* _data);

// Insert at head
linkedlist_t* llInsertHead(linkedlist_t* _head, void* _data);

// Insert at End -> linkedlist_t
void llInsertEnd(linkedlist_t* _head, void* _data);

// Insert a Node at an Index startin at 0 -> linkedlist_t
void llInsertIndex(linkedlist_t* _head, void* _data, int index);


// Merge Linked List -> linkedlist_t
linkedlist_t* llMerge(linkedlist_t* _head1, linkedlist_t* _head2);

// Free Memory
void llFree(linkedlist_t* _head);

#endif