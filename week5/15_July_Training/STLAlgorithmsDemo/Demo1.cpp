#include<memory>
#include "../Employee.h"
#include<iostream>
#include<list>
#include<algorithm>

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

    //Ckeck if all employees have age above 25

    //check all items from begin to end of my container

    bool result1=std::all_of(
        stackemployees.begin(),
        stackemployees.end(),
        [](const Employee& e){ return e.age() > 25;}
    ); 

    bool result2=std::all_of(
        rawptremployees.begin(),
        rawptremployees.end(),
        [](const Employee* e){ return e->age() > 25;}
    ); 

    bool result3=std::all_of(
        smartptremployees.begin(),
        smartptremployees.end(),
        [](const EmployeePtr& e){ return e->age() > 25;}
    ); 

    std::cout << result3 << "\n";

    //Ckeck if any of employees have age above 25

    bool result1=std::any_of(
        stackemployees.begin(),
        stackemployees.end(),
        [](const Employee& e){ return e.age() > 25;}
    );

    std::cout << result1 << "\n";
    //Ckeck if none of employees have age above 25

    bool result1=std::none_of(
        stackemployees.begin(),
        stackemployees.end(),
        [](const Employee& e){ return e.age() > 25;}
    ); 
    std::cout << result1 << "\n";

}