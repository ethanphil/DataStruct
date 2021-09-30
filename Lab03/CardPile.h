#pragma once
#include "Card.h"
#include <vector>

class CardPile{
    public:
    CardPile();
    ~CardPile();
    void ShuffleCards();
    bool AddCardToBottom(Card *c);
    bool AddCard(Card *c);
    Card *UnQueue();
    Card *GetTop();
    bool RemoveCardAt(int i);
    Card *GetCardAt(int i);
    int GetSize();
    std::string ToString();
    private:
    std::vector<Card*> m_cards;
};