#include "Engine.h"
#include "Functionalities.h"

int main(){
    Engine* engines[4];
    CreateObjects(engines,4);
    std::cout<<"The average power is : "<<AverageHorsePower(engines, 4)<<"\n";
    try{
        std::cout<<"The torque is: "<<FindTorqueById(engines,4,102)<<"\n";
    }
    catch(IdNotFoundException& msg){
        std::cerr << msg.what() << "\n";
    }
    try{
       std::cout << "The lowest horse power is: " << FindHorsePowerForMinTorqueEngine(engines, 4) <<"\n";
    }
    catch(IdNotFoundException& msg){
        std::cerr << msg.what() << "\n";
    }

}