
#include <iostream>
#include "Hand.hpp"


//Default Constructor
Hand::Hand() = default;

//Destructor
Hand::~Hand() {
}

Hand::Hand(const Hand& other) : cards_(other.cards_) {}

Hand& Hand::operator=(const Hand& other) {
    if (this != &other) {
        cards_ = other.cards_;
    }
    return *this;
}

//Move Constructor
Hand::Hand(Hand&& other){
    cards_=std::move(other.cards_);
} 

//Move Assignment Operator
Hand& Hand::operator=(Hand&& other) {
    if (this == &other) {
        return *this;
    }
    cards_ = std::move(other.cards_);
};
//Get the cards in the hand
const std::deque<PointCard>& Hand::getCards() const {
    return cards_;
};

//Add a card to the hand
void Hand::addCard(PointCard&& card) {
    card.setDrawn(true);
    cards_.push_back(std::move(card));
};

//Check if the hand is empty
bool Hand::isEmpty() const {
    return cards_.empty();
};

//Reverse the hand
void Hand::Reverse() {
    int left = 0;
    int right = cards_.size() - 1;
    
    while (left < right) {
        // Swap the elements at 'left' and 'right'
        std::swap(cards_[left], cards_[right]);
        left++;
        right--;
    }
}

//Play a card from the hand
int Hand::PlayCard() {
    if (isEmpty()==false) {
        int point = 0;  
        if(cards_.front().isPlayable()==true ) {
            point = std::stoi(cards_.front().getInstruction());
            cards_.pop_front();
            return point;
        }
        cards_.pop_front();
        return point;
    }

};
/*
#include "Hand.hpp"

// Constructor
Hand::Hand() {}

// Destructor
Hand::~Hand() {}

// Copy Constructor
Hand::Hand(const Hand& other)
{
    cards_ = other.cards_;
}

// Copy Assignment Operator
Hand& Hand::operator=(const Hand& other)
{
    if (this == &other)
    {
        return *this;
    }

    cards_ = other.cards_;
    return *this;
}

// Move Constructor
Hand::Hand(Hand&& other)
{
    cards_ = std::move(other.cards_);
}

// Move Assignment Operator
Hand& Hand::operator=(Hand&& other)
{
    if (this == &other)
    {
        return *this;
    }

    cards_ = std::move(other.cards_);
    return *this;
}

// Getter for cards
const std::deque<PointCard>& Hand::getCards() const
{
    return cards_;
}

// Add a card to the hand
void Hand::addCard(PointCard&& card)
{
    cards_.push_back(std::move(card));
}

// Check if the hand is empty
bool Hand::isEmpty() const
{
    return cards_.empty();
}

// Reverse the hand
void Hand::Reverse()
{
    std::reverse(cards_.begin(), cards_.end());
}

// Play the card at the front of the hand, removing it from the hand
int Hand::PlayCard()
{
    if (isEmpty())
    {
        // Handle the case when the hand is empty
        throw std::runtime_error("Hand is empty");
    }

    PointCard& frontCard = cards_.front();

    if (frontCard.isPlayable())
    {
        // Get the points from playing the card
        int points = std::stoi(frontCard.getInstruction());

        // Remove the card from the hand
        cards_.pop_front();

        return points;
    }
    else
    {
        // The card is not playable, so remove it from the hand
        cards_.pop_front();
        return 0; // No points earned for an unplayable card
    }
}
*/