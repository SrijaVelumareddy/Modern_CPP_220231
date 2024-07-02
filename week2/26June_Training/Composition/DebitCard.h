#ifndef DEBITCARD_H
#define DEBITCARD_H

#include<iostream>
#include"DebitCardType.h"

class DebitCard
{
private:
    short m_card_cc_number;
    std::string m_card_expiry_date;
    int m_card_number;
    DebitCardType m_card_type;

    
public:
    DebitCard(short cc, std::string date, int cardNumber, DebitCardType cardtype);
    ~DebitCard();

    short cardCcNumber() const { return m_card_cc_number; }

    std::string cardExpiryDate() const { return m_card_expiry_date; }

    int cardNumber() const { return m_card_number; }

    DebitCardType cardType() const { return m_card_type; }

    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs) {
        os << "m_card_cc_number: " << rhs.m_card_cc_number<<"\n"
           << " m_card_expiry_date: " << rhs.m_card_expiry_date<<"\n"
           << " m_card_number: " << rhs.m_card_number<<"\n"
           << " m_card_type: " << (int)rhs.m_card_type <<"\n";
        return os;
    }

    
};

#endif // DEBITCARD_H
