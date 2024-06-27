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

    ProjectRef project() const { return _project; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "_id: " << rhs._id
           << " _name: " << rhs._name
           << " _project: " << rhs._project.get();
        return os;
    }
};

#endif // EMPLOYEE_H

/*
    Project&

    lvalue Reference to a Project
*/
