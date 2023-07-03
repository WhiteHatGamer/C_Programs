#include "hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

unsigned int hash(char* _name){
    int length = strnlen(_name, MAX_SIZE);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += _name[i];
        hash_value = (hash_value*_name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void initHashTable(){
    for(int i=0;i<TABLE_SIZE;i++){
        hashTable[i] = NULL;
    }
}