#ifndef HASHTABLE_H
#define HASHTABLE_H

#define MAX_SIZE 256
#define TABLE_SIZE 10

typedef struct Person{
    char name[MAX_SIZE];
    int age;
    //.. Add Others later
}person_t;

// Hash Function
unsigned int hash(char _name);

#endif