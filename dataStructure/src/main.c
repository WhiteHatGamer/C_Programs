#include <stdio.h>
#include "linkedList.h"

int main(){
    linkedlist_t* Head;
    linkedlist_t* tmp;

    // Create New Node
    tmp = createNode(1);
    Head = tmp;
    tmp = createNode(2);
    tmp->next = Head;
    Head = tmp;
    tmp = createNode(3);
    tmp->next = Head;
    Head = tmp;

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