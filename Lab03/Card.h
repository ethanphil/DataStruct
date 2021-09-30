#pragma once
#include "Suits.h"

class Card{
public:
    Card(int value, Suits::Suit suit);
    ~Card();
    std::string ToString();
    int m_value;
    Suits::Suit m_suit;
};
