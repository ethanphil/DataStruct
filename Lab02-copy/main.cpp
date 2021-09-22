// TowerHannoiGame.cpp : Defines the entry point for the console application.
//

#include "StackQueue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class TowersOfHannoiGame
{
public:
	TowersOfHannoiGame()
	{

		for(int i = 0; i < diskNum; i++){
			towers[0].push(4-i);
		}

	}

	bool IsGameEnded() { return m_GameEnded; }

	void PrintTowers()
	{

		cout << "Tower 1: " + towers[0].toString() << endl;
		cout << "Tower 2: " + towers[1].toString() << endl;
		cout << "Tower 3: " + towers[2].toString() << endl;
	}

	bool CheckMove(int diskId, int fromId, int toId)
	{
		try
		{
			if ((towers[fromId - 1].peek() != diskId))
			{
				cout << "Disk " << diskId << " is not on top of tower " << fromId << endl;
				return false;
			}
		}catch(...){return false;}
		try 
		{
			if (towers[toId - 1].peek() < diskId)
			{
				cout << "Cannot move larger disk onto smaller disk" << endl;
				return false;
			}
		}catch(...){return true;}
		return true;
	}

	void QueueMove(std::string val)
	{
		queue.enQueue(val);
	}

	void WriteMoves(){
		ofstream movesOut;
		std::string line;
		movesOut.open ("moves.txt", ios::out);
		if(movesOut.is_open()){
			for(int i = queue.getFront(); i <= queue.getBack(); i++){
				line = queue.peekFront() ;
				movesOut << line << endl;
				queue.deQueue();
			}
				movesOut.close();
		}
		else{
			cout << "could not open moves.txt" << endl;
		}

	}

	bool WinCon(){
		if(towers[2].peek() == 1 && towers[2].getStackCount() == 4){
			cout << "You have won" << endl
				<< "ending game and saving moves" << endl;
			return true;
		}
		else{
			return false;
		}
	}

	bool MakeMove(int diskId, int fromId, int toId)
	{
		QueueMove(to_string(diskId) + "," + to_string(fromId) + "," + to_string(toId));
		towers[fromId-1].pop();
		towers[toId-1].push(diskId);
		if (towers[2].toString() == "4 3 2 1")
		{
			m_GameEnded = true;
		}
	}
private:
	bool m_GameEnded;
	ArrayBasedStack towers[3];
	ArrayBasedQueue queue;
	int diskNum = 4;
};

int main()
{

	cout << "Enter in moves to make for Towers  of  Hannoi" << endl;
	cout << "Progam will exit once towers have  been successfully moved of" << endl;
	cout << "or string of -1 is entered. Moves must be entired in format of" << endl;
	cout << "<disk>,<column from>,<column to>   NOTE no spaces!!!!" << endl;

	TowersOfHannoiGame game;

	std::string inputLine;
	ifstream moves;
	moves.open("moves.txt",ios::in);

	bool receivedEndToken = false;
	bool invalidToken= false;
	bool validMove = false;

	while (!receivedEndToken && game.IsGameEnded())
	{
		invalidToken = false;
		game.PrintTowers();


		cout << "Enter Move " << endl;
		getline(cin, inputLine);
		if (inputLine == "-1")
		{
			receivedEndToken = true;
		}

		else
		{
			std::vector<std::string> output;
			std::string::size_type prev_pos = 0, pos = 0;
			// Snippet from https://stackoverflow.com/questions/5167625/splitting-a-c-stdstring-using-tokens-e-g
			// tokenizing a string
			while ((pos = inputLine.find(",", pos)) != std::string::npos)
			{
				std::string substring(inputLine.substr(prev_pos, pos - prev_pos));
				output.push_back(substring);
				prev_pos = ++pos;
			}
			//Need to get last token
			output.push_back(inputLine.substr(prev_pos, pos - prev_pos)); // Last word

			if (output.size() != 3)
			{
				cout << "Invalid input recieved = " + inputLine << endl;
				invalidToken = true;
				continue;
			}
			else
			{
				std::string disk = output[0];
				std::string from = output[1];
				std::string to = output[2];

				if (disk.size() == 0 || from.size() == 0 || to.size() == 0)
				{
					cout << "Invalid input recieved = " + inputLine << endl;
					invalidToken = true;
					continue;
				}

				int diskId = atoi(disk.c_str()); 
				int fromId = atoi(from.c_str());
				int toId = atoi(to.c_str());
				//if any number is zero we didn't have a integer
				if (diskId == 0 || diskId > 4 || fromId == 0 || fromId > 3 || toId == 0 || toId > 3 || toId == fromId)
				{
					cout << "Invalid input recieved = " + inputLine << endl;
					invalidToken = true;
					continue;
				}

				cout << "Disk " << diskId << " From " << fromId << " To " << toId << endl;

				
				if(!invalidToken){
					if (game.CheckMove(diskId, fromId, toId))
					{
						game.MakeMove(diskId, fromId, toId);
					}
				}
				
				receivedEndToken = game.WinCon();

			}
		}


	}

	game.WriteMoves();

    return 0;
}

