#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ID = -1;

// CRUD
// create, read, update, delete
// update : delete + create


struct Mentor
{
    int ID;
    char name[255];
    int age;
    double gpa;
};

Mentor *createMentor(char *name, int age, double gpa)
{
    ID++;
    Mentor *newMentor = (Mentor *)malloc(sizeof(Mentor));

    newMentor->ID = ID;
    newMentor->age = age;
    newMentor->gpa = gpa;
    strcpy(newMentor->name, name);

    return newMentor;
}

void printMentor(Mentor *m)
{
    printf("Name: %s\n", m->name);
    printf("Age: %d\n", m->age);
    printf("GPA: %.2lf\n", m->gpa);
}

void deleteMentor(Mentor *m)
{
    ID--;
    free(m);
}

int main()
{
    // Static Memory Alloc
    // Mentor m; 
    // m.age = 10;
    // m.gpa = 3.90;
    // strcpy(m.name, "Test");

    // Dynamic Memory Alloc
    Mentor *m = createMentor((char *)"Testtt", 12, 3.90);
    printMentor(m);
    deleteMentor(m);

    // Show null values
    // BUT might still show some values caused by undefined behaviour
    printMentor(m);

    return 0;
}