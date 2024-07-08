/*
    Magic                                   Heap
                                            Employee
    ptr[0x100H]--------------------->[101  |  Srija  |  9000.0f]
    /////

    void Magic(){
    Employee* ptr = new Employee(101, "Srija", 9000.0f);
    }
    int main(){
        Magic();
        int n1=10;
    }
*/

//same code with array with raw pointers

// #include<iostream>
// #include<list>

// void CreateData(int* data){
//     data[0]=10;
//     data[1]=20;
// }

// void CalculateTotal(int* data, int size){
//     float total{0.0f};
//     for( int i=0;i<size;i++){
//         total+=data[i];
//     }
//     std::cout << "Total is : " << total << "\n";
// }

// void PrintFirstElement(int* data, int size){
//     std::cout << data[0];
// }

// int main(){
//     int* arr = new int[2];
//     CreateData(arr);
//     CalculateTotal(arr,2);
//     PrintFirstElement(arr,2);
//     //we will exit from the main function
    
// }

#include<iostream>
#include<list>
#include<memory>

void CreateData(std::shared_ptr<int[]> data){
    data[0]=10;
    data[1]=20;
}

void CalculateTotal(std::shared_ptr<int[]> data, int size){
    float total{0.0f};
    for( int i=0;i<size;i++){
        total+=data[i];
    }
    std::cout << "Total is : " << total << "\n";
}

void PrintFirstElement(std::shared_ptr<int[]> data, int size){
    std::cout << data[0];
}

int main(){
    std::shared_ptr<int[]>arr(new int[2]);
    CreateData(arr);
    CalculateTotal(arr,2);
    PrintFirstElement(arr,2);
    //we will exit from the main function
    
}