#include"Functionalities.h"

int main(){
    DataContainer vehicles{};

    CreateVehicleObjects(vehicles);

    auto result1=std::count_if(
        vehicles.begin(),
        vehicles.end(),
        [](VehiclePtr& v){
            return v->VehicleEngineType()==VehicleEngineType::HYBRID;
        }
    );
    
}