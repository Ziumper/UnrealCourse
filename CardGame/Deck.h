#pragma once
#include "Card.h"
#include <cstdlib> // dla rand() i srand()
#include <ctime>   // dla time()

class Deck
{
public:
	static const int s_MaxDeckSize = (int)Rank::SIZE * (int)Color::SIZE;
	void Initialize();
	void Shuffle();
	Card GetCard();
	Card* Distribute(int amount);
	void AddCard(Card card);
	bool IsEmpty();
	int Size();
	static const char* RankToString(Rank rank);
    static const char* ColorToString(Color color);

private:
	Card m_cards[s_MaxDeckSize];
	int m_size = 0;
};
