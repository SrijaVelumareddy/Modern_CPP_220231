#include<memory>
#include<iostream>
#include<list>
#include<algorithm>
#include<numeric>
#include"Employee.h"

using StackMemoryEmployees = std::list<Employee>;
using RawPointerHeapEmployees = std::list<Employee*>;
using EmployeePtr = std::shared_ptr<Employee>;
using SmartPointerHeapEmployees = std::list<EmployeePtr>;

void CreateObjects(StackMemoryEmployees& stackemployees){
    stackemployees.emplace_back(101,"Srija",9000.0f,22,11.1f);
    stackemployees.emplace_back(102,"Megha",8900.0f,23,23.1f);
    stackemployees.emplace_back(103,"Siri",7800.0f,24,34.1f);
}

void CreateObjects(RawPointerHeapEmployees& rawptremployees){
    rawptremployees.emplace_back(new Employee(101,"Srija",9000.0f,22,11.1f));
    rawptremployees.emplace_back(new Employee(102,"Megha",8900.0f,23,23.1f));
    rawptremployees.emplace_back(new Employee(103,"Siri",7800.0f,24,34.1f));
}

void CreateObjects(SmartPointerHeapEmployees& smartptremployees){
    smartptremployees.emplace_back(std::make_shared<Employee>(101,"Srija",9000.0f,26,11.1f));
    smartptremployees.emplace_back(std::make_shared<Employee>(102,"Megha",8900.0f,29,23.1f));
    smartptremployees.emplace_back(std::make_shared<Employee>(103,"Siri",7800.0f,27,34.1f));
}

int main(){
    StackMemoryEmployees stackemployees{};
    RawPointerHeapEmployees rawptremployees{};
    SmartPointerHeapEmployees smartptremployees{};

    CreateObjects(stackemployees);
    CreateObjects(rawptremployees);
    CreateObjects(smartptremployees);

    ///////////////////////////////////////
    float total_salary=std::accumulate(
        stackemployees.begin(),
        stackemployees.end(),
        0.0f,
        []( float ans_upto_now , const Employee& e ) { //this lambda is called binary operation lambda which takes 2 operators of any type
            return ans_upto_now + e.salary();
        }
    );
    std::cout << "Total salary is : " << total_salary << "\n";
    
}