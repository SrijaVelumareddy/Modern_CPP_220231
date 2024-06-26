#include<iostream>
#include <vector>
#include <list>
#include <array>

template<typename T>

void Display(T& data){
    for( int val : data){
        std::cout << val << "\n";
    }
}
int main() {
    std::list<int> data1{10,20,30};
    std::vector<int> data2{10,20,30};
    std::array<int,3> data3 {10,20,30}; //like a c-style array but without pointer

    Display<std::list<int>>(data1);
    Display<std::vector<int>>(data2);
    Display<std::array<int,3>>(data3);
}