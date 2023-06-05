#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "people.h"

// Function to create a new Person
people_t* createPerson(const char* _name, int _age){
    people_t* Person = (people_t*)malloc(sizeof(people_t));
    Person->name = (char*)malloc(sizeof(strlen(_name) + 1));
    strcpy(Person->name, _name);
    Person->age = _age;
    return Person;
}

//Funtion to Destroy a Person and Free Memory
void deletePerson(people_t* This){
    free(This->name);
    free(This);
}