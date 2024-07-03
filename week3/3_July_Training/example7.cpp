#include<iostream>
#include<thread>
#include<mutex>
#include<list>


//Singleton: A class which can be instantiated only once i.e, only one object of this class can be present at any point in the app 
using ThreadContainer=std::list<std::thread>;

class BankAccount
{
private:
    int32_t m_amount{1000};
    std::mutex mt{};

    static BankAccount* m_instance_ptr;
    //static data members of a class cannot be initialized in class
    //static member can/should only be modified by/ in the static member of the class

    BankAccount()=default;
    BankAccount(const BankAccount&)=delete;
    BankAccount(BankAccount&&)=delete;
    BankAccount& operator=(const BankAccount&)=delete;
    BankAccount& operator=(BankAccount&&)=delete;
    BankAccount(int32_t amount): m_amount{amount} {}
public:
    
    ~BankAccount()=default;
    

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

    /*
        if pointer exists, it means the object of this class is already present. As per rule sof Singleton pattern,new object cannot be created.
        So, take the amount value given by the user. Update it in the existing object. Return this same object's pointer ti the user.
        If pointerc is null, it means no object currently exists in the system for this class. So a new instance can be created. Take "null" provided by the user to construct a new object on the heap and return its pointer.      
    */
    static BankAccount* GetInstance(int val){
        if(m_instance_ptr){
            m_instance_ptr->setAmount(val);
            return m_instance_ptr;
        }
        else{
            m_instance_ptr=new BankAccount(20000); //default constructor
            return m_instance_ptr;
        }
    }

    void setAmount(const int32_t &amount) { m_amount = amount; }
        
};

//initialize static data member

BankAccount* BankAccount::m_instance_ptr {nullptr};
//data type  <full-name of data member>    //init value

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
    
    BankAccount* ptr=BankAccount::GetInstance(1000);
    
    ThreadContainer threads{}; //blank list of threads
    CreateThreads(threads,*ptr);
    JoinThreads(threads);
    DisplayFinalAmount(*ptr);
    delete ptr;
}

