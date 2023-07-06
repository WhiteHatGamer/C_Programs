#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

person_t* createPerson(char* _name, int _age){
    person_t* person = (person_t*)malloc(sizeof(person_t));
    strcpy(person->name, _name);
    person->age = _age;
    return person;
}

void freePerson(person_t* _person){
    if(_person == NULL){
        return;
    }
    free(_person);
    return;
}

void freePersonArray (person_t* _person[], int _personSize){
    for(int i=0;i<_personSize; i++){
        freePerson(_person[i]);
    }
    return;
}