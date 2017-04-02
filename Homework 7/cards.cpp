/*****************************************************************
 Anmol Jain
 March 8, 2016.
 Implementation of Card, Hand and Player classes.
 *****************************************************************/
#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>

/**************************************************
 Card class
 **************************************************/

//Default constructor for the Card class.
Card::Card() {
    int r = 1 + rand() % 4;
    switch (r) {
        case 1: suit = OROS;
            break;
        case 2: suit = COPAS; break;
        case 3: suit = ESPADAS; break;
        case 4: suit = BASTOS; break;
        default: break;
    }
    
    r = 1 + rand() % 10;
    switch (r) {
        case  1: rank = AS;
            break;
        case  2: rank = DOS;
            break;
        case  3: rank = TRES;
            break;
        case  4: rank = CUATRO;
            break;
        case  5: rank = CINCO;
            break;
        case  6: rank = SEIS;
            break;
        case  7: rank = SIETE;
            break;
        case  8: rank = SOTA;
            break;
        case  9: rank = CABALLO;
            break;
        case 10: rank = REY;
            break;
        default: break;
    }
}

//Accessor: returns a string with the suit of the card in Spanish
string Card::get_spanish_suit() const {
    string suitName;
    switch (suit) {
        case OROS:
            suitName = "oros";
            break;
        case COPAS:
            suitName = "copas";
            break;
        case ESPADAS:
            suitName = "espadas";
            break;
        case BASTOS:
            suitName = "bastos";
            break;
        default: break;
    }
    return suitName;
}

//Accessor: returns a string with the rank of the card in Spanish
string Card::get_spanish_rank() const {
    string rankName;
    switch (rank) {
        case AS:
            rankName = "As";
            break;
        case DOS:
            rankName = "Dos";
            break;
        case TRES:
            rankName = "Tres";
            break;
        case CUATRO:
            rankName = "Cuatro";
            break;
        case CINCO:
            rankName = "Cinco";
            break;
        case SEIS:
            rankName = "Seis";
            break;
        case SIETE:
            rankName = "Siete";
            break;
        case SOTA:
            rankName = "Sota";
            break;
        case CABALLO:
            rankName = "Caballo";
            break;
        case REY:
            rankName = "Rey";
            break;
        default: break;
    }
    return rankName;
}

//Accessor: returns a string with the suit of the card in English
string Card::get_english_suit() const {
    string englishSuitName;
    switch (suit) {
        case OROS:
            englishSuitName = "coins";
            break;
        case COPAS:
            englishSuitName = "cups";
            break;
        case ESPADAS:
            englishSuitName = "swords";
            break;
        case BASTOS:
            englishSuitName = "clubs";
            break;
        default: break;
    }
    return englishSuitName;
}

//Accessor: returns a string with the rank of the card in English
string Card::get_english_rank() const {
    string englishRankName;
    switch (rank) {
        case AS:
            englishRankName = "Ace";
            break;
        case DOS:
            englishRankName = "Two";
            break;
        case TRES:
            englishRankName = "Three";
            break;
        case CUATRO:
            englishRankName = "Four";
            break;
        case CINCO:
            englishRankName = "Five";
            break;
        case SEIS:
            englishRankName = "Six";
            break;
        case SIETE:
            englishRankName = "Seven";
            break;
        case SOTA:
            englishRankName = "Jack";
            break;
        case CABALLO:
            englishRankName = "Knight";
            break;
        case REY:
            englishRankName = "King";
            break;
        default: break;
    }
    return englishRankName;
}

//Accessor: Assigns a numerical value to card based on rank.
//AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
    return static_cast<int>(rank) + 1 ;
}

//Accessor: Assigns value based on the rank of the card
//AS=1, DOS=2, TRES=3, CUATRO=4, CINCO=5, SEIS=6, SIETE=7, SOTA=0.5, CABALLO=0.5, REY=0.5
double Card::get_value() const {
    double value = static_cast<double>(get_rank());
    if (value > 0 && value < 8)
        return value;
    else
        return 0.5;//equivalent value for numerical ranks 10, 11 and 12
}

//Accessor: Comparison operator for cards
//Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
    return rank < card2.rank;
}


/**************************************************
 Hand class
 **************************************************/

//Default constructor initializes a random card to the hand of cards
Hand::Hand() {
    Card newCard;
    cards.push_back(newCard);
}

//Accessor: Prints the last card stored in the hand of cards
void Hand::printLast() const {
    int i = cards.size() - 1;
    cout << "\t" << setw(20) << left << cards[i].get_spanish_rank()+" de "+cards[i].get_spanish_suit()
    << setw(20) << left << "("+cards[i].get_english_rank()+" of "+cards[i].get_english_suit()+")."
    << endl;
}

//Accessor: Finds the total value of all the cards in a hand
double Hand::sum() const {
    double sum = 0.0;
    
    for (int i = 0; i < cards.size(); i++) {
        sum += cards[i].get_value();
    }
    return sum;
}

//Accessor: Compares the values of two Hand objects and returns true if second hand has a higher total value
bool Hand::operator < (Hand hand2) const {
    double sum1 = sum();
    double sum2 = hand2.sum();
    return sum1 < sum2;
}

//Mutator: Adds a randomly generated card to the hand
void Hand::drawCard() {
    Card newCard;
    cards.push_back(newCard);
}

//Mutator: Resets the hand for a new game
void Hand::resetHand() {
    cards.resize(0);
}

//Mutator: Sorts the cards in the vector in ascending order based on rank
void Hand::sortHand() {
    sort(cards.begin(),cards.end());
}

//Prints all the cards in the hand (stored in the vector of cards)
void Hand::print() {
    sortHand();//The cards are sorted first
    for (int i = 0; i < cards.size(); i++) {
        cout << "\t" << setw(20) << left << cards[i].get_spanish_rank()+" de "+cards[i].get_spanish_suit()
        << setw(20) << left << "("+cards[i].get_english_rank()+" of "+cards[i].get_english_suit()+")."
        << endl;
    }
}

//Writes all the cards in the hand in the log file
void Hand::printLog(ofstream& fout) {
    sortHand();//The cards are sorted first
    
    for (int i = 0; i < cards.size(); i++) {
        fout << "\t" << setw(20) << left << cards[i].get_spanish_rank()+" de "+cards[i].get_spanish_suit()
        << setw(20) << left << "("+cards[i].get_english_rank()+" of "+cards[i].get_english_suit()+")."
        << endl;
    }
}

/**************************************************
 Player class
 **************************************************/

//Default constructor intializes m amount of money
Player::Player(int m) {
    money = m;
}

//Accessor: Returns the amount of money
int Player::getMoney() const {
    return money;
}

//Accessor: Updates money player has based on bets won or lost
void Player::updateMoney(int change) {
    money += change;
}