/* File: structs.cpp
 * Name: Paulo Lemus
 * Date: 2/2/2017
 */

#include <stdio.h>
#include <string.h>

struct Id{
    char name[100];
    int age;
    double weight;
};

int main(){

    struct Id person1, person2;
    
    strcpy(person1.name, "Alice");
    person1.age = 23;
    person1.weight = 160.4;

    strcpy(person2.name, "Bob");
    person2.age = 24;
    person2.weight = 202.8;

    printf("%s is %d and weighs %lflbs\n", person1.name, person1.age, person1.weight);
    printf("%s is %d and weighs %lflbs\n", person2.name, person2.age, person2.weight);

    return 0;
}
