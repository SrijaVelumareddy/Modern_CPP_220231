#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "BankAccount.h"
#include "AccountNotFoundException.h"

#include<vector>

using Container = std::vector<BankAccount*>;

void CreateObjects(Container accounts);

void DisplayCardDetails(const Container accounts,const long number);

void CountVISACards(const Container& accounts);

void DeallocateMemory(Container& accounts);

#endif // FUNCTIONALITIES_H
