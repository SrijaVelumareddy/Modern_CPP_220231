#include <iostream>

class Vehicle
{
private:
    std::string m_id{""};
    std::string m_modelName{""};
public:
    Vehicle()=delete;
    ~Vehicle()=default;
    /*
        vehicle constructor that takes one const lvalue reference to a Vehicle as a parameter
    */
    Vehicle(const Vehicle& other) = delete;

    Vehicle( std::string id,std::string name)
            :m_id{id}, m_modelName{name} {}
};

int main(){
    Vehicle v1{"101", "Dzire"};
    //Vehicle v2{v1}; //v2[101|Dzire]

    int n1=10;
    int n2=20;
    n2 = n1; //copy n1 into n2 after n2 was already initialized
    //copy constructor is creating the second object for the first time
    //copy assignment is overriding an already existed variable

    Vehicle v3 = v1;

    Vehicle v3{}; //default
    v3 = v1;
}