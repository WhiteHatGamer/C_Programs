#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

binarytree_t* createTree(int _data){
    binarytree_t* branch = (binarytree_t*)malloc(sizeof(binarytree_t));
    branch->data = _data;
    branch->left = NULL;
    branch->right = NULL;
    return branch;
}

void printTabs(int num){
    for (int i=0;i<num;i++){
        printf("\t");
    }
}

void printTreeRec(binarytree_t* _root, int level){
    if (_root == NULL){
        printTabs(level);
        printf("(NULL)\n");
        return;
    }
    printTabs(level);
    printf("(%d)\n", _root->data);
    printTabs(level);

    printf("Left: ");
    printTreeRec(_root->left, level+1);
    printTabs(level);

    printf("Right: ");
    printTreeRec(_root->right, level+1);
    printTabs(level);

    printf("\n");
    return;
}

void printTree(binarytree_t* _root){
    printf("\n");
    printTreeRec(_root, 0);
    printf("\n");
}

void freeTree(binarytree_t* _root){
    if (_root == NULL){
        return;
    }
    freeTree(_root->left);
    freeTree(_root->right);
    free (_root);
    return;
}