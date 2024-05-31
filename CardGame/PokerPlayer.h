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
    PokerPlayer() : Player(), m_active(true), m_index(-1) {};
    PokerPlayer(Hand hand, int index) : m_hand(hand), m_active(true), m_index(index) {};
    ~PokerPlayer() {}
    void SetActive(bool active) { m_active = active; }
    bool IsActive() const { return m_active; }
    virtual Action ChooseAction(); 
    virtual void Move();
    virtual void ChangeCards(Card* cardsToChange, Card* newCards, int size);
    virtual int GetHowManyToChange();
    virtual int GetIndex();
    virtual Card* GetCardsToChange(int amount);
    Hand GetHand() { return m_hand; }
protected:
    Action CastActionFromInt(int action); 
    Hand m_hand;
    bool m_active;
    int m_index;
};

class PokerHumanPlayer : public PokerPlayer 
{
    public:
        PokerHumanPlayer(Hand hand,int index) : PokerPlayer(hand,index) {};
        Action ChooseAction();
        int GetHowManyToChange();
        virtual Card* GetCardsToChange(int amount);
        void Move();
};

class PokerComputerPlayer : public PokerPlayer
{
    public:
        PokerComputerPlayer(Hand hand,int index) : PokerPlayer(hand,index) {};
        Action ChooseAction();
        int GetHowManyToChange();
        virtual Card* GetCardsToChange(int amount);
};