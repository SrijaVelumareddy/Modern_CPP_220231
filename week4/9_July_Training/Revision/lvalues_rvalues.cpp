/*
    scenario 1: non const integer by value (copy)
        if lvalue is passed, it will be copied, if rvalue is passed
        it will be assigned
*/

#include<iostream>
#include<variant>

void Demo(int n1){

}
int main(){
    Demo(10); //rvalue
    int n1 {10};
    Demo(n1); //lvalue

    //if you give std::move data variable can be converted to rvalue

    std::variant<int, std::string> v1 {10}; //lvalue
    std::variant<int, std::string>  {10}; //rvalue
    
}