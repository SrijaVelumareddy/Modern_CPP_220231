#include<iostream>
#include<functional>

void formula(int& x,int y,int z){
    std::cout << x+y+z << "\n";
}

int main(){
    int a=10;
    auto binded_formula=std::bind(&formula,std::ref(a), 100, std::placeholders::_1);
    binded_formula(99); //formula(a,100,99)

    //called formula (by copying x, assigning 100 to y, and assigning 99 to z)
    //you cannot use references to bind unless u put them in reference wrapper otherwise bind will take it as value not by reference
    

}