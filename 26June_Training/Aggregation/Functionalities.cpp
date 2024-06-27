#include "Functionalities.h"

void CreateObjects(Employee **employees, Project **projects, unsigned int size)
{
    projects[0] = new Project("c.111", 10, 1000.0f);
    employees[0] = new Employee(101, "Harshit", *projects[0]);

    projects[1] = new Project("c.221", 50, 11000.0f);
    employees[1] = new Employee(101, "Rohan", *projects[1]);

    projects[2] = new Project("c.331", 20, 10000.0f);
    employees[2] = new Employee(101, "Riya", *projects[2]);
}

void Deallocate(Employee **employees, Project **projects, unsigned int size)
{
    for(unsigned int i = 0; i < size; i++ ) {
        delete projects[i];
        delete employees[i];
    }
}
