#include "Card.h"
#include "CardPile.h"
#include "Game.h"
#include "Player.h"
#include "Suits.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;
static int guid = 1;

int main()
{
	Game *game = new Game();
	bool exitFlag = false;
	while (!exitFlag && game->GetPlayerCount() < 4)
	{
		std::string tempName = "";
		cout << "Enter a player name, or enter 1 to finish: ";
		cin >> tempName;
		if (tempName == "1")
		{
			if (game->GetPlayerCount() == 0)
			{
				cout << "There are not enough players, you must enter at least one player name" << endl;
				continue;
			}
			else 
			{
				exitFlag = true;
			}
		}
		else
		{
			game->AddPlayer(tempName);
		}
	}

	game->PrintPlayers();
	game->StartGame();
	delete game;
    return 0;
}

