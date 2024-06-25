//week 2 : Modern cpp starts

/*
    software to be built
    ------> diagnostics of a car at workshop
*/

/*
    Objective: I want to write an "Adapter function"
    which will accept:
        a) vector of integer 32 bit numbers
        b) a function that accepts a single integer 32 value and returns void

    Adaptor should "map" function provided on to the data provided

    -->we are giving a function and data as input and function operates on the data and show the result to user
*/

#include <iostream>
#include<vector>
void Square(int32_t number){
    std::cout << number * number << "\n";
}
void Cube(int32_t number){
    std::cout << number * number * number << "\n";
}
void Adaptor(
    void (*fn)(int32_t number),
    std::vector<int32_t>& data
)//function takes 2 parameters-for any fn returns void and takes 1 int 32 bit value; 2nd parameter is standard vector of int 32 value of l value reference
{
    for(int32_t val : data) //for each number in data, run the function with the number
    { 
        (*fn)(val);
    }
}
int main(){
    std::vector<int32_t>data{1,2,3,4,5};
    Adaptor(&Cube,data);
    Adaptor(&Square,data);

    //if user wants can design their own function and use its logic to process data
}
// int main(){
//     //int n1=10;
//     //int* ptr = &n1;

//     //function of pointer? --->address of a function

//     void (*ptr)(int32_t)=&Square;

//     void (*temp)(int32_t number) = &Cube;

//     (*temp)(10); //call cube function as Cube(10);
//     (*ptr)(9); //call square function as Square(9);

// }