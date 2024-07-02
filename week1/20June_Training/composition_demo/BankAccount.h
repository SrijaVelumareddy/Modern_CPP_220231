#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include "DebitCard.h"
#include "BankAccountType.h"

class BankAccount
{
private:
    long m_accountNumber;
    std::string m_accountHolderName;
    float m_accountBalance;
    BankAccountType m_accountType;
    DebitCard* m_attached_card; //pointer heap allocation
public:
    BankAccount(long number, std::string name, float balance, BankAccountType accountType, DebitCard& card);
    
    ~BankAccount();

    DebitCard* attachedCard() const { return m_attached_card; }

    long accountNumber() const { return m_accountNumber; }

    friend std::ostream &operator<<(std::ostream &os, const BankAccount &rhs);

};

#endif // BANKACCOUNT_H
