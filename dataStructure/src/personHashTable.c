#include "personHashTable.h"
#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

person_t* personHTArray[PHASHTABLE_SIZE];

unsigned int pHTHash(char* _name){
    // if (_name==NULL){
    //     return -1;
    // }
    int length = strnlen(_name, PHT_MAX_SIZE);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += _name[i];
        hash_value = (hash_value*_name[i]) % PHASHTABLE_SIZE;
    }
    return hash_value;
}

void pHTInit(){
    for(int i=0;i<PHASHTABLE_SIZE;i++){
        personHTArray[i] = NULL;
    }
}

void pHTDisplay(){
    printf("Start\n");
    for(int i=0;i<PHASHTABLE_SIZE;i++){
        if(personHTArray[i] == NULL){
            printf("\t%i\t---\n", i);
        }
        else if (personHTArray[i] == DELETED_NODE){
            printf("\t%i\t<deleted>\n", i);
        }
        else{
            printf("\t%i\t%s\n", i, personHTArray[i]->name);
        }
    }
    printf("End\n");
}

bool pHTInsert(person_t* _person){
    if (_person==NULL){
        return false;
    }
    unsigned int index = pHTHash(_person->name);
    for (int i = 0; i < PHASHTABLE_SIZE; i++) {
        int try = (i + index) % PHASHTABLE_SIZE;
        if(personHTArray[try] == NULL || personHTArray[try] == DELETED_NODE) {
            personHTArray[try] = _person;
            return true;
        }
    }
    return false;
}

person_t* pHTSearch(char* _name){
    unsigned int indx = pHTHash(_name);
    for (int i = 0; i < PHASHTABLE_SIZE; i++) {
        int try = (i + indx) % PHASHTABLE_SIZE;
        if(personHTArray[try] == NULL){
            return NULL;
        }
        if(personHTArray[try] == DELETED_NODE){
            continue;
        }
        if (strncmp(personHTArray[try]->name, _name, PHASHTABLE_SIZE)==0){
            return personHTArray[try];
        }
    }
    return NULL;
}

person_t* pHTDelete(char* _name){
    unsigned int indx = pHTHash(_name);
    for (int i = 0; i < PHASHTABLE_SIZE; i++) {
        int try = (i + indx) % PHASHTABLE_SIZE;
        if(personHTArray[try] == NULL){
            return NULL;
        }
        if(personHTArray[try] == DELETED_NODE){
            continue;
        }
        if (personHTArray[try] != NULL && strncmp(personHTArray[try]->name, _name, PHASHTABLE_SIZE)==0){
            person_t* tmp = personHTArray[try];
            personHTArray[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}
