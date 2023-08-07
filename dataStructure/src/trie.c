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

// Find if Trie Node has Child
bool trieHasChild(trie_t* node){
    if (node== NULL){
        return false;
    }
    for (int i=0;i<TRIE_SIZE;i++){
        if (node->child[i] != NULL){
            // Trie Node has atleast one child
            return true;
        }
    }
    return false;
}

bool deleteTrie(trie_t* _root, char* _signedText){
    if (_root == NULL){
        return false;
    }
    unsigned char* text = (unsigned char*)_signedText;
    trie_t* tmp = _root;
    int length = strlen(_signedText);
    for(int i=0;i<length;i++){
        if(tmp->child[text[i]] == NULL){
            return false;
        }
        tmp = tmp->child[text[i]];
    }
    tmp->terminal = false;
    return true;
}

bool searchTrie(trie_t* _root, char* _signedText){
    if (_root == NULL){
        return false;
    }
    unsigned char* text = (unsigned char*)_signedText;
    trie_t* tmp = _root;
    int length = strlen(_signedText);
    for(int i=0;i<length;i++){
        if(tmp->child[text[i]==NULL]){
            return false;
        }
        tmp = tmp->child[text[i]];
    }
    return (tmp->terminal);
}

void printTrieRec(trie_t* _node, unsigned char* _prefix, int length){
    unsigned char _newPrefix[length+2];
    memcpy(_newPrefix, _prefix, length);
    _newPrefix[length+1] = 0;
    if(_node->terminal){
        printf("WORD: %s\n", _prefix);
    }
    for (int i=0;i<TRIE_SIZE; i++){
        if(_node->child[i] != NULL){
            _newPrefix[length] = i;
            printTrieRec(_node->child[i], _newPrefix, length+1);
        }
    }
}

void printTrie(trie_t* _root){
    if (_root == NULL){
        printf("Trie EMPTY\n");
        return;
    }
    printTrieRec(_root, NULL, 0);
    return;
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