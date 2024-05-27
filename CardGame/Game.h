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
        static const int s_MaxPlayers = 4;

        Game() {};

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
        int m_playersAmount = 0;
        int m_humanPlayers = 0;
        int m_computerPlayers = 0;
        bool m_finished = false;
        Player m_players[s_MaxPlayers];
        
        void CreatePlayers();
        virtual void CreateHumanPlayer(int index);
        virtual void CreateComputerPlayer(int index);
};
