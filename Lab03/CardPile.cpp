#include "CardPile.h"
#include "Suits.h"
#include <algorithm>
#include <iostream>

CardPile::CardPile()
{
    m_cards.clear();
    
}

CardPile::~CardPile()
{
    for (auto c : m_cards)
    {
        delete c;
    }
}

void CardPile::ShuffleCards()
{
    std::random_shuffle(m_cards.begin(), m_cards.end());
}

bool CardPile::AddCard(Card *c)
{
    m_cards.push_back(c);
    return true;
}

bool CardPile::AddCardToBottom(Card *c)
{
    m_cards.insert(m_cards.begin(), c);
    return true;
}

Card *CardPile::UnQueue()
{
    Card *rCard = m_cards.back();
    m_cards.pop_back();
    return rCard;
}

Card *CardPile::GetTop()
{
    return m_cards.back();
}

Card *CardPile::RemoveCardAt(int i)
{
    auto card = m_cards.at(i);
    m_cards.erase(m_cards.begin()+i);
    return card;
}

Card *CardPile::GetCardAt(int i)
{
    return m_cards.at(i);
}

int CardPile::GetSize()
{
    return m_cards.size();
}

std::string CardPile::ToString()
{
    std::string rstr = "";
    for (int i = 0; i < m_cards.size(); i++)
    {
        rstr += "Card " + std::to_string(i+1) + ": " + std::to_string(m_cards.at(i)->m_value) + " of " + Suits::ToString(m_cards.at(i)->m_suit) + "\n";
    }
    return rstr;
}