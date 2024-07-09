#include<variant>
#include<iostream>

class A
{
private:
    /* data */
public:
    A(/* args */) { std::cout << "A object created\n"; }
    ~A() {
        std::cerr << "A object destroyed\n";
    }
};

class B
{
private:
    /* data */
public:
    B(/* args */) { std::cout << "B object created\n"; }
    ~B() {
        std::cerr << "B object destroyed\n";
    }
};

int main(){
    std::variant<A,B> v{}; //initialize the variant with default value of first type in variant
     //rhs will be executed first 
    v = B{}; //default initialized A object deallocated

    std::cout << "switch to A object again\n"; //older object gets destroyed before reassigning - thst is the difference with variant and union

    v = A{};

}