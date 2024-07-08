/*
    usecase 1: calculate square for 10 numbers

    10 std::thread object to compute sq1uare of number of each

    usecase 2: 5 operations are to be performed. All are independent (order of execution is not important). Execute all 5 parallelly.
        a) one std::thread for each operation
        b) one async thread for each operation
        c) mix of std::thread and std::async

        (all functions returning a value need to be executed via std::async, others via std::thread)

    usecase 3: 
        [producer-consumer problem]

        f1(producer) -----> data will be generated

        f2(consumer) -----> processing data only after data is generated


        example : sensor detects collision and deployment of airbags!

        program to call emergency()

*/

#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>

int32_t value {0};
std::condition_variable cv;
std::mutex mt;
bool m_inputReceived {false};

void Producer(){
    while(m_inputReceived){
        std::cin >> value;
        if(value > 5){
            m_inputReceived = true;
        }
    }

    //data is produced
        // 1) user input is received
        // 2) imput must be above 5

    //send a signal!
    std::lock_guard<std::mutex>lk(mt); // lock-guard releases at the end of the function according to the RAII
    cv.notify_one(); //sends a signal!

}

// int main(){
//     //This value cannot be executed before producer gives a signal
//     //std::cout << "Value squared is : " << value * value << "\n";
//     // This can be written in seperate function also
// }

void Consumer(){
    /*
        scenario 1 : consumer starts, consumer checks for condition 
        if condition is false, I cannot exit the function!! 
    */
    //waiting for signal!
    std::unique_lock<std::mutex> ul(mt); //unique lock releases the resource at the end or in the middle based on the condition
    cv.wait( ul  ,[](){ return m_inputReceived;} );
    std::cout << "Value squared is : " << value * value << "\n";
}

int main(){

    //will launch producer
    std::thread t1(&Producer);

    //will launch consumer
    std::thread t2(&Consumer);

    std::cout << "Main continuous chilling! Asks for 15 crores to fire employees advice!\n";
    std::cout << "Main can literally shut down TCS!\n";

    t1.join();
    t2.join();

    std::cout << "That's all. GoodBye!\n";

}

/*
    3 perspectives

    Main function
    -------------
    a) I created t1 thread(producer)
    b) I created t2 thread(Consumer)
    c) first cout
    d) second cout
    e) t1 join
    f) t2 join
    g) goodbye cout
    h) terminate app!

    Producer perspective:
    --------------------
    a) Executed a loop. In the loop til  m_inputReceived is true:
        a1) took a value
        a2) checked if input is greater than 5, make flag true

    b) Acquire a mutex so that nobody disturbs
    c) send a signal via notify_one()
*/