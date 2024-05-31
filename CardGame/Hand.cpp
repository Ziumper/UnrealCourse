#include "Hand.h"
#include "Deck.h"
#include <iostream>

using namespace std;

Hand::Hand(Card* cards, int size): m_size(size)
{
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

 Card* Hand::GetCards()
 {
     Card* cards  = new Card[m_size];
    
     for (int i = 0; i < m_size; ++i) 
     {
         cards[i] = m_cards[i];
     }

     return cards;
 }

 Card Hand::GetCard(int index)
 {
     if (index > -1 && index < m_size) 
     {
         return m_cards[index];
     }

     return Card();
 }

 int Hand::GetCardIndex(Card card)
 {
     for (int i = 0; i < m_size; ++i)
     {
         if (m_cards[i].color == card.color && m_cards[i].rank == card.rank) 
         {
             return i;
         }
     }

     return -1;
 }

 void Hand::SwapCard(int index, Card card)
 {
     if (index > -1 && index < m_size)
     {
         m_cards[index] = card;
     }
 }

 void Hand::ShowCards()
{
    for(int i = 0; i < m_size; ++i)
    {
        const char* colorChars = Deck::ColorToString(m_cards[i].color);
        const char* rankChars = Deck::RankToString(m_cards[i].rank);
        cout << i+1 <<".Color: " << colorChars << " Rank:" << rankChars << endl;
    }
}

