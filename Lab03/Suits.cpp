#include "Suits.h"

std::string SuitToString(Suits::Suit s)
{
    switch (s)
    {
    case Suits::Suit::Diamonds:
        return "Diamonds";
        break;
    case Suits::Suit::Hearts:
        return "Hearts";
        break;
    case Suits::Suit::Clubs:
        return "Clubs";
        break;
    case Suits::Suit::Spades:
        return "Spades";
        break;
    default:
        return "";
        break;
    }
}