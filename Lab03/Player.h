#pragma once
#include "CardPile.h"
#include <string>

class Player{
public:
    bool AddCardToHand(Card *c);
    bool AddCardToStack(Card *c);
    Card *RemoveCardFromHandByInt(int i);
    Card *RemoveCardFromHand();
    CardPile *GetHand();
private:
    CardPile * m_hand;
    CardPile * m_stack;
    std::string * m_name;
};