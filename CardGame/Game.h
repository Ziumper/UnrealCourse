#pragma once

#include <iostream>
#include "Player.h"

using namespace std;

/** 
 * Manage update of the game cycles and game loop
*/
class Game 
{
    public:
        Game(): m_amountOfPlayers(0), m_finished(false), m_players(nullptr) {};
        virtual ~Game() { delete[] m_players; }

        /**
         * Used for initialization and setup of the game resources
        */ 
        virtual void Start(); 
        
        /**
         * Used for updating the current game state, refreshing new 
         * and stale state of the game
        */
        virtual void Update();
        
        /**
         * Return true when game is finished
        */
        virtual bool IsFinish();
        
        /**
         * Ending the game, cleaning up the game state, so the game can be played again
         * if needed
        */
        virtual void End();      
     protected:
        int m_amountOfPlayers;
        bool m_finished;
        Player** m_players;
};
