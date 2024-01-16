#include <iostream>
#include "PointCard.hpp"
/**
         * @post: Construct a new Point Card object
         */
//Constructor
PointCard::PointCard() {
    setType(POINT_CARD);
};
/**
         * @return true if the card is playable, false otherwise
         * For a card to be playable, it has to be drawn and the instruction has to be a valid number
        */
// Implementation of the isPlayable method for PointCard
bool PointCard::isPlayable()
{
    // A point card is playable if it is drawn and the instruction is a valid number.
        const std::string& instruction = getInstruction();

        // Check if the instruction is a valid positive integer
        try
        {
            int points = std::stoi(instruction);
            return true;
        }
        catch (const std::invalid_argument& e)
        {
            // Invalid conversion to integer
            return false;
        }

    return false;
};

// Implementation of the Print method for PointCard
/**
         * @post: Print the Point Card in the following format:
         * Type: [CardType]
         * Points: [Instruction]
         * Card: 
         * [ImageData]
         * 
         * Note: For [ImageData]: If there is no image data, print "No image data" instead
         */
void PointCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl;
    const int* imageData = getImageData();
    std::cout << "Card: " << std::endl;

    if (imageData != nullptr) {
        for (int i = 0; i<80; i++) {
            std::cout << imageData[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No image data" << std::endl;
    }
};