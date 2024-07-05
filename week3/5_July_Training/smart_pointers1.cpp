#include<iostream>
#include<memory> //cpp11 feature
//If you want to use smartpointers, don't create lvalue raw pointers
class Data
{
private:
    int m_value{0};
public:
    Data()=default;
    ~Data()=default;
    Data(const Data&)=default;
    Data(Data&&)=delete;
    Data& operator=(const Data&)=delete;
    Data& operator=(Data&&)=delete;

    explicit Data(int val) : m_value{val} {}

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }

};

int main(){
    int32_t x {10};
    char grade {'A'};
    // int* ptr= (int*)malloc(4);
    // char* ptr2=(char*)malloc(1);

    std::unique_ptr<int> ptr1 { (int*)malloc(4) };
    std::unique_ptr<int> ptr2 { new int };
    std::unique_ptr<char> ptr3 { (char*)malloc(1) };

    std::unique_ptr<Data>ptr4 { new Data{100}};

    //By using unique_ptr you don't have to deallocate the memory manually it automatically deletes the heap memory. Even if you throw an exception any how the memory is deleted.

    if(true){
        std::cout << *ptr1 << "\n";
    }
    else{
        throw ;//
    }
}
/*
stack main function
                 
    0x108H      ptr1        0x242117H
    0x104H      grade       'A
    0x100H      x           10
*/
// malloc() specifies how many bytes you want to allocate to malloc;

/*
        void CalculateResult(input value){
            //allocate something on heap
            ptr=heap memory address

            if(value==condition){
                do something with ptr
            }
            else{
                throw an exception
            }
        }
        This code given memory leak because we are not deleting the heap memory. so delete ptr; has to be given in 2 places. One is if the condition is true and operation is done and second is before exception bcz once the exception is reached you are thrown out of the function. Now ptr gets deleted and you cannot delete the heap memory.

        void CalculateResult(input value){
            //allocate something on heap
            ptr=heap memory address

            if(value==condition){
                do something with ptr
                //action to do
                if(condition1){
                    take action
                } else if(condition2){
                    throw exception
                } else if(condition3){
                    throw exception
                }
                else{
                    do something
                }
            }

*/

/*
    Smart pointers
    Shared pointers
    Unique pointers
*/