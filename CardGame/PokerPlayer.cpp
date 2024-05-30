#include <iostream>
#include <cstdlib> // dla rand() i srand()
#include <ctime>   // dla time()
#include "PokerPlayer.h"
#include "Deck.h"

using namespace std;

void PokerPlayer::Move() 
{
    Player::Move();
    cout << "Turn player with index " << m_index << endl;
}

Hand PokerPlayer::GetHandToChange()
{
    return Hand();
}

Action PokerPlayer::ChooseAction() 
{
    return Action::Call;
}

Action PokerPlayer::CastActionFromInt(int action) {
    switch (action)
    {
    case 1:
        return Action::Change;
    case 2:
        return Action::Call;
    case 3: 
        return Action::Fold;
    default:
        break;
    }

    return Action::Fold;
}

Action PokerComputerPlayer::ChooseAction() 
{
    std::srand(std::time(0)); //take current time

    // Generate random value
    int randomValue = std::rand() % 3 + 1;
    return CastActionFromInt(randomValue);
}

Action PokerHumanPlayer::ChooseAction()
{
    cout << "What do you like to do?" << endl;
    cout << "1. Change your cards" << endl;
    cout << "2. Check enemy cards!" << endl;
    cout << "3. Pass" << endl;
    int action = 0;
    cin >> action;
    return CastActionFromInt(action);
}

void PokerHumanPlayer::Move() 
{
    PokerPlayer::Move();
    cout << "Here is your cards" << endl;
    Card* cards = m_hand.GetCards();
    for(int i = 0; i < m_hand.GetSize(); ++i) 
    {
        Card card = cards[i];
        const char* colorChars = Deck::ColorToString(card.color);
        const char* rankChars = Deck::RankToString(card.rank);
        cout << "Color: " << colorChars << " Rank:" << rankChars << endl;
        delete colorChars;
        delete rankChars;
    }

    cout << endl;
}