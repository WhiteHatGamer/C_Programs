#include <stdio.h>
#include "linkedList.h"

int main(){
    linkedlist_t l1, l2, l3;
    linkedlist_t* Head;

    // Create New Node
    l1.data = 1;
    l2.data = 2;
    l3.data = 3;
    Head = &l1;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = NULL;

    
    PrintList(Head);

    // Inserting in the beginning/somewhere
    linkedlist_t l4;
    l4.data = 4;
    l4.next = Head;
    Head = &l4;

    PrintList(Head);

    // Deleting a node from beggining
    Head = Head->next;
    
    PrintList(Head);

    return 0;
}