/*
    Magic                                   Heap
                                            Employee
    ptr[0x100H]--------------------->[101  |  Srija  |  9000.0f]
    /////

    void Magic(){
    Employee* ptr = new Employee(101, "Srija", 9000.0f);
    }
    int main(){
        Magic();
        int n1=10;
    }
*/

#include<iostream>
#include<list>

void CreateData(std::list<int>& data){
    data.emplace_back(10);
    data.emplace_back(20);
}

void CalculateTotal(std::list<int>& data){
    if(data.empty()){
        throw std::invalid_argument("empty data");
    }
    float total{0.0f};
    for( int val : data){
        total+=val;
    }
    std::cout << "Total is : " << total << "\n";
}

void PrintFirstElement(std::list<int>& data){
    if(data.empty()){
        throw std::invalid_argument("empty data");
    }
    std::cout << data.front();
}

int main(){
    std::list<int>data{};
    CreateData(data);
    CalculateTotal(data);
    PrintFirstElement(data);
    //we will exit from the main function
    
}