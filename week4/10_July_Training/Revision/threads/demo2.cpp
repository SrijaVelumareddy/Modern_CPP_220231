/*
    thread : Isolated unit of instructions executed in memory
*/
#include<iostream>
#include<vector>
#include<future>
#include<mutex>

std::mutex mt;

class Dummy
{
private:
    /* data */
public:
    Dummy() {}
    ~Dummy() {}

    int DisplayFactorial(unsigned int val){
        if(val == 1 || val == 0){
            std::lock_guard<std::mutex> lk(mt);
            return 1;
        }
        else {
            unsigned int result{1};
            for(unsigned int i=2; i<=val; i++){
                result *= i;
            }
            std::lock_guard<std::mutex> lk(mt);
            return result;
        }
    }
    static int MultiplyBy100(int number){
        std::lock_guard<std::mutex> lk(mt);
        return number * 100;
    }
};

int Square(int number){
    std::lock_guard<std::mutex> lk(mt);
    return number * number;
}

auto f1=[](int& number){ std::lock_guard<std::mutex> lk(mt); return number * number * number;};

int main(){
    std::vector<std::thread> threads{4}; 
    std::future<int>res1=std::async(&Square,10);
    int n1{10}; //if you pass by reference
    std::future<int>res2=std::async(f1, std::ref(n1));

    Dummy d1{};
    std::future<int>res3=std::async(&Dummy::DisplayFactorial, &d1, std::ref(n1));
    std::future<int>res4=std::async(&Dummy::MultiplyBy100, std::ref(n1));

    std::cout << res1.get() << "\n";
    std::cout << res2.get() << "\n";
    std::cout << res3.get() << "\n";
    std::cout << res4.get() << "\n";

}