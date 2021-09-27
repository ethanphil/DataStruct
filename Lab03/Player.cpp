#include "Player.h"
#include "Game.h"

bool Player::AddCardToHand(Card *c)
{
    m_hand->AddCard(c);
};

bool Player::AddCardToStack(Card *c)
{
    m_stack->AddCard(c);
};

Card *Player::RemoveCardFromHandByInt(int i)
{
    m_hand->RemoveCardAt(i);
};

CardPile *Player::GetHand()
{
    return m_hand;
}

Card *Player::RemoveCardFromHand()
{
    return m_hand->UnQueue();
}
