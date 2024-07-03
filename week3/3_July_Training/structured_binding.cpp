#include<iostream>
#include<array>

int main(){
    // a container of fixed size can be used with this syntax
    std::array<int,2>arr{9000,28};
    auto [salary,age]=arr;

    //This feature only works with cpp 17 or above
}