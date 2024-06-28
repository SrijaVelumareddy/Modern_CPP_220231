#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employee.h"
#include "Project.h"
#include<list>

using EmployeeContainer = std::list<Employee*>;
using ProjectContainer = std::list<Project*>;
using Predicate = std::function<bool(const Employee*)>;

void CreateObjects(EmployeeContainer& employees, ProjectContainer& projects);

void Deallocate(EmployeeContainer employees, ProjectContainer projects);

/*
    - Add a feature to filter employees based on filter predicates(functional style)[FILTER LAMBDA]
*/

void FilterEmployees(const Predicate fn,const EmployeeContainer& employees);

/*
    print project budget for all employees using employee data container
*/

void DisplayProjectBudget(const EmployeeContainer &employees);

#endif // FUNCTIONALITIES_H
