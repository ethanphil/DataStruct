#include "Game.h"
#include <algorithm>
#include <iostream>

using namespace std;
// TODO standard classes to be tested should be implemented here
Game::Game()
{
    m_isGameEnded = false;
    m_deck = new CardPile();
    CreateDeck();
}

Game::~Game()
{
    cout << "Deleting Game..." << endl;
    for (auto p : m_players)
    {
        delete p;
    }
    delete m_deck;
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
    std::cout << std::endl << "Shuffling Cards.." << std::endl;
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

void Game::PlayerDrawCard(Player *p)
{
    p->AddCardToHand(m_deck->UnQueue());
}

void Game::AddPlayer(std::string s)
{
    m_players.push_back(new Player(s));
}

void Game::PrintPlayers()
{
    for (int i = 0; i < m_players.size(); i++)
    {
        std::cout << "Player " + std::to_string(i+1) + ": " + m_players.at(i)->GetName() << std::endl;
    }
}

bool Game::IsGameEnded()
{
    return m_isGameEnded;
}

void Game::StartTurn(Player *player)
{
    bool turnEnded = false;
    cout << "Player " + player->GetName() + "'s turn.." << endl;
    cout << "Your hand: " << endl;
    player->PrintHand();
    cout << "Your Stack: " << endl;
    player->PrintStack();
    cout << endl;

    int tempInput = 0;
    std::string empty = "";
    bool exitFlag = false;
    while (!exitFlag)
    {
        cout << "If you would like to get a whole new hand, enter a -1, otherwise enter a 1" << endl;
        cin >> tempInput;
        getline(cin, empty);
        if (tempInput == -1)
        {
            MovePlayerHandToDeck(player);
            turnEnded = true;
            exitFlag = true;
            for (int i = 0; i < 5; i++)
            {
                player->AddCardToHand(m_deck->UnQueue());
            }
        }
        else if (tempInput == 1)
        {
            exitFlag = true;
            PlayerDrawCard(player);
        }
        else 
        {
            cout << "Invalid input, try again.." << endl;
        }
    }
    player->PrintCards();
    exitFlag = false;
    while (!exitFlag && !turnEnded)
    {
        std::string empty = "";
        cout << "Enter the card index(starting from 1) of the card you want to play, or enter -1 to end your turn: ";
        cin >> tempInput;
        getline(cin, empty);
        empty = "";
        tempInput--;
        if (tempInput > -1 && tempInput < 6 && player->IsValidMove(tempInput))
        {
            auto tempCard = player->MoveCardFromHandToStack(tempInput);
            cout << "Moved " + tempCard->ToString() + " to stack" << endl;
            tempCard = nullptr;
            PlayerDrawCard(player);
            player->PrintCards();
            if (player->CheckWon())
            {
                exitFlag = true;
                turnEnded = true;
                m_winningPlayer = player;
                m_isGameEnded = true;
            }
        }
        else if (tempInput == -2)
        {
            exitFlag = true;
            turnEnded = true;
        }
        else
        {
            cout << "Invalid move, try again.." << endl;
        }
        tempInput = 0;
    }
    if (player->GetHand()->GetSize() > 5)
    {
        exitFlag = false;
        while (!exitFlag && !m_isGameEnded){
            cout << "You must discard a card, enter the index(starting from 1) of the card you want to get rid of: ";
            cin >> tempInput;
            getline(cin, empty);
            if (tempInput > 0 && tempInput < 7)
            {
                PlayerDiscard(player, tempInput-1);
                exitFlag = true;
            }
            else 
            {
                cout << "Invalid input, try again.." << endl;
            }
        }
    }
    cout << "Ending turn.." << endl;

    
}

void Game::StartGame()
{
    DealCards();
    m_currentPlayer = 0;
    while (!IsGameEnded())
	{
		StartTurn(m_players.at(m_currentPlayer));
        CycleNextPlayer();
	}
    if (IsGameEnded())
    {
        cout << m_winningPlayer->GetName() + " HAS WON!!" << endl;    
    }
}

void Game::DealCards()
{
    for (int i = 0; i < 5; i++)
    {
        for (auto player : m_players)
        {
            player->AddCardToHand(m_deck->UnQueue());
        }
    }
}

void Game::CycleNextPlayer()
{
    m_currentPlayer = (m_currentPlayer + 1 ) % m_players.size();
}

void Game::PlayerDiscard(Player *p, int i)
{
    m_deck->AddCardToBottom(p->RemoveCardFromHandByInt(i));
}