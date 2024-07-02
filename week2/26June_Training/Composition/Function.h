#ifndef FUNCTION_H
#define FUNCTION_H

#include"BankAccount.h"
#include"DebitCard.h"
#include<list>
#include<functional>

using BankAccountContainer = std::list<BankAccount*>;
// using DebitCardContainer = std::list<DebitCard*>;
using Predicate = std::function<bool(const BankAccount*)>;

void createObjects( BankAccountContainer& account);

void showDetails(const BankAccountContainer& account,long number);

void countVisaCard(const Predicate fn, BankAccountContainer& account);

void deallocate(BankAccountContainer& account);


#endif // FUNCTION_H
