#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Engine.h"
#include <vector>
#include "IdNotFoundException.h"
#include "NoValidEngineFoundException.h"

using Container=std::vector<Engine*>;

void CreateObjects(Container& engines);

int AverageHorsePower(Container& engines);

float FindTorqueById(const Container& engines,unsigned int id);

int FindHorsePowerForMinTorqueEngine(const Container& engines);

#endif // FUNCTIONALITIES_H

