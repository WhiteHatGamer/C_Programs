#include "trie.h"

#include <stdio.h>
#include <stdlib.h>

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