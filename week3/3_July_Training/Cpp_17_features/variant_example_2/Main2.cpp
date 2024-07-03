/*
    Keep data on the heap
    and use variant for "functional polymorphism"

*/

#include<iostream>
#include<variant>
#include "Employee.h"
#include"BusinessOwner.h"

/*
    A function which either accepts another function as a parameter or returns a function
    is called "Higher-order" function
*/

using VrType = std::variant<BusinessOwner*, Employee*>;

void Display(const VrType& v){
    std::visit( [](auto&& val){ std::cout << *val << "\n"; },  v);
}

void ShowPfAmount(const VrType& v)
{
    bool m_flag {false};
    if( std::holds_alternative<Employee*>(v)){

        Employee* e = std::get<1>(v);
        m_flag = true;
        e->CalculateMonthlyPf();
    }
    if(!m_flag){
        throw std::runtime_error("Not valid for businessowner type data");
    }
}

//common behaviour can be executed using visit
void ShowTaxAmount(const VrType& v){
    std::visit ( [](auto&& val){ val->CalculateTaxAmount();},v);
}

int main(){

    //In this method there is no need of copy or move constructors or operators as we are creating the objects on the heap.

    VrType v;
    v = new BusinessOwner {"Velumareddy", 89000.0f};
    Display(v);

    v=new Employee{"Srija", 9000.0f};
    Display(v);
    try{
        ShowPfAmount(v);
    }catch(std::runtime_error& ex){
        std::cout<<ex.what()<<"\n";
    }
    ShowTaxAmount(v);
}