#pragma once

#include "Game.h"
#include "Deck.h"
#include "Hand.h"
#include "PokerPlayer.h"


// Definicja kombinacji kart
enum class PokerRank : char {
    HighCard,
    Pair,
    TwoPairs,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,

    SIZE
};

/*
 Poker card game implementation, each player can:
 have amount of 5 cards, and is able to 
 - change cards
 - pass
 - check the cards of enemy in turn
*/
class PokerCardGame : public Game 
{
    public:
        static const int s_CardsInHandMax = 5;
        PokerCardGame(Deck deck);
        void Update();
        void Start();
        static const char* PokerRankToString(PokerRank rank);
    protected:
        //Creating one normal human player and the rest would be computer players
        void CreatePlayers();
    private:
        bool CompareCards(const Card& a, const Card& b);
        void SortCards(Card* cards);
        PokerRank EvaluateCards(const Card* cards);
        
        void DeclareWinner(int winner);
        Deck m_deck;
};
