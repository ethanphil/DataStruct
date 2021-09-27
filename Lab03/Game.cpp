#include "Game.h"
#include "Suit.h"

// TODO standard classes to be tested should be implemented here
void Game::CreateDeck()
{
    for(int i = 1; i < 14; i++)
    {
        m_deck.AddCard(new Card(i, Suit::Diamonds));
    }
}

void Game::MovePlayerHandToDeck(Player *p)
{
    auto hand = p->GetHand();
    while (hand.GetSize() > 0)
    {
        m_deck.AddCardToBottom(p->RemoveCardFromHand());
    }
}