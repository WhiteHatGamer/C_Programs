#include "binaryTree.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

binarytree_t* btCreateNode(int _data){
    binarytree_t* branch = (binarytree_t*)malloc(sizeof(binarytree_t));
    if (branch==NULL){
        // No Memory
        return NULL;
    }
    branch->data = _data;
    branch->left = NULL;
    branch->right = NULL;
    return branch;
}

void btInsertNode(binarytree_t** _root, int _data){
    // Had Created node pointer for creating but tends to leak memory
    if(*_root==NULL){
        *_root = btCreateNode(_data);
        return;
    }
    if ((*_root)->data < _data){
        if((*_root)->right == NULL){
            (*_root)->right = btCreateNode(_data);;
        }
        else{
            btInsertNode(&(*_root)->right, _data);
        }
    }
    else if ((*_root)->data > _data)
    {
        if((*_root)->left == NULL){
            (*_root)->left = btCreateNode(_data);;
        }
        else{
            btInsertNode(&(*_root)->left, _data);
        }
    }
    else if((*_root)->data == _data){
        printf("[NOTE] Tried to insert Duplicate Value\n");
    }
    return;
}

binarytree_t* btSearchNodeDFS(binarytree_t* _root, int _data){
    // Had Created node pointer for creating but tends to leak memory
    if(_root==NULL){
        // NULL Validation
        return NULL;
    }
    if(_root->data == _data){
        return _root;
    }
    else if (_root->data < _data){
        return btSearchNodeDFS(_root->right, _data);
    }
    else if (_root->data > _data)
    {
        return btSearchNodeDFS(_root->left, _data);
    }
    return NULL;
}

binarytree_t* btSearchNodeBFS(binarytree_t* _root, int _data){
    if (_root->data == _data){
        return _root;
    }
    else{
        return NULL;
    }
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