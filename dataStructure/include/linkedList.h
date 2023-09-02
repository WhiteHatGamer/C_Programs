#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedList{
    void* data;
    struct LinkedList* next;
}linkedlist_t;


#endif