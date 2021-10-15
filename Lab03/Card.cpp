#include "Card.h"
#include <iostream>

Card::Card(int i, Suits::Suit suit)
{
    m_value = i;
    m_suit = suit;
}

Card::~Card()
{
    
}

std::string Card::ToString()
{
    return std::to_string(m_value) + " of " + Suits::ToString(m_suit);
}