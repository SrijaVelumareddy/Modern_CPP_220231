/*
    10 20 30 40
    I would like to store data continuously / I want to access previous and next elements of a certain element in the fastest time

    API's are like mechanisms to access/use the features od something

*/

#include "Employee.h"
#include<queue>
#include<memory>

using EmployeePtr=std::shared_ptr<Employee>;
using DataContainer=std::queue<EmployeePtr>;

void CreateEntriesForQueue(DataContainer& data){
    data.emplace( std::make_shared<Employee>(101,"Srija",9000.0f,22,11.1f));
    data.emplace( std::make_shared<Employee>(102,"Anaya",11000.0f,23,23.1f));
    data.emplace( std::make_shared<Employee>(103,"Hanshu",13000.0f,24,34.1f));
}

/*

                            101,"Srija",9000.0f,22,11.1f
                            ^                                102,"Anaya",11000.0f,23,23.1f
                            |                                ^                                103,"Hanshu",13000.0f,24,33.1f
                            |                                |                                ^
                            |                                |                                |
                            |                                |                                |
<-extract items from here-> [   [  0x00H  ]   ]   #         [   [   0x296H   ]   ]         #  [   [   0x876H   ]  ]  ->End of the queue

       queue front                                                          queue back
*/

int main(){
    DataContainer employees{};
    CreateEntriesForQueue(employees);

    /*
        Queue is a FIFO data structure.
        Insertion of items at one end and retrieval from the other
    */

   // we get the addresses of the data if we compile only with employee, but if you want values of the data use '*employee'
    std::cout << *employees.front() << "\n";

    /*
        We can check size 
    */
    
    std::cout << employees.size() << "\n";

    /*
        Can only read/fetch the data at the end of the queue. 
    */

    std::cout << *employees.back() << "\n";
}