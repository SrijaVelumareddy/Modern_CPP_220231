#include<iostream>
#include<thread>
//threads cannot take values by reference, only values it means the values will be copied

void Formula(int& val, float factor, const std::string& name){//non-const lvalue  of integer
    std::cout << "Absolutely important work!";
}

int main(){
    //thread will not take values directly, first they will go to a forwarding function. Then that forwarding function will send to thread during compilation
    //undefined reference to pthread_createobjects : forgot to include -lpthread while compiling
    int n1{10};
    //as threads won't take reference, but still you want to pass a reference to a thread use std::ref
    //thread arguements should be invokable

    std::thread t1 {&Formula, n1,10.21f, "Srija"};
}