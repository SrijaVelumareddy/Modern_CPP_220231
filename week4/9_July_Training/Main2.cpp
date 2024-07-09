#include "Functionalities.h"

int main(){

    //empty container data
    DataContainer engines {}; //empty initialization
    CreateObjects(engines);
    std::future<std::optional<DataContainer>>res1=std::async(&ReturnMatchingInstance,
        [](const EnginePtr& ptr) {return ptr->engineTorque()>30.0f;
        },std::ref(engines));
    std::future<bool>res2=std::async(&IsAtleastOneInstanceMatching,
        [](const EnginePtr& ptr){return ptr->engineTorque()>15.0f;
        },std::ref(engines));
    std::future<float>res3=std::async(&AverageEngineCC,std::ref(engines));
    bool flag = res2.get();
    std::cout << "Is at least one instance matching condition: " << std::boolalpha << flag << "\n";

    float ans=res3.get();
    std::cout << "Average engine cc : " << ans << "\n";

    std::optional<DataContainer>objects=res1.get();

    if( objects.has_value() ){
        DataContainer pointers = objects.value();
        std::cout << "All pointers with objects satisfying condition: " << "\n";

        for(const EnginePtr e : pointers){
            std::cout << *e << "\n";
        }
    }
}