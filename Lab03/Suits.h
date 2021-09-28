#pragma once
#include <string>

namespace Suits{
    enum class Suit {Hearts, Diamonds, Clubs, Spades};
    std::string ToString(Suit s);
}