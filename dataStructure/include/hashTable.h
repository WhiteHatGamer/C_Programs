#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>
#include "person.h"

#define MAX_SIZE 256
#define TABLE_SIZE 10

person_t* hashTable[TABLE_SIZE];

// Hash Function
unsigned int hash(char* _name);

// Initialize every memory to NULL
void initHashTable();

#endif