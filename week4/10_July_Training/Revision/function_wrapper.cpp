#include<iostream>
#include<vector>
#include<thread>
#include<mutex>

std::mutex mt;

class Dummy
{
private:
    /* data */
public:
    Dummy() {}
    ~Dummy() {}

    void DisplayFactorial(unsigned int val){
        if(val == 1 || val == 0){
            std::cout << 1 << "\n";
        }
        else {
            unsigned int result{1};
            for(unsigned int i=2; i<=val; i++){
                result *= i;
            }
            std::cout <<result << "\n";
        }
    }
    static void MultiplyBy100(int number){
        std::cout << number * 100 << "\n";
    }
};

void Square(int number){
    std::cout << number * number << "\n";
}

auto f1=[](int number){ std::lock_guard<std::mutex> lk(mt); std::cout << number * number * number<<"\n";};

/*
    Here is a function, here is a data value compatible
    with inputs required for the function

    Please apply the function on the data AND
        a) transform it
        b) filter it
        c) reduce it

    Programmer: OKAY!!
*/
#include<functional>

void Adaptor(  std::function<bool(int)> fn, int data){
    //a function that takes a input and returns bool is called predicate
    if(fn(data)){
        std::cout << data << "\n";
    }
}

void Adaptor( std::function <int(int)> fn, int data){
    std::cout << fn(data) << "\n";
}

int main(){
    std::vector<std::thread> threads{4}; 
}