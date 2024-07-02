/*
    3 styles of programming
        - structure oriented
        - object oriented - dynamic dispatch(select correct function based on type of data)
        - functional


    Rules for functional programming

    a) Treat functions as if they are objects
    b) If possible, maintain purity of function (do not modify the data, pass by lvalue mostly), (do not prefer to print anything in the function only perform the operation bcz sometimes it does not give proper output and it is considered as impure function)
    c) Functions have categories based on what they do
        example1: a function that transforms x1,x2,x3 into y1,y2,y3 based on a transformation mapping logic is called a "Map function".

            e.g: data=[1,2,3,4,5]
                fn=(n)->n*n

            result : 1,4,9,16,25

            In map function application, number of inputs and outputs are same

            [101  27000  ] [102  90000  ] [102  88000  ] 

            fn=(e)->salary*0.1f; //as tax

            result = 2700 , 9000 , 8800

        example2: a function that "remove/identifies" from the input, a select number of values based on a criteria [Filter function]

        e.g: data=[1,2,3,4,5]
        fn->n%2==0
        result:[2,4] //only 2 input values satisfy the condition (predicate)


        example3: a function that accumulates/aggregates/gathers multiple input values into one, final, singular output value [reduce/accumulates functions]

        e.g: data=[1,2,3,4,5]
        fn=(x,y)->x+y

        result : 15

        total    1   2   3   4   5
        0        |   |
        |        |   |
            1    |   |
            |        | 
                    3   |
                    |   |
                       6    4
                       |     |

        
*/

#include<iostream>
#include<functional>

using Operation=std::function<int32_t(int32_t)>;

void Adaptor(Operation fn, int32_t value)
//auto Adaptor(Operation fn, int32_t value) -> void
{
    std::cout << fn(value);
}

int main(){
    //takes one input of type int32_t by balue and returns an int32_t value
    //the function should multiply input number by 100

    auto fn=[](int32_t n){ return n*100;};
    //auto fn=[](int32_t n) -> int32_t  { return n*100;};

    int n1=100;
    auto demo_fn = [n1](int32_t num) mutable { n1=99; return num * n1;};
    //incase if you want to modify n1 value then add mutable to lambda function

    Adaptor(fn,10);
}