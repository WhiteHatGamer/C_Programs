#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/people.h"

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

// Function to set the name of a Person
void setPersonName(people_t* This, const char* _name){
    if (This->name){
        free(This->name);
    }
    This->name = (char*)malloc(strlen(_name)+1);
    strcpy(This->name, _name);
}
//Same Function but uses strdup function so that we don't need to allocate using malloc seperately.
void setPersonNamestrdup(people_t* This, const char* _name){
    free(This->name);
    This->name = strdup(_name);
}

// Function to set the age of a Person
void setPersonAge(people_t* This, int _age){
    This->age = _age;
}

// Function to get the name of a Person
const char* getPersonName(const people_t* This){
    return This->name;
}

// Function to get the age of a Person
int getPersonAge(const people_t* This){
    return This->age;
}