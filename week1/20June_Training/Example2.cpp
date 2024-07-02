#include<iostream>
#include <vector>
 
void Deallocate(std::vector<int*>&& values){
    for(int* v:values){
        delete v;
    }
}
 
void Magic(std::vector<int*>&& values){
    for(int * v:values){
        std::cout<<*v<<"\n";
    }
    Deallocate(std::move(values)); //transfer ownership of heap allocated data
}
 
int main(){
    std::vector<int*>data {new int {10}, new int{20}};
    Magic(std::move(data)); //transfer ownership of heap allocated data
    // accessing data variable agter move is complete
    //WILL BE UNDEFINED BEHAVIOUR
 
}