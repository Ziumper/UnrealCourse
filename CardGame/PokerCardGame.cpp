#include "PokerCardGame.h"
#include "PokerPlayer.h"
#include "Card.h"
#include <iostream>

using namespace std;

PokerCardGame::~PokerCardGame()
{
    for(int i = 0; i < m_playersAmount; ++i) 
    {
        delete m_poker_players[i];
    }
}

PokerCardGame::PokerCardGame(Deck deck): m_deck(deck)
{
    m_deck.Shuffle();
}

void PokerCardGame::CreateComputerPlayer(int index)
{
    Game::CreateComputerPlayer(index);
    Hand hand = CreatePlayerHand();
    m_poker_players[index] = new PokerComputerPlayer(hand,index);
}

void PokerCardGame::CreateHumanPlayer(int index)
{
    Game::CreateHumanPlayer(index);
    m_poker_players[index] = new PokerHumanPlayer (CreatePlayerHand(),index);;
}

void PokerCardGame::Update() 
{
    Game::Update(); 

    //start a new round of game turn
    int foldCounter = 0;

    for(int i = 0; i < m_playersAmount; ++i) 
    {
        //not active players are not taking action in current game
        if (!m_poker_players[i]->GetActive()) 
        {
            continue;
        }; 

        m_poker_players[i]->Move();
        Action action =  m_poker_players[i]->ChooseAction();

        if (action == Action::Call) 
        {
            //player would like to check cards let's do it!
            /*
                1. Get all cards from users 
                2. Get all figures from cards
                3. Check the highest figure  
                4. Declare the winner
                5. Break the loop and finish the game
            */

           m_finished = true;
           return;
        } 

        if(action == Action::Change) 
        {
            //Changing call for cards
            //continue the loop
            //1. Choose the amount of cards to change
            //2. get cards add to deck to be the last ones 
            //3. Get cards from the thop 
            //4. Distribute them into the hand of the player 
            // Procced with the lop
        }

        if(action == Action::Fold) 
        {
            //set player not active since he is not inside
            m_poker_players[i]->SetActive(false);
            ++foldCounter;

            if (foldCounter == m_playersAmount-1) 
            {
                //finish the game
                //declare the winner
                m_finished = false;
                //get the last man standing and declare the winner
            }
        }
    }

    //if it's not finished the game 
    //reactivate not active players from the current round
}

Hand PokerCardGame::CreatePlayerHand() 
{
    cout << "Creating hand deck distribution" << endl;
    Card* distributed = m_deck.Distribute(s_AmountOfCardsInPlayerHand);
    Hand hand(distributed,s_AmountOfCardsInPlayerHand);
    delete distributed;
    cout << "Cards created" << endl;
    return hand;
}


