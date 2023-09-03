#ifndef PERSON_H
#define PERSON_H

#define PHT_MAX_SIZE 256

typedef struct Person{
    char name[PHT_MAX_SIZE];
    int age;
    //.. Add Others later
}person_t;

person_t* createPerson(char* _name, int _age);

void freePerson(person_t** _person);

void freePersonArray (person_t* _person[], int _personSize);

#endif