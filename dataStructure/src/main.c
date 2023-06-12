#include <stdio.h>
#include "linkedList.h"

int main(){
    linkedlist_t* Head = NULL;
    linkedlist_t* tmp;

    // Create New Node
    tmp = createNode(999);
    tmp->next = Head;
    Head = tmp;
    for (int i = 0; i < 25; i++)
    {
        tmp = createNode(i);
        tmp->next = Head;
        Head = tmp;
    }
    
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