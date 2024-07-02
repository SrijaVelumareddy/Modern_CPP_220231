#include "Function.h"

void createObjects(BankAccountContainer &account)
{
    account.emplace_back(new BankAccount(142356789,"vivi", 45000,BankAccountType::CURRENT, new DebitCard(425,"25/2/2025", 789654,DebitCardType::VISA)));


}

void showDetails(const BankAccountContainer &account, long number)
{
    bool flag {false};
    for(const BankAccount* b:account){
        if(b->accountNumber() == number){
            std::cout<<*b<<"\n";
            flag=true;
        }
    }

    if(!flag){
        std::cout<<"No account found!!";
    }
}

void countVisaCard(const Predicate fn, BankAccountContainer &account)
{
    int count {0};
    for(const BankAccount* b: account){
        if(fn(b)){
            count++;
        }
    }
    std::cout<<"the count is : "<<count<<"\n";
}



void deallocate(BankAccountContainer &account)
{
    for(BankAccount* b:account){
        delete b;
    }
}
