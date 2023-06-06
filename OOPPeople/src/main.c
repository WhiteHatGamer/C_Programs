#include <stdio.h>
#include "people.h"

int main(){
    //Creating a new Person
    people_t* Home[10];
    Home[0] = createPerson("Muhammed", 5);
    
    //Correcting the name and age of the person
    setPersonAge(Home[0], 6);
    setPersonName(Home[0], "Muhammed M");

    //Getting the name and age of peoples at home
    printf("Name : %s", Home[0]->name);
    printf("Age : %d", Home[0]->age);

    //Delete the person and free the memory
    deletePerson(Home[0]);

    return 0;
}