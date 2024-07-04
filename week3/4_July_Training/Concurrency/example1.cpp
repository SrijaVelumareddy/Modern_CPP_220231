/*
    parallel process data with multiple threads
*/

/*
            [   10    20    30    40   ]


            [   t1    t2    t3    t4   ]
*/

#include<iostream>
#include<list>
#include<thread>
#include<functional>
#include<mutex>

using ThreadContainer=std::list<std::thread>;
using DataContainer=std::list<int32_t>;
using FnWrapper=std::function<void(int32_t)>;

std::mutex mt;

//we are taking each data and assigning to a thread to square the number
void MapThreads( ThreadContainer& threads, const DataContainer& data, FnWrapper fn){
    // auto itr = data.begin();
    // for( std::thread& th : threads){ //this line won't work because we are mapping the threads with the data but the point here is the threads don't exist now and we cannot loop on it.
    //     th=std::thread { fn, *itr++};
    // }
    for ( int32_t n : data){
        threads.emplace_back(fn,n); //we are looping on the data rather than the threads
    }
}

void JoinThreads( ThreadContainer& threads) {
    for( std::thread& th : threads){
        if(th.joinable()){
            th.join();
        }
    }
}

int main(){

    ThreadContainer threads {};
    DataContainer data {10,20,30,40};
    auto f1 = [](int32_t number) { mt.lock();
                                    std::cout << number * number << "\n";
                                    mt.unlock();
                                    };
    MapThreads(threads, data, f1);
    JoinThreads(threads);
    
}