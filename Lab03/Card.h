#pragma once
#include "Suit.h"

class Card{
public:
    Card(int value, Suit suit);
    int *m_value;
    Suit *m_suit;
};
