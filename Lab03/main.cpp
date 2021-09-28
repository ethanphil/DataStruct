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
	int exitFlag = 0;
	while (exitFlag != 1 && game->GetPlayerCount() > 0)
	{
		std::string tempName = "";
		cout << "Enter a player name, or enter 1 to finish: ";
		cin >> tempName;
		
	}
    return 0;
}

