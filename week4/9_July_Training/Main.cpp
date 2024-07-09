#include "Functionalities.h"
#include<iostream>

int main(){
    DataContainer data; 
    auto fn=[](EnginePtr engine){return engine->type()==EngineType::ICE;};
    CreateObjects(data);
    std::future<std::optional<DataContainer>>result= std::async(&ReturnMatchingInstance,fn,data);
    std::optional<DataContainer> res1 = result.get();
    if(res1.has_value()){
        for(const EnginePtr ptr:res1.value()){
            std::cout << "Matching instance found : \t" << *ptr <<"\n";//we get address only with ptr and *ptr gives values
        }
    }
    std::future<bool> result2 = std::async(&IsAtleastOneInstanceMatching,fn,data);
    std::cout<<std::boolalpha<<result2.get()<<"\n";
    std::future<float>result3 = std::async(&AverageEngineCC,data);
    std::cout <<"Average : \t"<<result3.get()<<"\n";
    
}