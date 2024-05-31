#pragma once

#include "Card.h"

class Hand {
public:
    Hand(Card* cards, int size);
    Hand(): m_size(0), m_cards(nullptr) {};
    //use it for getting the copy assign 
    Hand(const Hand& other); 
    ~Hand() { delete[] m_cards; m_size = 0; }
    Hand& operator=(const Hand& other);
    int GetSize() { return m_size; }
    Card* GetCards();
    Card GetCard(int index);
    int GetCardIndex(Card card);
    void SwapCard(int index, Card card);
    void ShowCards();
private:
    Card* m_cards;
    int m_size;
};