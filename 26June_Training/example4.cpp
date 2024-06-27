/*
    std::reference_wrapper<T>:
        this is a wrapper class to "hold"
        reference type T
*/

#include<iostream>
#include<vector>
#include<functional>
void Magic(std::reference_wrapper<int> data){


}
// int main(){
//     int n1=10;
//     int& ref=n1; //ref is a reference of n1
//     //reference is the altername name for n1 in main function
//     Magic(n1); //int& data=n1;
//     // int& arr[1] {ref};
//     std::vector<int&> v1 {ref}; //references don't exist and hence you cannot construct array,vector,list....etc it takes 0 bytes of data.

// }

int main(){
    int n1=10;
    std::reference_wrapper<int> ref=n1; //ref is a reference of n1
    //reference is the altername name for n1 in main function
    Magic(n1); //std::reference_wrapper<int> data=n1;
    // int& arr[1] {ref};
    std::reference_wrapper<int>arr[1] {ref}; 
    std::vector<std::reference_wrapper<int>>v1;
    std::cout << v1[0].get(); //get the value inside the wrapper in 0 position of vector
}

//reference wrapper can auto convert to raw reference if required
void Magic(int& data){
    std::cout << data << "\n";
}
int main(){
    
}
