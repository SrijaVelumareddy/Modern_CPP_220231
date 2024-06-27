#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include<functional>
#include "Project.h"

using ProjectRef=std::reference_wrapper<Project>;

class Employee
{
private:
    int _id;
    std::string _name;
    ProjectRef _project;
public:
    Employee(int id, std::string name, ProjectRef pr);
    ~Employee();
};

#endif // EMPLOYEE_H

/*
    Project&

    lvalue Reference to a Project
*/
