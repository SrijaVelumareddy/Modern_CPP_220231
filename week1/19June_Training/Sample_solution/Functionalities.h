#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Engine.h"
#include <vector>
#include "IdNotFoundException.h"
#include "NullArrayException.h"
#include "NoValidEngineFoundException.h"

void CreateObjects(std::vector<Engine*>& engines);

int AverageHorsePower(const std::vector<Engine*>& engines);

float FindTorqueById(const std::vector<Engine*>& engines,unsigned int id);

int FindHorsePowerForMinTorqueEngine(const std::vector<Engine*>& engines);

#endif // FUNCTIONALITIES_H

