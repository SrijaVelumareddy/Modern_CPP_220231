#include<memory>
#include<iostream>
#include<list>
#include<algorithm>
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

    
    //find the position where minimum element is located.
    //if there are multiple minimums, then consider the first one found
    // 11, 9, 7, 10, 18, 7

    auto result1 = std::min_element(
        stackemployees.begin(),
        stackemployees.end(),
        []( const Employee& e1, const Employee& e2) {
            return e1.experienceYears() < e2.experienceYears();
        }
    );
    std::cout << "The name of employee with minimum experience is : " << (*result1).name() << "\n";

    auto result2 = std::min_element(
        rawptremployees.begin(),
        rawptremployees.end(),
        []( const Employee* e1, const Employee* e2) {
            return e1->experienceYears() < e2->experienceYears();
        }
    );
    std::cout << "The name of employee with minimum experience is : " << (*result2)->name() << "\n";

}