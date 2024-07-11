#include "Operations.h"

void CreateObjects(DataContainer& data)
{
    data.emplace_back(new Engine("e1",EngineType::ICE,56.0f,32.0f,354));
    data.emplace_back(new Engine("e2",EngineType::HYBRID,46.0f,27.0f,256));
    data.emplace_back(new Engine("e3",EngineType::ALTERNATE_FUEL,43.0f,32.0f,300));
    data.emplace_back(new Engine("e4",EngineType::ICE,87.0f,46.0f,270));
    data.emplace_back(new Engine("e5",EngineType::HYBRID,75.0f,53.0f,390));

}

DataContainer ReturnMatchingInstance(Predicate predicate_fn,DataContainer& data){
    if(data.empty()){
        std::cerr<<"Data is empty\n";
    }
    DataContainer result{};
    bool input_empty{false};
    for(EnginePtr& ptr : data){
        if(predicate_fn(ptr)){
            result.emplace_back(ptr);
            input_empty=true;
        }       
    }
}

bool IsAtleastOneObjectFound(Predicate predicate_fn, DataContainer& data){
    if(data.empty()){
        std::cerr<<"Data is empty\n";
    }
    for(EnginePtr& ptr : data){
        if(predicate_fn(ptr)){
            return true;
        }
    }
    return false;

}

float AverageCC(DataContainer& data){
    if(data.empty()){
        std::cerr<<"Data is empty\n";
        
    }
    bool input_empty{false};
    float total {0.0f};
    for(EnginePtr& ptr : data){
        total+=ptr->engineCc();
        input_empty=true;
    }
    if(input_empty){
        return 0.0f;
    }
    return total/data.size();

}





