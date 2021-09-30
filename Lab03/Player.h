#pragma once
#include "CardPile.h"

class Player{
    public:
    Player(std::string name);
    ~Player();
    bool AddCardToHand(Card *c);
    bool AddCardToStack(Card *c);
    bool IsValidMove(int c);
    Card *RemoveCardFromHandByInt(int i);
    Card *RemoveCardFromHand();
    CardPile *GetHand();
    CardPile *GetStack();
    Card *MoveCardFromHandToStack(int i);
    std::string GetName();
    void PrintHand();
    void PrintStack();
    void PrintCards();
    bool CheckWon();
    private:
    CardPile * m_hand;
    CardPile * m_stack;
    std::string m_name;
};