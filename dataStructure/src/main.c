#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"
#include "binaryTree.h"
#include "person.h"
#include "hashTable.h"
#include "queue.h"
#include "stack.h"
#include "bitFields.h"

void sleep(int ms){
    ms = ms * 5714285;
    for (int i=0;i<ms;i++)
    {
        i=i;
    }
    return;
}

int main(int argc, char** argv){
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
    printf("List Freed\n\n");


    binarytree_t* Root = btCreateNode(55);
    Root->left = btCreateNode(00);
    Root->right = btCreateNode(66);
    printf("Tree Created\n");

    printTree(Root);
    printf("Tree printed\n");

    binarytree_t* Node = btCreateNode(99);
    btInsertNode(Root, Node);
    printf("Node Inserted\n");
    printTree(Root);

    freeTree(Root);
    printf("Tree Freed\n\n");


    initHashTable();
    printHashTable();
    printf("\n");
    person_t* person[10] = {NULL};
    person[0] = createPerson("Bob", 23);
    person[1] = createPerson("alex", 35);
    person[2] = createPerson("joyce", 30);
    person[3] = createPerson("JohnCena", 45);
    person[4] = createPerson("Doctor", 256);
    htInsert(person[0]);
    htInsert(person[1]);
    htInsert(person[2]);
    htInsert(person[3]);
    htInsert(person[4]);
    printHashTable();

    person_t* tmp = htSearchPerson("Bob");
    if (tmp==NULL){
        printf("Person Not Found\n");
    }
    else{
        printf("Person Found: %s\n", tmp->name);
    }

    tmp = htSearchPerson("Unknown");
    if (tmp==NULL){
        printf("Person Not Found\n");
    }
    else{
        printf("Person Found: %s\n", tmp->name);
    }

    int personSize = sizeof(person)/sizeof(person[0]);
    for(int i=0;i<personSize;i++){
        if (person[i] != NULL){
            htDeletePerson(person[i]->name);
        }
    }
    freePerson(&person[0]);
    freePersonArray(person, personSize);
    printf("Person Freed\n");
    printHashTable();


    queue_t* queue = initQueue();

    for(int i=0;i<25;i++){
        enqueue(queue, i);
    }
    qPrint(queue);

    dequeue(queue);
    qPrint(queue);
    for(int i=0;i<25;i++){
        dequeue(queue);
    }

    qPrint(queue);
    if (qIsEmpty(queue))
    {
        printf("Queue is Empty");
    }

    freeQueue(queue);
    printf("\nQueue Freed\n");
    

    stack_t* stack = initStack();
    printf("\nStack Initialized\n");

    for (int i=0;i<16;i++){
        if (i==14){push(stack,999);}
        push(stack, i);
    }
    printf("Stack Pushed\n");
    printStack(stack);

    pop(stack);
    pop(stack);
    pop(stack);
    printStack(stack);

    freeStack(stack);
    printf("Stack Freed\n");

    printf("\n");
    bitfield_t* bits = initBitField();
    #define LOG_SR  0x01
    #define LOG_TM  0x02
    #define LOG_USR 0x04
    #define LOG_DIR 0x08

    //bits->options |= 0x01; //1
    //bits->options |= 0x02; //2
    //bits->options |= 0x04; //4
    //bits->options |= 0x08; //8
    bits->options |= 0x0F; //15
    char* message = "Hellow World!";
    if (bits->options & LOG_SR){
        printf("1: ");
    }
    if (bits->options & LOG_TM){
        printf("14/07/23 19:16:00: ");
    }
    if (bits->options & LOG_USR){
        printf("WHG: ");
    }
    if (bits->options & LOG_DIR){
        printf("C://User/Documents $");
    }
    printf("%s\n\n", message);

    for (int i=0;i< 32;i++){
        printBin(bits->small,2);
        printf(" ");
        printBin(bits->medium,3);
        printf(" ");
        printBin(bits->large,4);
        printf("\n");
        bits->small++;
        bits->medium++;
        bits->large++;
    }

    SET_BIT(bits->bit64, 10);
    SET_BIT(bits->bit64, 2);
    SET_BIT(bits->bit64, 16);
    SET_BIT(bits->bit64, 35);

    Print64Bit(bits->bit64);
    printf("\n");
    CLR_BIT(bits->bit64, 16);
    Print64Bit(bits->bit64);
    printf("\n");
    
    freeBitfield(bits);
    printf("BitFields Freed\n\n");


    printf("argc: %i\n",argc);
    for(int i=0;i<argc;i++){
        printf("argv[%i]: %s\n", i, argv[i]);
    }

    return 0;
}