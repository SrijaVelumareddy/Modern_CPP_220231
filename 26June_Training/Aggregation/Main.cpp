#include "Functionalities.h"

int main() {
    EmployeeContainer employees;
    ProjectContainer projects;
    CreateObjects(employees, projects);
    //filter all employees whose project team count is above 10
    auto fn=[](const Employee* emp) {return emp->project().get().teamSize()>10;};
    FilterEmployees(fn,employees);
    Deallocate(employees, projects);
}