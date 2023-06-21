#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(){
    // Create New Node
    linkedlist_t* tmp = createNode(999);
    linkedlist_t* Head = tmp;
    for (int i = 0; i < 15; i++)
    {
        tmp = createNode(i);
        tmp->next = Head;
        Head = tmp;
    }
    
    PrintList(Head);

    // Inserting in the beginning/somewhere
    linkedlist_t* l4 = (linkedlist_t*)malloc(sizeof(linkedlist_t));
    l4->data = 4;
    l4->next = Head;
    Head = l4;

    PrintList(Head);

    // Deleting a node from beggining
    deleteHead(&Head);
    
    PrintList(Head);

    freeLinkedList(Head);

    return 0;
}