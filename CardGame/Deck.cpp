#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include "Deck.h"

using namespace std;

void Deck::Initialize()
{
	m_size = 0;
	for (int i = 0; i < (int)Rank::SIZE; ++i)
	{
		for (int j = 0; j < (int)Color::SIZE; ++j)
		{
			Card card;
			card.color = (Color)j;	
			card.rank = (Rank)i;
			m_cards[m_size] = card;
			m_size++;
		}
	}
}

Card* Deck::Distribute(int amount) 
{
	Card* cards = new Card[amount];
	for(int i = 0; i < amount; ++i) 
	{
		cards[i] = GetCard();
	}

	return cards;
}

void Deck::Shuffle()
{
	srand(time(NULL)); // get current time
	for (int i = 0; i < m_size; ++i)
	{
		int otherIndex = rand() % m_size;
		cout << "Index of shuffle:" << otherIndex << endl;
		std::swap(m_cards[i], m_cards[otherIndex]);
	}
}

Card Deck::GetCard()
{
	if (m_size > 0)
	{
		Card card = m_cards[m_size - 1];

		m_size--;
		return card;
	}

	return Card();
}

void Deck::AddCard(Card card)
{

}

bool Deck::IsEmpty()
{
	return m_size == 0; 
}

int Deck::Size()
{
	return m_size;
}


const char* Deck::ColorToString(Color color)
{
    switch(color)
    {
        case Color::Pik: return "Pik";
        case Color::Trefl: return "Trefl";
        case Color::Karo: return "Karo";
        case Color::Kier: return "Kier";
        default: return "";
    }
}

const char* Deck::RankToString(Rank rank)
{
    switch(rank)
    {
        case Rank::_2: return "2";
        case Rank::_3: return "3";
        case Rank::_4: return "4";
        case Rank::_5: return "5";
        case Rank::_6: return "6";
        case Rank::_7: return "7";
        case Rank::_8: return "8";
        case Rank::_9: return "9";
        case Rank::_10: return "10";
        case Rank::_J: return "J";
        case Rank::_D: return "D";
        case Rank::_K: return "K";
        case Rank::_AS: return "AS";
        default: return "";
    }
}
