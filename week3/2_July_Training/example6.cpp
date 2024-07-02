#include<iostream>
#include<thread>
#include<mutex>
#include<list>

using ThreadContainer=std::list<std::thread>;

class BankAccount
{
private:
    int32_t m_amount{1000};
    std::mutex mt{};
public:
    BankAccount()=default;
    BankAccount(const BankAccount&)=delete;
    BankAccount(BankAccount&&)=delete;
    BankAccount& operator=(const BankAccount&)=delete;
    BankAccount& operator=(BankAccount&&)=delete;
    ~BankAccount()=default;
    BankAccount(int32_t amount): m_amount{amount} {}

    void Deposit(){
        for(int i=0;i<100;i++){
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            mt.lock();
            m_amount+=10;
            mt.unlock();
            }
        }

    void Withdraw(){
        for(int i=0;i<100;i++){
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            mt.lock();
            m_amount-=10;
            mt.unlock();
            }
        }

    int32_t amount() const { return m_amount; }
        
};


// class ThreadManager
// {
// private:
//     /* data */
// public:
//     ThreadManager(/* args */) {}
//     ~ThreadManager() {}
// };

void CreateThreads(ThreadContainer& threads, BankAccount& b1){
    threads.emplace_back(&BankAccount::Deposit, &b1);
    threads.emplace_back(&BankAccount::Withdraw, &b1);
}

void JoinThreads(ThreadContainer& threads){
    for(std::thread& th : threads){
        if(th.joinable()){
            th.join();
        }
    }
}

void DisplayFinalAmount(BankAccount& b1){
    std::cout << "Final answer is : " << b1.amount() << "\n";
}

int main(){
    BankAccount b1{5000};
    
    ThreadContainer threads{}; //blank list of threads
    CreateThreads(threads,b1);
    JoinThreads(threads);
    DisplayFinalAmount(b1);
}

