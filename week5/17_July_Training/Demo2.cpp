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
    std::vector<Employee> result{};
    
    //There are 3 types of copy, based on requirement choose the correct one
    //**but the thing is we have to enable copy constructors
    //**move constructors enabling will be based on the behaviours of the stl containers
    //for stack objects, vector requires move also bcz first we are copying into a template or node and then moving into a vector
    //example 1 : based on some condition-copy_if
    //create a inserter pointer, if space is not allocated, do it automatically
    std::copy_if(
        stackemployees.begin(),
        stackemployees.end(),
        std::inserter(result, result.begin()),
        []( const Employee& e) {
            return e.age() > 20;
        }
    );
    
    //examplpe 2 : To copy n number of elements-copy_n
    std::vector<Employee> n_result_container{};
    std::copy_n(
        stackemployees.begin(),
        2,
        std::inserter(n_result_container,n_result_container.begin())
    );

    //example 3 : copy all items from rawptremployees into the container-copy
    std::vector<Employee*> result_pointers { rawptremployees.size() };
    std::copy(
        rawptremployees.begin(),
        rawptremployees.end(),
        result_pointers.begin()
    );
    //allof
    //anyof
    //noneof
    //minelement
    //maxelement
    //copy-copy_if,copy_n,copy,count_if
    //
    
}