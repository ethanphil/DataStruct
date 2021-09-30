// tests.cpp
#pragma 
#include <fstream>
#include <gtest/gtest.h>
#include "Suits.h"
#include "Card.h"
#include "CardPile.h"
#include "Game.h"
#include "Player.h"

		//Suits Class
	TEST(Card,isSuit)
	{
		
		Card card1(13, Suits::Suit::Hearts);




	}

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
