
#include <iostream>
#include "Player.hpp"

// Constructor
Player::Player() {
    score_ = 0;
    opponent_ = nullptr;
    actiondeck_ = nullptr;
    pointdeck_ = nullptr;
};

// Destructor
Player::~Player() {
    delete opponent_;    
    delete pointdeck_;
    delete actiondeck_;
    opponent_ = nullptr;
    pointdeck_ = nullptr;
    actiondeck_ = nullptr;
};

// Getter for hand
const Hand& Player::getHand() const {
    return hand_;
};

// Setter for hand
void Player::setHand(const Hand& hand) {
    this->hand_ = hand;
};

// Getter for score
int Player::getScore() const {
    return score_;
};

// Setter for score
void Player::setScore(const int& score) {
    this->score_ = score;
};

/*
void Player::play(ActionCard&& card) {
    //check which card it is and do its respective action
    if(card.getInstruction() == "SWAP HAND WITH OPPONENT") {
        std::cout << "PLAYING ACTION CARD: SWAP HAND WITH OPPONENT" << std::endl;
        if(opponent_ != nullptr) {
            Hand temp = getHand();
            setHand(opponent_->getHand());
            opponent_->setHand(temp);
        }
    }
    else if (card.getInstruction() == "REVERSE HAND") {
        std::cout << "PLAYING ACTION CARD: REVERSE HAND" << std::endl;
        hand_.Reverse();
    }
    else {
        std::vector<std::string> words;
        std::string word = "";
        for (int i = 0; i < card.getInstruction().size(); i++) {
            if(card.getInstruction()[i] == ' ') {
                words.push_back(word);
                word = "";
            }
            else {
                word += (card.getInstruction()[i]);
            }
        }

        if (words[0] == "PLAY") {
            std::cout << "PLAYING ACTION CARD: PLAY" << std::endl;
            int count = std::stoi(words[1]);
            for (int i = 0; i < count; i++) {
                playPointCard();
            }
        }
        else if (words[0] == "DRAW") {
            std::cout << "PLAYING ACTION CARD: DRAW" << std::endl;
            int count = std::stoi(words[1]);
            for (int i = 0; i < count; i++) {
                drawPointCard();
            }
        }
    }

};*/
void Player::play(ActionCard&& card) {
    const std::string instruction = card.getInstruction();
    std::cout << "PLAYING ACTION CARD: " << instruction << std::endl;

    if (instruction == "SWAP HAND WITH OPPONENT") {
        if (opponent_) {
            std::swap(hand_, opponent_->hand_);
        }
    } else if (instruction == "REVERSE HAND") {
        hand_.Reverse();
    } else {
        std::istringstream iss(instruction);
        std::string action, value;
        iss >> action >> value;

        if (action == "PLAY") {
            int count = std::stoi(value);
            for (int i = 0; i < count; i++) {
                playPointCard();
            }
        } else if (action == "DRAW") {
            int count = std::stoi(value);
            for (int i = 0; i < count; i++) {
                drawPointCard();
            }
        }
    }
}


// Draw a point card and place it in the player's hand
void Player::drawPointCard()
{
    if (pointdeck_ != nullptr && !pointdeck_->IsEmpty())
    {
        PointCard &&card = pointdeck_->Draw();
        hand_.addCard(std::move(card));
    }
}


// Play a point card from the player's hand and update the player's score
void Player::playPointCard()
{
    if (!hand_.isEmpty())
    {
        int points = hand_.PlayCard();
        score_ += points;
    }
}

// Set the opponent of the player
void Player::setOpponent(Player *opponent)
{
    opponent_ = opponent;
}

// Get the opponent
Player *Player::getOpponent()
{
    return opponent_;
}

// Set the action deck of the player
void Player::setActionDeck(Deck<ActionCard> *actiondeck)
{
    this->actiondeck_ = actiondeck;
}

// Get the action deck
Deck<ActionCard> *Player::getActionDeck()
{
    return actiondeck_;
}

// Set the point deck of the player
void Player::setPointDeck(Deck<PointCard> *pointdeck)
{
    pointdeck_ = pointdeck;
}

// Get the point deck
Deck<PointCard> *Player::getPointDeck()
{
    return pointdeck_;
}


