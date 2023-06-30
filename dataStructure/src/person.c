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