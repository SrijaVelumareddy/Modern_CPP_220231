#include "Functionalities.h"

int main() {
    std::vector<BankAccount*> accounts;
    CreateObjects(accounts);
    /*
        write other parts of client code here
    */
    DeallocateMemory(accounts);
}