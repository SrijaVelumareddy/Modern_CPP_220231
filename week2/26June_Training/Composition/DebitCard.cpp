#include "DebitCard.h"

DebitCard::DebitCard(short cc, std::string date, int cardNumber, DebitCardType cardtype):m_card_cc_number{cc}, m_card_expiry_date{date}, m_card_number{cardNumber},m_card_type{cardtype}
{
}

DebitCard::~DebitCard()
{
    std::cout<<"The card with "<<m_card_number<<" is deleted\n";
}
