#include "Game.h"
#include "Player.h"
#include <algorithm>

// TODO standard classes to be tested should be implemented here
Game::Game()
{
    CreateDeck();
}

void Game::CreateDeck()
{
    for(int i = 1; i < 14; i++)
    {
        m_deck->AddCard(new Card(i, Suits::Suit::Diamonds));
        m_deck->AddCard(new Card(i, Suits::Suit::Hearts));
        m_deck->AddCard(new Card(i, Suits::Suit::Spades));
        m_deck->AddCard(new Card(i, Suits::Suit::Clubs));
    }
    m_deck->ShuffleCards();
}

void Game::MovePlayerHandToDeck(Player *p)
{
    auto hand = p->GetHand();
    while (hand->GetSize() > 0)
    {
        m_deck->AddCardToBottom(p->RemoveCardFromHand());
    }
}

void Game::MovePlayerCardToDeck(Player *p, int c)
{
    auto hand = p->GetHand();
    auto card = hand->GetCardAt(c);
    m_deck->AddCardToBottom(card);
    hand->RemoveCardAt(c);
}

CardPile *Game::GetDeck()
{
    return m_deck;
}

int Game::GetPlayerCount()
{
    return m_players.size();
}