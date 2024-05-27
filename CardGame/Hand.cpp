#include "Hand.h"
#include <iostream>

using namespace std;

Hand::Hand(Card* cards, int size): m_size(size)
{
    //kopia kart
    m_cards = new Card[m_size];
    for (int i = 0; i < m_size; ++i) 
    {
        m_cards[i] = cards[i]; //przypisanie struktury tworzy nowy egzemplarz (głęboka kopia)
    }
}

 Hand::Hand(const Hand& other) 
 {
    m_size = other.m_size;
    m_cards = new Card[m_size];
    for (int i = 0; i < m_size; ++i) 
    {
        m_cards[i] = other.m_cards[i];
    }
 }

 Hand& Hand::operator=(const Hand& other) 
 {
     if (this == &other) {
            return *this;
        }

        // Zwolnienie istniejącej pamięci, aby uniknąć wycieku pamięci
        delete[] m_cards;

        //alokacja i przypisanie nowej pamięci
        m_size = other.m_size;
        m_cards = new Card[m_size];
        for (int i = 0; i < m_size; ++i) {
            m_cards[i] = other.m_cards[i];
        }

        return *this;
}

Card* Hand::GetCardsInHand() 
{
    Card* cards = new Card[m_size];
    for(int i = 0; i < m_size; ++i)
    {
        cards[i] = m_cards[i];
    }

    return cards;
}