#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "binaryTree.h"

int main(){
    // Create New Node
    linkedlist_t* Head = createNode(999);

    // Insert New Node
    for (int i = 0; i < 15; i++)
    {
        Head = insertHead(Head, i);
    }
    
    // Printing whole List
    printf("\nInsertHead");
    PrintList(Head);

    // Inserting in the beginning/somewhere
    linkedlist_t* l4 = (linkedlist_t*)malloc(sizeof(linkedlist_t));
    l4->data = 4;
    l4->next = Head;
    Head = l4;
    printf("\nInsertnorml");
    PrintList(Head);

    // Deleting a node from beggining
    deleteHead(&Head);
    printf("\ndeleteHead");
    PrintList(Head);

    for (int i=15; i<25; i++){
        insertEnd(Head, i);
    }
    printf("\nInsertend");
    PrintList(Head);

    printf("Node 999 found: %i\n",findNode(Head, 999));
    deleteNode(Head, 999);
    printf("Node 999 found: %i\n",findNode(Head, 999));

    insertIndex(Head, 9999, 5);
    printf("\nInserindex");
    PrintList(Head);

    updateNode(Head, 9999, 999);
    printf("\nInsertHead");
    PrintList(Head);

    freeLinkedList(Head);
    printf("List Freed\n");


    binarytree_t* Root = createTree(55);
    Root->left = createTree(99);
    Root->right = createTree(00);
    printf("Tree Created\n");

    printTree(Root);
    printf("Tree printed\n");

    freeTree(Root);
    printf("Tree Freed\n");

    return 0;
}