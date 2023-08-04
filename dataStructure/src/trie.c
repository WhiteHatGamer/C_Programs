#include "trie.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

trie_t* initTrie(){
    trie_t* _root = (trie_t*)malloc(sizeof(trie_t));
    if(!_root){
        // NULL validation
        return NULL;
    }

    for (int i=0;i<TRIE_SIZE;i++){
        _root->child[i] = NULL;
    }
    _root->terminal = false;

    return _root;
}

bool insertTrie(trie_t** _root, char* _signedText){
    if (*_root==NULL)
    {
        *_root = initTrie();
    }
    unsigned char* text = (unsigned char*)_signedText;
    trie_t* tmp= *_root;
    int length = strlen(_signedText);
    for(int i=0;i<length;i++){
        if(tmp->child[text[i]] == NULL){
            tmp->child[text[i]] = initTrie();
        }
        tmp = tmp->child[text[i]];
    }
    if (tmp->terminal){
        return false;
    }else{
        tmp->terminal = true;
    }
    // Returns true if the word was successfully inserted.
    return true;
}

bool freeTrie(trie_t* _root){
    if (_root == NULL)
    {
        return false;
    }
    for (int i = 0; i < TRIE_SIZE; i++)
    {
        freeTrie(_root->child[i]);
    }
    free(_root);
    return true;
}