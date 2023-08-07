#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>

#define TRIE_SIZE 256

// Struct Definition
typedef struct Trie
{
    struct Trie* child[TRIE_SIZE];
    bool terminal;
}trie_t;

// Trie Initialisation Returns -> trie_t*
trie_t* initTrie();

// Insert Into Trie
bool insertTrie(trie_t** _root, char* _signedText);

// Check if has Children
bool trieHasChild(trie_t* node);

// Delete From Trie
bool deleteTrie(trie_t* _root, char* _signedText);

// Search From Trie
bool searchTrie(trie_t* _root, char* _signedText);

// Print Trie
void printTrie(trie_t* _root);

// Frees trie allocated by malloc
bool freeTrie(trie_t* _root);

#endif