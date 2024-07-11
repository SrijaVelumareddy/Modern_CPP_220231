#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "Engine.h"
#include<list>
#include<functional>
#include<memory>

using EnginePtr=std::shared_ptr<Engine>;
using DataContainer=std::list<EnginePtr>;
using Predicate=std::function<bool(EnginePtr)>;

void CreateObjects(DataContainer& data);

DataContainer ReturnMatchingInstance(Predicate predicate_fn,DataContainer& data);

bool IsAtleastOneObjectFound(Predicate predicate_fn, DataContainer& data);

float AverageCC(DataContainer& data);



#endif // OPERATIONS_H
