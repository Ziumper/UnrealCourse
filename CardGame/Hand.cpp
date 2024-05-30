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
    delete[] m_cards;
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

Card* Hand::GetCards() 
{
    //creating copy of cards inside hand
    Card* cards = new Card[m_size];
    for(int i = 0; i < m_size; ++i)
    {
        cards[i] = m_cards[i];
    }

    return cards;
}

void Hand::RemoveCardsFromHand(const Hand& toRemove)
{
    int newSize = m_size - toRemove.m_size;


    Card* newCards = new Card[newSize];
    
    for (int j = 0; j < toRemove.m_size; ++j)
    {
        for (int i = 0; i < m_size; ++i)
        {
            bool isDifferent = toRemove.m_cards[j].color != m_cards[i].color
                && toRemove.m_cards[j].rank != m_cards[i].rank;
            if (isDifferent)
            {
                Card card;
                card.color = m_cards[i].color;
                card.rank = m_cards[i].rank;
                newCards[]
            }
        }
   
    }
    
}
