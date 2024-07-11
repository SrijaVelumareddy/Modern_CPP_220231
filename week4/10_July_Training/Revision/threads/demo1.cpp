/*
    thread : Isolated unit of instructions executed in memory
*/
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
            std::lock_guard<std::mutex> lk(mt);
            std::cout << 1 << "\n";
        }
        else {
            unsigned int result{1};
            for(unsigned int i=2; i<=val; i++){
                result *= i;
            }
            std::lock_guard<std::mutex> lk(mt);
            std::cout <<result << "\n";
        }
    }
    static void MultiplyBy100(int number){
        std::lock_guard<std::mutex> lk(mt);
        std::cout << number * 100 << "\n";
    }
};

void Square(int number){
    std::lock_guard<std::mutex> lk(mt);
    std::cout << number * number << "\n";
}

auto f1=[](int number){ std::lock_guard<std::mutex> lk(mt); std::cout << number * number * number<<"\n";};

void MapThreads(std::vector<std::thread>& threads) //threads cannot be copied so reference is passed
{
    //instead of index, can also use emplaceback
    threads[0]=std::thread(&Square,10);
    threads[1]=std::thread(f1,10); //f1 is an object so we will not keep & for lambda
    threads[2]=std::thread(Dummy::MultiplyBy100,10);
    Dummy d1{}; //factorial function is not static so it needs an obj to function so obj is created
    threads[3]=std::thread(&Dummy::DisplayFactorial,&d1,5);
}

void JoinThreads(std::vector<std::thread>& threads){
    for(std::thread& th : threads) {
        if(th.joinable()){
            th.join();
        }
    }
}

int main(){
    std::vector<std::thread> threads{4}; 
    MapThreads(threads);
    JoinThreads(threads);
}