#include"Function.h"

int main(){
    BankAccountContainer account;
    createObjects(account);
    showDetails(account, 142356789);

    auto fn =[](const BankAccount* b){return b->attachedCard()->cardType() == DebitCardType::VISA;};
    countVisaCard(fn,account);

    deallocate(account);

}