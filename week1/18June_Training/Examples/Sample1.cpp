/*

    problems with regular enums
*/

#include <iostream>

enum class Gear {
    FIRST,
    SECOND
};

enum class Rank {
    FIRST,
    SECOND

};

void Magic(int n1){
    std::cout << n1 * 100 << "\n";
}

int main() {
    FIRST; //problem1: Not mandatory to prefix enum name (confusion)

    Gear g1 = Gear::FIRST;
    Rank r1 = Rank::FIRST;

    if(g1 == r1) //problem2: enums of two different categories get compared on basis of integer value
    {
        std::cout << "No" << "\n";
    }
    Magic(r1); //problem3: auto conversion of enum to integer without consent!!
}

//all these problems can be solved by using enum class