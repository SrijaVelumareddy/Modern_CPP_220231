/*
    More about lambdas:
        1) WHAT ARE THEY EXACTLY?
            -
        2) WHAT IS [] WITH LAMBDAS?
            -if we want to access objects/variables created in the enclosing function of the lambda, we use [] i.e capture clause
        3) SOME WEIRD THINGS TO KNOW ABOUT LAMBDAS
*/

#include<iostream>
#include<functional>

void Demo(void(*ptr)(int n1,int n2)){
    ptr(10,20);
}

int main(){
    auto fn = [](int n1,int n2) { std::cout << n1 + n2;};
    Demo(+fn);
    //"+" symbol before lambda variable makes it to work as a function pointer
}


// void add(int32_t n1, int32_t n2){
//     std::cout << n1 + n2 << "\n";
// }

// int main(){
//     /*
//         lambda object is bound to fn variable in the scope of main function
//     */
//     auto fn = [](int32_t n1, int32_t n2){ std::cout << n1 + n2 << "\n";};
//     fn(10,20); //overload the () operator of a class created in the background
// }

// int main(){
//     /*
//         lambda object is bound to fn variable in the scope of main function
//     */
//     int data=20;
//     auto fn = [](int32_t n1, int32_t n2){ std::cout << n1 + n2 + data << "\n";};
//     fn(10,20,data); //overload the () operator of a class created in the background
// } //does not take data value bcz it is not present in lambda function so one way is the following

int main(){
    /*
        lambda object is bound to fn variable in the scope of main function
    */
    int data=20;
    auto fn = [](int32_t n1, int32_t n2 , int data){ std::cout << n1 + n2 + data << "\n";};
    fn(10,20,data); //overload the () operator of a class created in the background
} 

//instead of giving the function another parameter we can do this
int main(){
    /*
        lambda object is bound to fn variable in the scope of main function
    */
    int data=20;
    auto fn = [data](int32_t n1, int32_t n2){ std::cout << n1 + n2 + data << "\n";};
    fn(10,20); //overload the () operator of a class created in the background
} 

int main(){
    /*
        lambda object is bound to fn variable in the scope of main function
    */
    int data=20;
    int value=200;
    auto fn = [data,value](int32_t n1, int32_t n2){ std::cout << n1 + n2 + data << "\n";};
    fn(10,20); //overload the () operator of a class created in the background
} 



/*
    
    capture class

    int n1=10;
    int n2=20;
    int n3=30;

    example1: use of no captured variables
        auto fn = [](){ std::cout << "hello world\n";};
        fn();

    example2: use of no captured variables but passed parameters
        auto fn = [](int n1,int n2){ std::cout << n1 + n2;};
        fn(n1,n2);

    example3: use of n1 as captured variable, n1 should be copied into the lambda
        auto fn = [n1](int n2){ std::cout << n1 + n2;};
        fn(n2); //only n2 is passed as n1 is already copied

    example4: use of n1 as captured variable, n1 should be referred into the lambda
        auto fn = [&n1](int n2){ std::cout << n1 + n2;};
        fn(n2); //only n2 is passed as n1 is already captured by reference

    example5: capture all variables from the surrounding (make them all accessible int the lambda). (copied everything into lambda when they are accessed in the body of the lambda)
        auto fn = [=](){ std::cout << n1 + n2 + n3;};
        fn(); //all variables were copied by capture into the lambda
        // "=" operator when used, it can only use the data but cannot modify it because the data is immutable when copied

    example6: capture all variables from the surrounding (make them all accessible int the lambda). (refer everything into lambda when they are accessed in the body of the lambda)
        auto fn = [&](){ std::cout << n1 + n2 + n3;};
        fn(); //all variables were captured by reference into the lambda



*/
