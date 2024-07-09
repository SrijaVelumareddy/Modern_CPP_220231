#include "Functionalities.h"

void CreateObjects(DataContainer &engines)
{
    engines.emplace_back(new Engine("e1",EngineType::ICE,32.0f,15.0f,44));
    engines.emplace_back(new Engine("e2",EngineType::HYBRID,32.0f,15.0f,44));
    engines.emplace_back(new Engine("e3",EngineType::ALTERNATE_FUEL,32.0f,15.0f,44));
    engines.emplace_back(new Engine("e4",EngineType::ICE,32.0f,15.0f,44));
    engines.emplace_back(new Engine("e5",EngineType::HYBRID,32.0f,15.0f,44));
    // std::shared_ptr<Engine> sptr { new Engine("e1",EngineType::ICE,32.0f,15.0f,44)};
    //std::make_shared<Engine> { "e1",EngineType::ICE,32.0f,15.0f,44 };

}

std::optional<DataContainer> ReturnMatchingInstance(const Predicate &predicate_fn, const DataContainer &engines)
{
    bool m_input_empty{false}; //flag to check if input was empty
    if(engines.empty()){
        std::cerr<<"Data container is emoty\n";
        m_input_empty=true; //set it to true
    }
    DataContainer result{};
    /*
        for each EnginePtr in engines,
        check if predicate_fn is applicable on the pointer.
        If yes, store it in result
    */
    for(const EnginePtr& ptr:engines){
        if(predicate_fn(ptr)){
            result.emplace_back(ptr);
        }
    }
    //if input is not empty but result is empty
    if(!m_input_empty && result.empty()){
        return std::nullopt;
    }
    //if input is not empty and result has some data
    else if(!m_input_empty){
        return result;
    }
    else {
        return std::nullopt;
    }
    return std::optional<DataContainer>();
}

bool IsAtleastOneInstanceMatching(const Predicate &predicate_fn, const DataContainer &engines)
{
    bool m_input_empty{false}; //flag to check if input was empty
    if(engines.empty()){
        std::cerr<<"Data container is empty\n";
        m_input_empty=true; //set it to true
    }
    for(const EnginePtr& ptr:engines){
        if(predicate_fn(ptr)){
            return true;
        }//should not return false bcz the atleast one instance is needed. so it may be found at 2nd, 3rd or . so if we return here it means we are checking only the first obj and getting out of if loop. So return after for loop so that we can check the entire loop of objects.
    }
    return false;
}

float AverageEngineCC(const DataContainer &engines)
{
    bool m_input_empty{false}; //flag to check if input was empty
    if(engines.empty()){
        std::cerr<<"Data container is empty\n";
        m_input_empty=true; //set it to true
    }
    float total {0.0f};

    for(const EnginePtr& ptr:engines){
        total += ptr->engineCc();
    }

    if(m_input_empty){
        return 0.0f; //can return it in if block also
    }

    return total/engines.size();

}

/*
    ex1:
        std::list<int> engines;
        engines.emplace_back(99);
    ex2:
        std::list<int*> engines;
        engines.emplace_back(new int{10});
    ex3:
        std::list< std::variant<int,std::string
*/