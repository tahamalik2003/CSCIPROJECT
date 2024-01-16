
#include <iostream>
#include "Deck.hpp"


// Default constructor
template <typename CardType>
Deck<CardType>::Deck()
{
}

// Destructor
template <typename CardType>
Deck<CardType>::~Deck()
{
}

// Add card to deck
template <typename CardType>
void Deck<CardType>::AddCard(const CardType &card)
{
    cards_.push_back(card);
}

// Draw card from the deck
template <typename CardType>
CardType &&Deck<CardType>::Draw()
{
    if (IsEmpty())
    {
        throw std::runtime_error("Cannot draw from an empty deck.");
    }

    CardType &&drawnCard = std::move(cards_.back());
    cards_.pop_back();
    return std::move(drawnCard);
}

// Checks if deck is empty
template <typename CardType>
bool Deck<CardType>::IsEmpty() const
{
    return cards_.empty();
}

// Shuffle deck
template <typename CardType>
void Deck<CardType>::Shuffle()
{
    // Create a random number generator using std::mt19937 with seed 2028358904
    std::mt19937 rng(2028358904);
    // Shuffle the vector of cards using the random number generator
    std::shuffle(cards_.begin(), cards_.end(), rng);
}

// Returns size of deck
template <typename CardType>
int Deck<CardType>::getSize() const
{
    return cards_.size();
}

// Returns vector of cards in deck
template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const
{
    return cards_;
}