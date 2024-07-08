/*
    Employee
        - int id, string name, string designation, categorical Department, float salary
*/

#include<iostream>
#include "Department.h"

class Employee
{
private: //In class initialization
    unsigned int m_id {0}; //default value for m_id
    std::string m_name {""}; //default value for m_name
    std::string m_designation {"executive"};
    Department m_dept {Department::IT};
    float m_salary {0.0f};

public:
    Employee()=default; //enable the default constructor
    ~Employee()=default; //enable the default destructor
    Employee(const Employee& other)=delete;//disable copy
    //any thing you want to enable-default, disable-delete
    Employee& operator=(const Employee& other) = delete;
    Employee(Employee&& other) = delete; //move constructor
    Employee& operator=(Employee&& other) = delete;

    Employee(unsigned int id, std::string name, std::string des, Department dept, float salary) : m_id {id}, m_name {name}, m_designation {des}, m_dept {dept}, m_salary {salary} //member list initialization
    {}
        /*
        this->m_dept=dept;
        this->m_designation=des;
        this->m_id=id;
        this->m_name=name;
        this->salary=salary;
        */
};

int main() {
    //Employee* e1 = new Employee(); 
    Employee* ptr=nullptr; //declaration of a pointer of type Employee [uniform initialization]

    ptr = new Employee(); //default constructor

    ptr = new Employee(101, "Srija" , "Intern", Department::IT, 9000.0f); //parameterized constructor

    int n1 {10};
    int* ptr {nullptr};
    int arr[3] {1,2,3};
    Employee e1{}; //default constructor
    Employee e2{102, "Megha", "Admin", Department::ADMIN, 8000.0f};
    //std::list<int> data {1,2,3,4,5};
}