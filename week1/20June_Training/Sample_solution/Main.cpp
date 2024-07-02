#include "Engine.h"
#include "Functionalities.h"

int main(){
    std::vector<Engine*>engines;
    CreateObjects(engines);
    try{
        AverageHorsePower(engines);
    }catch(NoValidEngineFoundException& ex){
        std::cerr << ex.what()<<"\n"; //your handling logic goes here
    }
    try{
        FindTorqueById(engines,102);
    }catch(NoValidEngineFoundException& ex){
        std::cerr << ex.what()<<"\n";
    }catch(IdNotFoundException& ex){
        std::cerr << ex.what()<<"\n";
    }

}