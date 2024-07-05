#include<iostream>

void Display(char grade){
    std::cout << grade << "\n";
}

void Demo(int n1, std::string name){
    std::cout << n1 << name << "\n";
}

void Temp(float n1, int* ptr, std::string name, char&& grade, const bool& flag){
    std::cout << n1 << "\t" << *ptr << "\t" << name << "\t" << grade << "\t" << flag << "\n";
}
int main(){
    //Display("A"); //const char[1]
    //Display('A');

    //Demo("abc",16); //This will give an error because the parameters are not passed in correct order. And the error comes from the declaration of the function and not the definition. Make sure that all the parameters are same and aligned with declaration function parameters.
    //Demo is a function which gets two parameters as input which are an integer and a string that are required to perform a particular operation 
    //***Demo is a function which takes non-const int byvalue non-const std string byvalue and returns void
    std::string val {"abc"};
    bool flag{true};
    char grade {'A'};
    Temp(10.21f, new int(10), val, 'A', flag); //remove the declaration of char
    //Temp(10.21f, new int(10), val, grade, flag); //there is an error near grade beacuse the input is char&& which is rvalue but we are passing lvalue.
    //double ampersent with concrete data type means rvalue reference of that data
    //For const bool : const lvalue reference means i will take the value by reference and if it rvalue then i will absorb it and assign it.
}