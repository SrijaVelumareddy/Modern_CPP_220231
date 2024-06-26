#include "Functionalities.h"


int main() {
    SmartDevice* devices[3];

    CreateObjects(devices, 3);
    FilterDevices( [](const SmartDevice* s){ return s->price() > 6000.0f;}, (const SmartDevice**) devices, 3);
    FilterDevices( [](const SmartDevice* s){ return s->deviceTechnology() == Technology::BLUETOOTH;},  (const SmartDevice**)devices, 3);

    Deallocate((const SmartDevice**)devices,3);
}