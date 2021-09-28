#include "Player.h"

Player::Player(std::string name)
{
    m_name = name;
}

bool Player::AddCardToHand(Card *c)
{
    m_hand->AddCard(c);
}

bool Player::AddCardToStack(Card *c)
{
    m_stack->AddCard(c);
}

Card *Player::RemoveCardFromHandByInt(int i)
{
    m_hand->RemoveCardAt(i);
}

CardPile *Player::GetHand()
{
    return m_hand;
}

Card *Player::RemoveCardFromHand()
{
    return m_hand->UnQueue();
}

void Player::MoveCardFromHandToStack(int i)
{
    auto card = m_hand->GetCardAt(i);
    RemoveCardFromHandByInt(i);
    AddCardToStack(card);
}

Card *Player::DrawCard(Game *game)
{
    auto deck = game->GetDeck();
    auto card = deck->GetTop();
    deck->UnQueue();
    AddCardToHand(card);
    return card;
}