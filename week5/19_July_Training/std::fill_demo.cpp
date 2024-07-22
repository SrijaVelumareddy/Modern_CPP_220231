/*
    If I have memory locations already allocated up to a certain size, I can "fill" all locations with "some" value using this algorithm

    for e.g: std::vector<int> data {5}; //size 5 vector

    std::fill( data.begin(), data.end(), 11);

    result: data: {11,11,11,11,11}

    for e.g: std::array<int,5> arr{}; //array of 5 location

    std::fill(arr.begin(), arr.end(), 11);

    result: arr: {11,11,11,11,11}

*/

#include<iostream>
#include<memory>
#include"Employee.h"
#include<vector>
#include<algorithm>
using StackMemoryEmployees = std::vector<Employee>;
using RawPointerHeapEmployees = std::vector<Employee*>;
using EmployeePtr = std::shared_ptr<Employee>;
using SmartPointerHeapEmployees = std::vector<EmployeePtr>;

int main(){
    StackMemoryEmployees stackemployees{};
    RawPointerHeapEmployees rawptremployees{};
    SmartPointerHeapEmployees smartptremployees{};

    std::fill(
        stackemployees.begin(),
        stackemployees.end(),
        Employee{}
    );

    std::fill(
        rawptremployees.begin(),
        rawptremployees.end(),
        new Employee{}
    );

    std::fill(
        smartptremployees.begin(),
        smartptremployees.end(),
        std::make_shared<Employee>()
    );

}