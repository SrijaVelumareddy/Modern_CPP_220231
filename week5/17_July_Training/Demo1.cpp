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

    auto result1 = std::count_if(
        stackemployees.begin(),
        stackemployees.end(),
        []( const Employee& e1) {
            return e1.experienceYears() > 8.0f;
        }
    );
    std::cout << "count of employees with more than 8 years experience is : " << result1 << "\n";
    
    auto result2 = std::count_if(
        rawptremployees.begin(),
        rawptremployees.end(),
        []( const Employee* e1) {
            return e1->experienceYears() > 8.0f;
        }
    );
    std::cout << "count of employees with more than 8 years experience is : " << result2 << "\n";
    
    auto result3 = std::count_if(
        smartptremployees.begin(),
        smartptremployees.end(),
        []( const EmployeePtr& e1) {
            return e1->experienceYears() > 8.0f;
        }
    );
    std::cout << "count of employees with more than 8 years experience is : " << result3 << "\n";

}