
#include "Functionalities.h"

void CreateObjects(SmartDevice** devices, unsigned int size){

    float* values1 = new float[3];
    values1[0] = 10.21f; values1[1] = 9.21f; values1[2] = 11.22f;

    float* values2 = new float[3];
    values2[0] = 10.21f; values2[1] = 9.21f; values2[2] = 11.22f;

    float* values3 = new float[3];
    values3[0] = 10.21f; values3[1] = 9.21f; values3[2] = 11.22f;

    devices[0] = new SmartDevice("101", "Mobile", 9000.0f, Technology::BLUETOOTH, values1);
    devices[1] = new SmartDevice("102", "Tablet", 19000.0f, Technology::BLUETOOTH_WIFI, values2);
    devices[2] = new SmartDevice("103", "SmartBand", 2000.0f, Technology::BLUETOOTH, values3);

    
}

void Deallocate(const SmartDevice** devices, const unsigned int size){
    for(unsigned int i = 0; i < size; i++) {
        delete[] devices[i]->arr(); //delete the float values array for this object first.
        //now we can delete the actual object
        delete devices[i];
    }
}


void FindIthIndexValue(const SmartDevice* device, unsigned int idx) {
    if (idx >=0 && idx < 3) {
        std::cout << (*device)[idx] << "\n";
    }   

    else {
        throw std::invalid_argument("Idx is not valid");
    }
}

void FindMaxGSTDeviceId(const SmartDevice **devices, unsigned int size)
{
    float max_value = devices[0]->CalculateGstCost(); //initial object's gst is maximum (assumption)
    std::string id="";

    for(unsigned int i = 0 ; i < size; i++) {
        if (  devices[i]->CalculateGstCost() > max_value ) {
            max_value = devices[i]->CalculateGstCost();
            id = devices[i]->id();
        }
    }

    std::cout << id << "\n";

}
void FilterDevices(Predicate fn, const SmartDevice **devices, const unsigned int size)
{
    bool atleastOneMatchingDeviceFound{false};

    for(unsigned int i=0;i<size;i++){
        if( fn(devices[i])) {
            std::cout <<*devices[i];
            atleastOneMatchingDeviceFound=true;
        }
    }
    if(!atleastOneMatchingDeviceFound) {
        std::cerr << "No matching instance found\n";
    }
}
// object[]

// arr ---> pointers--->object[]


