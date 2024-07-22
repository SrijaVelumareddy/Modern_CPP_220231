#include "Functionalities.h"

std::function< bool(const VehiclePtr&, const VehiclePtr&)> comparison_fn=[](const VehiclePtr& v1, const VehiclePtr& v2){
    return v1->vehicleMultimediaType() == v2->vehicleMultimediaType();
};

void CreateVehicleObjects(DataContainer &vehicles)
{
    vehicles.emplace_back(new Vehicle(VehicleType::PRIVATE,VehicleStandard::BS4,VehicleFuelType::ALTERNATE_FUEL,VehicleEngineType::HYBRID,VehicleMultimedia::ANDROID_SMART,30000.0f));

    vehicles.emplace_back(new Vehicle(VehicleType::COMMERCIAL,VehicleStandard::BS6,VehicleFuelType::ICE,VehicleEngineType::REGULAR,VehicleMultimedia::APPLE_SMART,35000.0f));

    vehicles.emplace_back(new Vehicle(VehicleType::RENTAL,VehicleStandard::BS6_2,VehicleFuelType::OTHER,VehicleEngineType::NA,VehicleMultimedia::APPLE_ANDROID_SMART,45000.0f));

    vehicles.emplace_back(new Vehicle(VehicleType::COMMERCIAL,VehicleStandard::BS4,VehicleFuelType::ICE,VehicleEngineType::HYBRID,VehicleMultimedia::ANALOG,50000.0f));
    
    vehicles.emplace_back(new Vehicle(VehicleType::PRIVATE,VehicleStandard::BS6,VehicleFuelType::ALTERNATE_FUEL,VehicleEngineType::NA,VehicleMultimedia::APPLE_ANDROID_SMART,55000.0f));
}

PriorityQueue PrioritizeVehicles(const DataContainer &vehicles)
{
    Comparator fn;
    PriorityQueue pf(vehicles.begin(),vehicles.end(),fn);
    return pf;
}


std::optional<std::size_t> CountOfMatchingEngineTypeObjects(const DataContainer &vehicles, const VehicleEngineType venginetype)
{
    std::optional<std::size_t> result{std::nullopt};
    //// bool m_is_data_found{false};

    // if(vehicles.empty()){
    //     result=std::nullopt;
    // }

    // result=std::count_if(
    //     vehicles.begin(),
    //     vehicles.end(),
    //     [&](const VehiclePtr& v){ return v->vehicleEngineType() == venginetype;}
    // );

    // if(result.has_value()){
    //     return result;//m_is_data_found=true;
    // }

    // std::cerr << "No data is found in input data\n";

    // return result;

    if(vehicles.empty()){
        std::cerr << "No data is found in input data\n";
    }

    else {
        result=std::count_if(
            vehicles.begin(),
            vehicles.end(),
            [&](const VehiclePtr& v){ return v->vehicleEngineType() == venginetype;}
        );
    }

    return result;

}

std::optional<DataContainer> ReturnMatchingVehicles(const DataContainer &vehicles, const Predicate fn)
{
    std::optional<DataContainer> result{std::nullopt};

    if(vehicles.empty()){
        std::cerr << "No data is found in input data\n";
    }
    else{
        DataContainer values{};
        std::copy_if(
            vehicles.begin(),
            vehicles.end(),
            std::inserter(values,values.begin()),
            fn
        );

        if(!values.empty()){
            result=values;
        }
    }
    return result;
}

bool AreAllVehiclesPriceAbove90K(const DataContainer &vehicles,const Predicate fn)
{
    bool flag {false};

    if(vehicles.empty()){
        std::cerr << "No data is found in input data\n";
    }
    else{
        flag=std::all_of(
            vehicles.begin(),
            vehicles.end(),
            [](const VehiclePtr& v){

            }
        );
    }
    return flag;
}

float AverageRegistrationCost(const DataContainer &vehicles)
{
    return 0.0f;
}

std::optional<DataContainer> ReturnLastNObjects(const DataContainer &vehicles,unsigned int N)
{
    std::optional<DataContainer>result{};
    if(vehicles.empty()){
        std::cerr << "No data is found in input data\n";
    }
    if(N>vehicles.size()){
        std::cerr<< "N is invalid as it is more than size\n";
    }
    else{
        DataContainer values{};

        std::copy_n(
            vehicles.rbegin(),
            N,
            std::inserter(values, values.begin())
        );
        result = values;
    }
    return result;
}

std::optional<UniqueVehicles> FindUniqueVehicles(const DataContainer &vehicles)
{
    std::optional<UniqueVehicles> result{ std::nullopt};

    if(vehicles.empty()){
        std::cerr << "No data is found in input data\n";
    }

    else {
        UniqueVehicles values { vehicles.begin(), vehicles.end(), vehicles.size(), hash_logic, comparision_fn};
        result=values;
    }    
    return result;
}
