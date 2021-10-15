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
	TEST(CardTests, isSuit)
	{
		Card card = Card(13, Suits::Suit::Hearts);
		ASSERT_EQ(card.m_suit, Suits::Suit::Hearts);
	}

	TEST(CardTests, isValue)
	{
		Card card = Card(5, Suits::Suit::Spades);
		ASSERT_EQ(card.m_value, 5);
	}

	TEST(CardTests, isString)
	{
		Card card = Card(7, Suits::Suit::Clubs);
		ASSERT_EQ("7 of Clubs", card.ToString());
	}
 
	TEST(CardPileTests, AddCardToBottom)
	{
		CardPile pile;
		pile.AddCard(new Card(3,Suits::Suit::Clubs));
		pile.AddCardToBottom(new Card(6, Suits::Suit::Hearts));
		ASSERT_EQ(pile.GetTop()->m_value, 3);
		ASSERT_EQ(pile.GetSize(), 2);
	}

	TEST(CardPileTests, AddingCardToBottom)
	{
		CardPile pile;
		pile.AddCard(new Card(9,Suits::Suit::Spades));
		pile.AddCardToBottom(new Card(12, Suits::Suit::Diamonds));
		ASSERT_EQ(pile.GetTop()->m_value, 9);
		ASSERT_EQ(pile.GetSize(), 2);
	}

	TEST(CardPileTests, ToString)
	{
		CardPile pile;
		pile.AddCard(new Card(9,Suits::Suit::Spades));
		pile.AddCardToBottom(new Card(12, Suits::Suit::Diamonds));
		std::string test = pile.ToString();
		ASSERT_EQ(pile.ToString(), "Card 1: 12 of Diamonds\nCard 2: 9 of Spades\n");
	}

	TEST(PlayerTests, PlaceCard)
	{
		Player p = Player("Jane Doe");
		p.AddCardToHand(new Card(3, Suits::Suit::Spades));
		p.MoveCardFromHandToStack(0);
		ASSERT_EQ(p.GetStack()->GetSize(), 1);
	}

	TEST(PlayerTests, IsValidMove)
	{
		Player p = Player("Doe Jane");
		p.AddCardToStack(new Card(1, Suits::Suit::Clubs));
		p.AddCardToHand(new Card(3, Suits::Suit::Diamonds));
		ASSERT_FALSE(p.IsValidMove(0));
	}

	TEST(PlayerTests, RemoveCard)
	{
		Player p = Player("John Doe");
		p.AddCardToHand(new Card(4, Suits::Suit::Spades));
		p.AddCardToHand(new Card(10, Suits::Suit::Hearts));
		ASSERT_EQ(p.RemoveCardFromHandByInt(0)->m_value, 4);
		ASSERT_EQ(p.GetHand()->GetSize(), 1);
	}

	TEST(GameTests, ConstructorMadeDeck)
	{
		Game g = Game();
		ASSERT_EQ(g.GetDeck()->GetSize(), 52);
	}

	TEST(GameTests, AddPlayers)
	{
		Game g = Game();
		g.AddPlayer("Tom");
		g.AddPlayer("Jeff");
		g.AddPlayer("Jill");
		ASSERT_EQ(g.GetPlayerCount(), 3);
	}

	TEST(GameTests, DealCards)
	{
		Game g = Game();
		g.AddPlayer("Tom");
		g.AddPlayer("Jeff");
		g.AddPlayer("Jill");
		g.DealCards();
		ASSERT_EQ(g.GetDeck()->GetSize(), 37);
	}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
