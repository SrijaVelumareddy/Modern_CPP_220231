#include<iostream>

// void Magic(int n1){
//     ////
// }


// void Magic(int data){
//     ////
// }

// void Magic(int& data){
//     ////
// }

// void Magic(int&& data){
//     ////
// }

void Magic(const int&& data){
    ////
}


int main(){
    Magic(10);
    int n1=10;
    Magic(n1);
}


// Fn(XYZ val)----->call by value
// Fn(XYZ& val)----->reference(lvalue)
// Fn(XYZ&& val)----->rvalue references
// Fn(const XYZ& val)----->lvalue &rvalue