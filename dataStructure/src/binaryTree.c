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
    if (_root == NULL){
        return;
    }
    printf(" - %d - ", _root->data);
    printf(" - Left - ");
    printTree(_root->left);
    printf(" - Right - ");
    printTree(_root->right);
    return;
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