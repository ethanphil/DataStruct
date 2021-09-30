#include "Player.h"
#include <iostream>

Player::Player(std::string name)
{
    m_name = name;
    m_stack = new CardPile();
    m_hand = new CardPile();
}

Player::~Player()
{
    std::cout << "Deleting Player " + m_name << std::endl;
    delete m_hand;
    delete m_stack;
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
    return m_hand->RemoveCardAt(i);
}

CardPile *Player::GetHand()
{
    return m_hand;
}

CardPile *Player::GetStack()
{
    return m_stack;
}

Card *Player::RemoveCardFromHand()
{
    return m_hand->UnQueue();
}

Card *Player::MoveCardFromHandToStack(int i)
{
    auto card = m_hand->GetCardAt(i);
    RemoveCardFromHandByInt(i);
    AddCardToStack(card);
    return card;
}

std::string Player::GetName()
{
    return m_name;
}

void Player::PrintHand()
{
    std::cout << m_hand->ToString() << std::endl;
}

void Player::PrintStack()
{
    std::cout << m_stack->ToString() << std::endl;
}

void Player::PrintCards()
{
    std::cout << "Hand: " << std::endl;
    PrintHand();
    std::cout << "Stack: " << std::endl;
    PrintStack();
}

bool Player::IsValidMove(int c)
{
    if (m_stack->GetSize() == 0 && m_hand->GetCardAt(c)->m_value == 1)
    {
        return true;
    }
    else if (m_hand->GetCardAt(c)->m_value == m_stack->GetTop()->m_value + 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Player::CheckWon()
{
    if (m_stack->GetSize() == 13)
    {
        return true;
    }
    else 
    {
        return false;
    }
}