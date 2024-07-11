//static keyword!

/*
    1) static storage variable
    2) static data member
    3) static member function
*/
//static data will not be deleted after the scope of the function, they are not stored in the local memory, they will be in the memory till the complete execution and they are not stored in stack.
//one copy will be created and it is used in the whole program
//static data members are not initialized in the constructor because they are not the part of the object
//static data members can only be accessed through static functions
#include<iostream>

void Increment(){
    static int n1{1};
    //std::cout << n1 << "\n";
    std::cout << n1++ << "\n";
}

class EmployeeData 
{
private:
    static long long m_company_landline_number;
    std::string m_employee_name;
public:
    EmployeeData (std::string name) : m_employee_name{name} {}
    static long long companyLandLineNumber() { return EmployeeData::m_company_landline_number;};
};

long long EmployeeData::m_company_landline_number=234567;

int main(){
    Increment(); //created n1 in static data segment. Initial 1. print 1
    Increment();
    EmployeeData e1{"Srija"};
    std::cout << EmployeeData::companyLandLineNumber()<<"\n";
}