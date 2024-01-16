#include <iostream>
#include <string>
#include "Card.hpp"

// Big Five and Constructor
        /**
         * Destructor
         * @post: Destroy the Card object
        */
// Destructor
Card::~Card(){
   
    delete [] bitmap_;
    bitmap_ = nullptr;
}

/**
         * Copy Assignment Operator
         * @param const reference to a Card object
         * @return this Card object
         */
// Copy Constructor
Card::Card(const Card& rhs){
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    bitmap_ = new int[80];
    std::copy(rhs.bitmap_, rhs.bitmap_ + 80, bitmap_);
    drawn_ = rhs.drawn_;
}

// Copy Assignment Operator
/*Card& Card::operator=(const Card& rhs)
{
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    
    // Deep copy the bitmap data
    if (bitmap_ != nullptr)
    {
        delete[] bitmap_;
        bitmap_ = nullptr;
    }
    bitmap_ = new int[80];
    std::copy(rhs.bitmap_, rhs.bitmap_ + 80, bitmap_)
    drawn_ = rhs.drawn_;
    return *this;
}
*/
/**
         * Move Constructor
         * @param: rvalue reference to a Card object 
        */
Card& Card::operator=(const Card& rhs){
    if (this == &rhs){
        return *this;
    }
    if (bitmap_ != nullptr) {
        delete[] bitmap_;
        bitmap_ = nullptr;
    }
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    bitmap_ = new int[80];
    std::copy(rhs.bitmap_, rhs.bitmap_ + 80, bitmap_);
    drawn_ = rhs.drawn_;
    return *this;
}
/**
         * Move assignment operator
         * @param: rvalue reference to a Card object
         * @return this card object
        */
// Move Constructor
Card::Card(Card&& rhs){
    cardType_ = rhs.cardType_;
    instruction_ = std::move(rhs.instruction_);
    bitmap_ = rhs.bitmap_;
    rhs.bitmap_ = nullptr;
    drawn_ = rhs.drawn_;
    rhs.drawn_ = false;
}
/**
         * Default Constructor
         * @post: Construct a new Card object 
         */
// Move Assignment Operator
Card& Card::operator=(Card&& rhs){
    if (this == &rhs){
        return *this;
    }
    delete [] bitmap_;
    bitmap_ = rhs.bitmap_;
    rhs.bitmap_ = nullptr;
    cardType_ = rhs.cardType_;
    instruction_ = std::move(rhs.instruction_);
    drawn_ = rhs.drawn_;
    rhs.drawn_ = false;
    return *this;
}

// Default Constructor
Card::Card() {
    instruction_ = "";
    bitmap_ = new int[80];
    drawn_ = false;
    drawn_ = false;
};

// Getter for card type
std::string Card::getType() const {
return  (cardType_ == POINT_CARD) ? "POINT_CARD" : "ACTION_CARD";
};
// Setter for card type
void Card::setType(const CardType& type) {
    cardType_ = type;
};

// Getter for instruction
const std::string& Card::getInstruction() const {
    return instruction_;
};

// Setter for instruction
void Card::setInstruction(const std::string& instruction) {
    instruction_ = instruction;
};

// Getter for image data
const int* Card::getImageData() const {
    return bitmap_;
};

// Setter for image data
void Card::setImageData(int* data) {
    bitmap_ = data;
};

// Getter for drawn status
bool Card::getDrawn() const {
    return drawn_;
};

// Setter for drawn status
void Card::setDrawn(const bool& drawn) {
    drawn_ = drawn;
};