#include<iostream>
#include<functional>

class Data
{
private:
    int m_value {0};
public:
    Data()=default;
    ~Data()=default;
    Data(const Data&)=delete;
    Data(Data&&)=delete;
    Data& operator=(Data&&)=delete;
    Data& operator=(const Data&)=delete;

    Data(int val) : m_value(val) {}

    void DisplayReading(int factor) {
        std::cout << m_value * factor;
    }

    static void Display(int times){
        std::cout << "Hello World" << times << "times\n";
    }
};

int main(){
    Data obj {18}; //m_value is 18
    // obj.DisplayReading(100); //100 is the factor
    //or
    auto fn = std::bind(&Data::DisplayReading,&obj,100); //obj has to be passed for non-static member function 
    fn(); //obj.DisplayReading(100);

    Data::Display(10); //"Hello World 10 times"

    auto binded_static_display = std::bind( Data::Display, 10);
    binded_static_display(); //Data::Display(10);
}

/*
    For non-static member functions
        a) object address is mandatory
        b) It must be the first argument after specifying the name of the function in bind
        c) You "must" use & symbol with the name of the member function in bind

    For static member functions
        a) No object involved so no address required
        b) You "SHOULD NOT" use & symbol with the name of the function

*/