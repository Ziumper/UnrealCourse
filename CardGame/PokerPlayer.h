#pragma once

#include "Player.h"
#include "Hand.h"
#include "Card.h"
#include <iostream>

using namespace std;

enum class Action : char {
    Fold,
//    Check,
//    Bet,
//    Raise,
    Call, 
    Change,

    SIZE
};

class PokerPlayer : public Player
{
    public:
        PokerPlayer(): Player() {};
        PokerPlayer(Hand hand,int index): m_hand(hand), Player(index) 
        {
            cout << "poker player constructor" << endl;
        };
        ~PokerPlayer() { cout << "poker player destructor" << endl; }
        void SetHand(Hand hand) { m_hand = hand; }
        Hand GetHand() { return m_hand; }
        void SetActive(bool active) { m_active = active; }
        bool IsActive() const { return m_active; }
        virtual Action ChooseAction(); 
        virtual void Move();
        Hand GetHandToChange();
    protected:
        Action CastActionFromInt(int action); 
        Hand m_hand;
        bool m_active = true;
};

class PokerHumanPlayer : public PokerPlayer 
{
    public:
        PokerHumanPlayer(Hand hand, int index) : PokerPlayer(hand,index) {};
        Action ChooseAction();
        void Move();
};

class PokerComputerPlayer : public PokerPlayer
{
    public:
        PokerComputerPlayer(Hand hand,int index) : PokerPlayer(hand,index) {};
        Action ChooseAction();
};