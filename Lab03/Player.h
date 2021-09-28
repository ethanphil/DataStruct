#pragma once
#include "CardPile.h"
#include "Game.h"

class Player{
    public:
    Player(std::string name);
    Card* DrawCard(Game *game);
    bool AddCardToHand(Card *c);
    bool AddCardToStack(Card *c);
    Card *RemoveCardFromHandByInt(int i);
    Card *RemoveCardFromHand();
    CardPile *GetHand();
    void MoveCardFromHandToStack(int i);
    private:
    CardPile * m_hand;
    CardPile * m_stack;
    std::string m_name;
};