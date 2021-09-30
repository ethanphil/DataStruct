// TODO standard classes to be tested should be defined
#pragma once
#include "Player.h"
#include "CardPile.h"

class Game
{
    public:
    Game();
    ~Game();
    void CreateDeck();
    void MovePlayerHandToDeck(Player *p);
    void MovePlayerCardToDeck(Player *p, int c);
    CardPile *GetDeck();
    int GetPlayerCount();
    void PlayerDrawCard(Player *p);
    void PlayerDiscard(Player *p, int i);
    void AddPlayer(std::string s);
    void PrintPlayers();
    bool IsGameEnded();
    void StartTurn(Player *p);
    void StartGame();
    void DealCards();
    void CycleNextPlayer();
    private:
    std::vector<Player*> m_players;
    CardPile *m_deck;
    int m_currentPlayer;
    Player *m_winningPlayer;
    bool m_isGameEnded;
};
