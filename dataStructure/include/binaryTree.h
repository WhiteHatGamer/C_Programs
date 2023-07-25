#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct BinaryTree{
    int data;
    struct BinaryTree* left;
    struct BinaryTree* right;
}binarytree_t;

typedef enum {
    BFS_SEARCH = 0x01,
    BFS_PRINT = 0x02
} BFS_Operation;

// Creating a Tree Node
binarytree_t* btCreateNode(int _data);

// Insert a Node in Tree
void btInsertNode(binarytree_t** _root, int _data);

//TODO: search for a node in tree
//TODO: bfs
binarytree_t* btNodeBFS(binarytree_t* _root, int _data, BFS_Operation options);

// dfs
binarytree_t* btSearchNodeDFS(binarytree_t* _root, int _data);

//TODO: Delete a node in tree
//TODO: without child, one chile, two child

// in order traversal in a tree
void printTree(binarytree_t* _root);

//TODO: pre order traversal in a tree

//TODO: post order traversal in a tree

void freeTree(binarytree_t* _root);

#endif