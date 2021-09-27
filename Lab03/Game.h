// TODO standard classes to be tested should be defined
#pragma once
#include "Player.h"
#include "CardPile.h"

class Game
{
    public:
    void CreateDeck();
    void MovePlayerHandToDeck(Player *p);
    private:
    std::vector<Player*> *m_players;
    CardPile *m_deck;
    CardPile *m_drawPile;
};
