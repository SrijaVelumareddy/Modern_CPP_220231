#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include<iostream>
#include"BankAccountType.h"
#include"DebitCard.h"

class BankAccount
{
private:
    long m_account_number;
    std::string m_holder_name;
    int m_balance;
    BankAccountType m_type;
    DebitCard* m_attached_card;

public:
    BankAccount(long number, std::string name, int balance,BankAccountType type, DebitCard* card);
    ~BankAccount();

    long accountNumber() const { return m_account_number; }

    std::string holderName() const { return m_holder_name; }

    int balance() const { return m_balance; }

    BankAccountType type() const { return m_type; }

    DebitCard* attachedCard() const { return m_attached_card; }

    friend std::ostream &operator<<(std::ostream &os, const BankAccount &rhs) {
        os << "m_account_number: " << rhs.m_account_number <<"\n"
           << " m_holder_name: " << rhs.m_holder_name<<"\n"
           << " m_balance: " << rhs.m_balance<<"\n"
           << " m_type: " << (int)rhs.m_type<<"\n"
           << " m_attached_card: " << *rhs.m_attached_card<<"\n";
        return os;
    }

    
};

#endif // BANKACCOUNT_H
