#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>
#include "person.h"

#define MAX_SIZE 256
#define TABLE_SIZE 10

extern person_t* hashTableArray[TABLE_SIZE];

// Hash Function
unsigned int hash(char* _name);

// Initialize every memory to NULL
void initHashTable();

// Print Hash Table
void printHashTable();

// Inset a person to hash Table
bool htInsert(person_t* _person);

// Find a person using Name
person_t* htSearchPerson(char* _name);

#endif