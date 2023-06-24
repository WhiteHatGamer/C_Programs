#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct BinaryTree{
    int data;
    struct BinaryTree* left;
    struct BinaryTree* right;
}binarytree_t;

binarytree_t* createTree(int _data);

void printTree(binarytree_t* _root);

void freeTree(binarytree_t* _root);

#endif