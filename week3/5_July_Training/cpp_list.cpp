#include<iostream>
#include<variant>
#include<list>

using DataContainer = std::list<std::string>;

void CreateObjects(DataContainer& data){
    //DataContainer data {10,20,30}; //error because the data type is string and we have given data as integers
    data.emplace_back(10); //Intellisense doesn't show any error here because emplace back is also like a forwarding function. The error is shown during the compilation.
}
int main(){

}