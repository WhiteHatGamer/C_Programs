#ifndef PEOPLE_H
#define PEOPLE_H

//Structure Definition
typedef struct People{
    char* name;
    int age;
}people_t;

// Function Prototypes
people_t* createPerson(const char* _name, int _age);
void deletePerson(people_t* This);
void setPersonName(people_t* This, const char* _name);
void setPersonAge(people_t* This, int _age);
const char* getPersonName(const people_t* This);
int getPersonAge(const people_t* This);

#endif