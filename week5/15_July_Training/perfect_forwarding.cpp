#include<iostream>
#include<memory>
#include "Employee.h"

template<typename T>
void Destination(T&& arg){
    std::cout << arg << "\n";
}

template<typename T, typename... Args>
auto Forward(Args&&... n1){
    Destination<T>(std::forward<Args>(n1)...);
}

int main(){
    //Forward 10 to make a new int
    Forward<int>(10); //rvalue of type int
    std::shared_ptr<Employee> sptr = std::make_shared<Employee>(103,"Akshara",7600.0f,26,25.1f);

}

/*
    1) THIS IS AN ASSIGNMENT OPERATION : RHS HAS TO BE ASSIGNED TO LHS!
        RHS IS EXECUTED FIRST
    2) RHS IS A FUNCTION, FUNCTIONS ARE CALLE DWITH PARAMETERS, 5 PARAMETERS HAV EBEEN PROVIDED
*/

/*
    what is a forwarding function, how to recognize it?

    A forwarding function is a template function that accepts parameters to call function F.

    It will always be a variadic template.

    it will always use the built-in tool std::forward

    All parameters received in the function shall be of type "Something" with the syntax
    <function-name>(Something&&...values)

    i.e The function shall receive one or more template parameters using ...
    with &&

    void magic(int&& data);
    ///////////////////////
    template<typename T>
    void magic(T&& data); //T&& does not mean rvalue of type T, it means a forwarded function

    when you see a template e.g auto with && it means forwarded function
*/