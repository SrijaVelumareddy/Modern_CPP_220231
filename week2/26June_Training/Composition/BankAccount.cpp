#include "BankAccount.h"

BankAccount::BankAccount(long number, std::string name, int balance, BankAccountType type, DebitCard *card):m_account_number{number}, m_holder_name{name},m_balance{balance},m_type{type},m_attached_card{card}
{
}

BankAccount::~BankAccount()
{
    delete m_attached_card;
    std::cout<<"The bank account number "<<m_account_number<<" is deleted\n";
}
