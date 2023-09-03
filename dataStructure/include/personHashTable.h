#ifndef PERSON_HASHTABLE_H
#define PERSON_HASHTABLE_H

#include <stdbool.h>
#include "person.h"

#define PHASHTABLE_SIZE 10
#define DELETED_NODE (person_t*)(0xFFFFFFFFFFFFFFFFUL)

extern person_t* personHTArray[PHASHTABLE_SIZE];

// Hash Function
unsigned int pHTHash(char* _name);

// Initialize every memory to NULL
void pHTInit();

// Print Hash Table
void pHTDisplay();

// Inset a person to pHTHash Table
bool pHTInsert(person_t* _person);

// Find a person using Name
person_t* pHTSearch(char* _name);

// Delete a person from the table array
person_t* pHTDelete(char* _name);

#endif