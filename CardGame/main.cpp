#include <iostream>

#include "Deck.h"
#include "PokerCardGame.h"

using namespace std;

// Makao, Pan, Remik, Poker



// classes:
// Game
// Card
// Deck
// Hand
// Player

// enums:
// color
// rank


int main()
{
    Deck deck;
    deck.Initialize();

    Game* game = new PokerCardGame(deck);   
    
    game->Start();
    while(!game->IsFinish()) 
    { 
        game->Update();
    }
    game->End();

    delete game;
    return 0;
}