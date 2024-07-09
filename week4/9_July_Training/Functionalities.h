#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Engine.h"
#include<list>
#include<memory>
#include<functional>
#include<optional>
#include<thread>
#include<future>

// using DataContainer=std::list<std::shared_ptr<Engine>>;
// using Predicate=std::function<bool(std::shared_ptr<Engine>)>;

using EnginePtr=std::shared_ptr<Engine>;
using DataContainer=std::list<EnginePtr>;
using Predicate=std::function<bool(const EnginePtr)>;


// void CreateObjects(DataContainer& data);
/*
    CreateObjects
    input: Empty container reference
    output: void
*/
void CreateObjects(DataContainer& engines);

// DataContainer ReturnMatchingContainer(const Predicate fn, DataContainer& data);
/*
    ReturnMatchingInstances
    input: DataContainer reference, function wrapper for predicate
    output: DataContainer of matching instances
*/
std::optional<DataContainer> ReturnMatchingInstance(const Predicate& predicate_fn,const DataContainer& engines);

// DataContainer ReturnMatchingInstance(const Predicate fn, DataContainer& data);
/*
    IsAtleastOneInstanceMatching
    input: DataContainer reference, function wrapper for predicate
    output: bool
*/
bool IsAtleastOneInstanceMatching(const Predicate& predicate_fn,const DataContainer& engines);

// float Average(const DataContainer& data);
/*
    
*/
float AverageEngineCC(const DataContainer& engines);


#endif // FUNCTIONALITIES_H
