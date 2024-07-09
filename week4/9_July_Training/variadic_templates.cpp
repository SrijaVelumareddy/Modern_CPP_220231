/*
    cpp11: create a function in c++ that can accept 1 or more arguments
*/

#include<iostream>

//cpp11 and cpp14 syntax
//base class : only 1 argumement for addition
template <typename T>
T add(T val){
    return val;
}

template<typename T, typename...Other> //...->ellipsis operator - to say one or more typenames
auto add(T n1, Other... args){ //one or more other args are going to other
    return n1 + add(args...); //one or more args are going to add
}
int main(){
    std::cout << add<int>(1,2,3) << "\n";//6
    std::cout << add<int>(1) << "\n";//1
    std::cout << add<int>(1,2) << "\n";//3
}

/*
    cpp17 syntax:

    fold_expression.cpp
    
    add is a function template that takes 1 or more arguements of unknown type in each case. We assume is type T

    The function adds the first parameter with the remaining operator by using + operaroe between n1 and remaining arguements...

            template <typename... T>
            auto add(T... n1){
                return (... + n1); //left most side arguments will be added first
                return (n1 + ...); //right most side arguments will be added first
            }
            int main(){
            std::cout << add<int>(1,2,3) << "\n";//6
            std::cout << add<int>(1) << "\n";//1
            std::cout << add<int>(1,2) << "\n";//3
            }

    add(1,2,3,4,5) //recursion soves in reverse order

    (1+(2+3+(4+5))) // n1 + ... right associative, right most + first

    ((((1+2)+3)+4)+5) // ... + n1 left association, left most + first

    subtraction is not associative

    example 1:

    subtract(1,2,3)

    left most associative operation

    ((1-2)-3) = -1-3 = -4

    right associative operation

    (1-(2-3)) = 1-(-1) = 1+1 = 2  

*/