/*

#include "Player.hpp"
#include <string>
#include <sstream>

// Constructor
Player::Player(): hand_(nullptr), score_(0), opponent_(nullptr), actiondeck_(nullptr), pointdeck_(nullptr) {}

// Destructor
Player::~Player() {
    delete opponent_;
    delete actiondeck_;
    delete pointdeck_;
    opponent_ = nullptr;
    actiondeck_ = nullptr;
    pointdeck_ = nullptr;
}

// Getter for hand
const Hand &Player::getHand() const
{
    return hand_;
}

// Setter for hand
void Player::setHand(const Hand &hand)
{
    this->hand_ = hand;
}

// Getter for score
int Player::getScore() const
{
    return score_;
}

// Setter for score
void Player::setScore(const int &score)
{
    this->score_ = score;
}

void Player::play(ActionCard&& card) {
    //check which card it is and do its respective action
    if(card.getInstruction() == "SWAP HAND WITH OPPONENT") {
        std::cout << "PLAYING ACTION CARD: SWAP HAND WITH OPPONENT" << std::endl;
        if(opponent_ != nullptr) {
            Hand temp = getHand();
            setHand(opponent_->getHand());
            opponent_->setHand(temp);
        }
    }
    else if (card.getInstruction() == "REVERSE HAND") {
        std::cout << "PLAYING ACTION CARD: REVERSE HAND" << std::endl;
        hand_.Reverse();
    }
    else {
        std::vector<std::string> words;
        std::string word = "";
        for (int i = 0; i < card.getInstruction().size(); i++) {
            if(card.getInstruction()[i] == ' ') {
                words.push_back(word);
                word = "";
            }
            else {
                word += (card.getInstruction()[i]);
            }
        }

        if (words[0] == "PLAY") {
            std::cout << "PLAYING ACTION CARD: PLAY" << std::endl;
            int count = std::stoi(words[1]);
            for (int i = 0; i < count; i++) {
                playPointCard();
            }
        }
        else if (words[0] == "DRAW") {
            std::cout << "PLAYING ACTION CARD: DRAW" << std::endl;
            int count = std::stoi(words[1]);
            for (int i = 0; i < count; i++) {
                drawPointCard();
            }
        }
    }

};
*/
// Play an action card
/*void Player::play(ActionCard &&card)
{
    ///If its not working try using the isPlayable() function from ActionCard to see if its vaild
    std::string instr = card.getInstruction();             // get the instruction corresponding to the string
    std::cout << "PLAYING ACTION CARD: " << instr << "\n"; // prints
    std::string read_input = "";
    std::stringstream user_input(instr); // create a string stream object to read in the string - now stores the string
    bool flag = true;

    while (flag && user_input >> read_input)
    {
        if (read_input == "DRAW")
        {
            int amount = 0;
            std::string a = ""
            user_input >> a; // get the amount, if it doesnt work read it in as a string and use stoi()
            amount = std::stoi(a);
            flag = false;
            // Now do the drawing implemenation /// when your done set the flag = to false
            for(int i = 0; i < amount; i++){
                this->drawPointCard();
            }
        }
        else if (read_input == "PLAY")
        {
            int amount = 0;
            user_input >> a; // get the amount, if it doesnt work read it in as a string and use stoi()
            amount = std::stoi(a);            
            flag = false;
            //So do we play x amount of classes 
            for(int i = 0; i < amount; i++){
                if (hand_.isEmpty()) {
                    drawPointCard();
                }
                this->playPointCard();
            }
        }
        else if (read_input == "REVERSE")
        {
            flag = false;
            this->hand_.Reverse();//revereses the order of our cards
            //if this is wrong its with the operator overload 
            //Big headace so just reverse manually in here:)
            // reverse whatever that means
        }
        else if (read_input == "SWAP")//swap current hand with opponents hand
        {
            flag = false;
            std::swap(this->hand_, this->opponent_->hand_);//just swap
            // swap whatever means
        }
        else
        {
            flag = false;
        }
    }

    // Implement the logic for playing the action card
}*/

// Draw a point card and place it in the player's hand
/*void Player::drawPointCard()
{
    if (pointdeck_ != nullptr && !pointdeck_->IsEmpty())
    {
        PointCard &&card = pointdeck_->Draw();
        hand_.addCard(std::move(card));
    }
}

// Play a point card from the player's hand and update the player's score
void Player::playPointCard()
{
    if (!hand_.isEmpty())
    {
        int points = hand_.PlayCard();
        score_ += points;
    }
}

// Set the opponent of the player
void Player::setOpponent(Player *opponent)
{
    opponent_ = opponent;
}

// Get the opponent
Player *Player::getOpponent()
{
    return opponent_;
}

// Set the action deck of the player
void Player::setActionDeck(Deck<ActionCard> *actiondeck)
{
    this->actiondeck_ = actiondeck;
}

// Get the action deck
Deck<ActionCard> *Player::getActionDeck()
{
    return actiondeck_;
}

// Set the point deck of the player
void Player::setPointDeck(Deck<PointCard> *pointdeck)
{
    pointdeck_ = pointdeck;
}

// Get the point deck
Deck<PointCard> *Player::getPointDeck()
{
    return pointdeck_;
}
*/