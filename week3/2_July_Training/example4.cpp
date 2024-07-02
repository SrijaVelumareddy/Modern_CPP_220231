#include<iostream>
#include<thread>
#include<mutex>

class MathOperations
{
private:
    std::mutex mt{}; //mutex should not and will not copy  and does not have any parameterised construction so it cannot ba given any value and not declared in the parameterized constructor list
    int32_t m_value{0};
public:
    MathOperations(const MathOperations&)=default;
    MathOperations(MathOperations&&)=delete;
    MathOperations& operator=(const MathOperations&)=delete;
    MathOperations& operator=(MathOperations&&)=delete;
    MathOperations()=default;
    MathOperations(int val) : m_value {val} {}
    ~MathOperations()=default;

    void Square() { 
        mt.lock();
        std::cout << "Id : of the thread square: " << std::this_thread::get_id() << "\n";
        std::cout << "Square of " << m_value << " is : " << m_value * m_value << "\n"; 
        mt.unlock();
        }
        int32_t addition(int other){ 
            mt.lock();
            std::cout << "Id : of the thread addition: " << std::this_thread::get_id() << "\n";
            mt.unlock();
            return m_value + other;};

        //paren paren operator
        int64_t operator()(){
            mt.lock();
            std::cout << "Id : of the thread operator: " << std::this_thread::get_id() << "\n";
            mt.unlock();
            return m_value * m_value * m_value;
        }
};

//an object that behaves like a function (can be invoked like a function)
//is called a "functor" object

// int main(){
//     std::thread t1 { &MathOperations::Square, MathOperations{10} };
//     MathOperations m1{100};

//     std::thread t2 { m1 }; //thread created by a functor object
//     m1(); //use the parenthesis operator with the object

//     std::thread t3 { &MathOperations::addition, &m1, 100};

//     //you cannot capture return values from a function when executing
//     //then via std::thread
//     //It means it will be executed but any function returning value, you cannot see the output

//     t1.join();
//     t2.join();
//     t3.join();
//     //function call error

// }

int main(){
    MathOperations m1{100};

    //the first parameter passed in a thread it is always a function and compiler take it as callables
    std::thread t1 { &MathOperations::Square, &m1 }; //address of object &m1

    std::thread t2 { std::ref(m1) }; //thread created by a functor object //address of function &m1
    m1(); //use the parenthesis operator with the object

    std::thread t3 { &MathOperations::addition, &m1, 100};

    //you cannot capture return values from a function when executing
    //then via std::thread
    //It means it will be executed but any function returning value, you cannot see the output

    t1.join();
    t2.join();
    t3.join();
    
    // Note: t2 and t3 outputs will get discarded. no way to capture it.

    // Note: all parameters passed to std::thread constructor are taken as "call by value"

}