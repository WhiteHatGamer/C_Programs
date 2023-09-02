#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "intLinkedList.h"
#include "binaryTree.h"
#include "person.h"
#include "hashTable.h"
#include "intQueue.h"
#include "stack.h"
#include "bitFields.h"
#include "trie.h"
#include "graph.h"

void cleanupFunction(){
    atexit(freeBitfield);
    atexit(IntLLFree);
    atexit(intQFree);
    atexit(freeStack);
    atexit(freeTree);
    atexit(freeTrie);
    atexit(freeGraph);
}

void sleep(int ms){
    ms = ms * 5714285;
    for (int i=0;i<ms;i++)
    {
        i=i;
    }
    return;
}

int main(int argc, char** argv){
    atexit(cleanupFunction);

    // Create New Node
    intlinkedlist_t* Head = IntLLCreateNode(999);

    // Insert New Node
    for (int i = 0; i < 15; i++)
    {
        Head = IntLLInsertHead(Head, i);
    }
    
    // Printing whole List
    printf("\nInsertHead");
    IntLLDisplay(Head);

    // Inserting in the beginning/somewhere
    intlinkedlist_t* l4 = (intlinkedlist_t*)malloc(sizeof(intlinkedlist_t));
    l4->data = 4;
    l4->next = Head;
    Head = l4;
    printf("\nInsertnorml");
    IntLLDisplay(Head);

    // Deleting a node from beggining
    IntLLDeleteHead(&Head);
    printf("\ndeleteHead");
    IntLLDisplay(Head);

    for (int i=15; i<25; i++){
        IntLLInsertEnd(Head, i);
    }
    printf("\nInsertend");
    IntLLDisplay(Head);

    printf("Node 999 found: %i\n",IntLLFindNode(Head, 999));
    IntLLDeleteNode(Head, 999);
    printf("Node 999 found: %i\n",IntLLFindNode(Head, 999));

    IntLLInsertIndex(Head, 9999, 5);
    printf("\nInserindex");
    IntLLDisplay(Head);

    IntLLUpdateNode(Head, 9999, 999);
    printf("\nInsertHead");
    IntLLDisplay(Head);
    printf("LL Printed size: %lu\n", sizeof(*Head));

    IntLLFree(Head);
    printf("List Freed\n\n");


    binarytree_t* Root = btCreateNode(55);
    btInsertNode(&Root,00);
    btInsertNode(&Root,32);
    printf("Tree Created\n");

    printTree(Root);
    printf("Tree printed\n");

    btInsertNode(&Root,99);
    btInsertNode(&Root,66);
    btInsertNode(&Root,64);

    printf("Node Inserted\n");
    printTree(Root);

    binarytree_t* node = NULL;
    node = btSearchNodeDFS(Root, 55);
    if (node == NULL){
        printf("Tree Node Not Found\n");
    }else{
        printf("Node Found: %d\n", node->data);
    }
    node = btSearchNodeDFS(Root, 63);
    if (node == NULL){
        printf("Tree Node Not Found\n");
    }else{
        printf("Node Found: %d\n", node->data);
    }
    btNodeBFS(Root, 1, BFS_PRINT);
    btNodeBFS(Root, 32, BFS_SEARCH);
    btNodeBFS(Root, 64, BFS_PRINT | BFS_SEARCH);
    printf("Binary Tree Printed size: %lu\n", sizeof(*Root));

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
    printf("Hash Table Printed  size: %lu\n", sizeof(*hashTableArray));

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


    intqueue_t* queue = intQInit();

    for(int i=0;i<25;i++){
        intQEnqueue(queue, i);
    }
    intQDisplay(queue);
    printf("Queue Printed size: %lu\n", sizeof(queue));

    intQDequeue(queue);
    intQDisplay(queue);
    for(int i=0;i<25;i++){
        intQDequeue(queue);
    }

    intQDisplay(queue);
    if (intQIsEmpty(queue))
    {
        printf("Queue is Empty");
    }

    intQFree(queue);
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
    printf("Stack Printed size: %lu\n", sizeof(*stack));

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
    printf("\n size: %lu\n", sizeof(*bits));
    
    freeBitfield(bits);
    printf("BitFields Freed\n\n");


    trie_t* trieRoot=initTrie();
    printf("Trie Initialised\n");

    insertTrie(&trieRoot, "Hello");
    insertTrie(&trieRoot, "World");
    insertTrie(&trieRoot, "Dettol");
    insertTrie(&trieRoot, "Ditto");
    insertTrie(&trieRoot, "Raspberry");
    insertTrie(&trieRoot, "RaspberryPi");
    printf("Trie Inserted\n");

    if(searchTrie(trieRoot, "Dettol")){
        printf("Dettol is in Trie\n");
    }else{printf("Dettol Not in trie\n");}
    deleteTrie(trieRoot, "Dettol");
    printf("Dettol Deleted\n");
    if(searchTrie(trieRoot, "Dettol")){
        printf("Dettol is in Trie\n");
    }else{printf("Dettol Not in trie\n");}

    printTrie(trieRoot);
    printf("Trie Printed size: %lu\n", sizeof(*trieRoot));
    
    freeTrie(trieRoot);
    printf("Trie Freed\n\n");


    graph_t* graph = graphInit();

    int ar[5] = {0,1,2,3,4};
    insertGraphVertex(&graph, &ar[0]);
    insertGraphVertex(&graph, &ar[1]);
    insertGraphVertex(&graph, &ar[2]);
    insertGraphVertex(&graph, &ar[3]);
    if(insertGraphVertex(&graph, &ar[4])){
        printf("Graph Filled\nReference:\n0->%p\n1->%p\n2->%p\n3->%p\n4->%p\n", &ar[0], &ar[1], &ar[2], &ar[3], &ar[4]);
    }

    addGraphEdges(&graph, &ar[0], &ar[1]);
    addGraphEdges(&graph, &ar[0], &ar[4]);
    addGraphEdges(&graph, &ar[4], &ar[0]);
    addGraphEdges(&graph, &ar[1], &ar[4]);
    addGraphEdges(&graph, &ar[1], &ar[3]);
    addGraphEdges(&graph, &ar[1], &ar[2]);
    addGraphEdges(&graph, &ar[2], &ar[3]);
    if(addGraphEdges(&graph, &ar[3], &ar[4])){
        printf("Edges Added\n");
    }

    if(graphDeleteNode(&graph, &ar[2])){
        printf("Graph Node Deleted\n");
    }

    printDigraph(graph);
    if(printGraph(graph)){
        printf("Graph Printed\n");
    }

    graphSearchBFS(graph, NULL);
    printf("GRAPH BFS\n");
    
    printf("Graph Initialized size: %lu\n", sizeof(*graph));
    if(freeGraph(&graph)){
        printf("Graph Freed\n\n");
    }


    printf("argc: %i\n",argc);
    for(int i=0;i<argc;i++){
        printf("argv[%i]: %s\n", i, argv[i]);
    }

    return 0;
}