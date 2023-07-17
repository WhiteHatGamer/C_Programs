#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct BinaryTree{
    int data;
    struct BinaryTree* left;
    struct BinaryTree* right;
}binarytree_t;

// Creating a Tree Node
binarytree_t* btCreateNode(int _data);

// Insert a Node in Tree
void btInsertNode(binarytree_t** _root, int _data);

//TODO: search for a node in tree

//TODO: bfs
binarytree_t* btSearchNodeBFS(binarytree_t* _root, int _data);

//TODO: dfs

//TODO: Delete a node in tree
//TODO: without child, one chile, two child

//TODO: in order traversal in a tree
void printTree(binarytree_t* _root);

//TODO: pre order traversal in a tree

//TODO: post order traversal in a tree

void freeTree(binarytree_t* _root);

#endif