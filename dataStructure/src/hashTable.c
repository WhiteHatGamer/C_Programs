#include "hashTable.h"
#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

person_t* hashTableArray[TABLE_SIZE];

unsigned int hash(char* _name){
    // if (_name==NULL){
    //     return -1;
    // }
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
        hashTableArray[i] = NULL;
    }
}

void printHashTable(){
    printf("Start\n");
    for(int i=0;i<TABLE_SIZE;i++){
        if(hashTableArray[i] == NULL){
            printf("\t%i\t---\n", i);
        }
        else{
            printf("\t%i\t%s\n", i, hashTableArray[i]->name);
        }
    }
    printf("End\n");
}

bool htInsert(person_t* _person){
    if (_person==NULL){
        return false;
    }
    unsigned int index = hash(_person->name);
    if(hashTableArray[index] != NULL){
        return false;
    }
    hashTableArray[index] = _person;
    return true;
}