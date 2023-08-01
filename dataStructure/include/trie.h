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

// Frees trie allocated by malloc
bool freeTrie(trie_t* _root);

#endif