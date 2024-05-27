#pragma once

#include "Card.h"

class Hand {
public:
    Hand(Card* cards, int size);
    Hand() {};
    //use it for getting the copy assign 
    Hand(const Hand& other); 
    ~Hand() { delete[] m_cards; }
    Hand& operator=(const Hand& other);
    Card* GetCardsInHand();
    int GetSize() { return m_size; }
private:
    Card* m_cards;
    int m_size;
};