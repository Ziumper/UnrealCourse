#pragma once

#include "Game.h"
#include "Deck.h"
#include "Hand.h"
#include "PokerPlayer.h"

class PokerCardGame : public Game 
{
    protected:
        void CreateComputerPlayer(int index); 
        void CreateHumanPlayer(int index);
        Hand CreatePlayerHand();
    public:
        static const int s_AmountOfCardsInPlayerHand = 5;
        PokerCardGame(Deck deck);
        ~PokerCardGame();
        void Update();
    private:
        Deck m_deck;
        PokerPlayer* m_poker_players[s_MaxPlayers];
        
};
