#include "Card.h"

Card::Card(int i, Suit suit)
{
    *m_value = i;
    *m_suit = suit;
}