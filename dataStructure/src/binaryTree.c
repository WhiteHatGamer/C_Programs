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

void printTree(binarytree_t* _root){
    return;
}

void freeTree(binarytree_t* _root){
    free(_root);
    return;
}