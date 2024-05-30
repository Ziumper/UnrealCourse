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

class PokerCardGame : public Game 
{
    protected:
        void CreateComputerPlayer(int index); 
        void CreateHumanPlayer(int index);
        Hand CreatePlayerHand();
        bool CompareCards(const Card& a, const Card& b);
        void SortCards(Card* cards);
        PokerRank EvaluateCards(const Card* cards);
        void DeclareWinner(int winner);
    public:
        static const int s_AmountOfCardsInPlayerHand = 5;
        PokerCardGame(Deck deck);
        ~PokerCardGame();
        void Update();
    private:
        Deck m_deck;
        PokerPlayer* m_poker_players[s_MaxPlayers];

        
};
