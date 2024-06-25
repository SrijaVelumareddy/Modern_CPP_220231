#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Engine.h"
#include "IdNotFoundException.h"
#include "NullArrayException.h"

void CreateObjects(Engine** engines, unsigned int size);

int AverageHorsePower(Engine** engines, unsigned int size);

float FindTorqueById(Engine** engines, unsigned int size, unsigned int id);

float FindHorsePowerForMinTorqueEngine(Engine** engines, unsigned int size);

#endif // FUNCTIONALITIES_H

