#include "Employee.h"
#include<queue>

/*
    1) what kind of data goes into priority queue?
    2) what is the backend of the queue to store the data? //vector is the default
    3) what is the comparision logic? (also called "comparator")
*/

// int main(){
//     std::vector<Employee> employees {};
//     employees.emplace_back(101,"Srija",8900.0f,22,11.1f); 
//     employees.emplace_back(102,"Megha",1100.0f,24,23.1f); 
//     employees.emplace_back(103,"Akshara",7600.0f,26,25.1f); 

//     //all employees which are in the vector must be inserted into the heap using heapify()

//     //comparators
//     auto fn = [](const Employee& e1, const Employee& e2) { return e1.experienceYears() > e2.experienceYears(); };

//     std::priority_queue<Employee,std::vector<Employee>, decltype(fn)> pq { employees.begin(), employees.end(), fn};

//     //This code will give an error because we have to take data from a vector to queue so it requires copy and move constructors 

//     /*
//         CPP is a strongly & statically typed language
//         1) CPP : everything has a type, including functions!

//         2) a lambda in c++ is an object that behaves like a function

//         3) Lambda is always implemented by the compiler by creating a class during compilation. Name of this class is unknown to us!

//         4) So, my requirement is : compiler should create fn lambda. It's type will be known to compiler

//         The declared data type for fn is what we need to obtain from the compiler 
    
//     */

// }

int main(){

    //priority is reverse of comparator operator : > mean min heap, < means max heap!
    //time complexity is O(log(n))

    auto fn = [](const Employee& e1, const Employee& e2) { return e1.experienceYears() < e2.experienceYears(); };

    std::priority_queue<Employee,std::vector<Employee>, decltype(fn)> pq {fn};

    pq.emplace(101,"Srija",8900.0f,22,11.1f);
    pq.emplace(102,"Megha",1100.0f,24,23.1f);
    pq.emplace(103,"Akshara",7600.0f,26,25.1f);

    //For this code you only need move constructor, no need of copy contructor

    //who is the employee with "HIGHEST PRIORITY"
    std::cout << pq.top() << "\n";
}

