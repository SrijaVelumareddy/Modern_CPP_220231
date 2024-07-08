/*
    Terminologies:

    1) CPU : Set of hardware responsible for executing tasks in a computing system

    2) System : Any computing device

    3) Processor : Hardware chip (made of silicon) designed for executing instructions given by the user of the computer 

    e.g : intel i7-1256U

    4) Socket: Point on the motherboard where processor is connected

    5) Core : Every processor is divided internally into units called as "cores"
        Each core can execute instructions from one "process" at any given time

    6) Process: A running task on the system

*/

#include<iostream>
#include<vector>
#include<functional>
#include<thread>

using Operation=std::function<void(int number)>;
void Adaptor(Operation fn, const std::vector<int>& data){
    for(int val : data){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        fn(val);//apply the function on a single item. repeat this in a loop
    }
}

void Square(int number){
    std::cout << number * number << "\n";
}

int main()
{
    auto cube_fn=[](int number){ std::cout << number * number * number << "\n";};
    // Adaptor(Square, std::vector<int> {1,2,3,4,5});
    // Adaptor(cube_fn, std::vector<int> {1,2,3,4,5});


    //execute Adaptor function by using square functiona and vector of values
    //as its parameters 

    //use -lpthread to compile multiple threads
    std::thread t1{ &Adaptor,&Square, std::vector<int>{1,2,3,4,5}};
    std::thread t2{ &Adaptor,cube_fn, std::vector<int>{1,2,3,4,5}};

    t1.join(); //main cannot proceed beyond line 52 unless t1 is terminated/completed
    t2.join(); //main cannot proceed beyond line 53 unless t2 is terminated/completed

}
