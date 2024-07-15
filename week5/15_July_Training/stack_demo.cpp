#include<stack>
#include<iostream>
#include "Employee.h"
/*
    A stack is never used for accessing all items together.
        NO LOOPING OPERATIONS!!
*/
int main(){
    std::stack<Employee> s{};

    s.emplace(101,"Srija",8900.0f,22,11.1f); //push operation in the stack
    s.emplace(102,"Megha",1100.0f,24,23.1f); //push operation in the stack
    s.emplace(103,"Akshara",7600.0f,26,25.1f); //push operation in the stack

    //Display top item and then pop
    std::cout << s.top() << "\n";
    s.pop();

    //s.push()//it takes only rvalues so you have to on the copy or move constructor
    //check size:

    std::cout << s.size() << "\n";

    std::cout << "Checking for empty: " << std::boolalpha << s.empty() << "\n";

     
}