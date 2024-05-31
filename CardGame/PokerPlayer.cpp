#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include "PokerPlayer.h"
#include "Deck.h"

using namespace std;

void PokerPlayer::Move()
{
    Player::Move();

    cout << "Player with index: " << m_index  << " is moving " << endl;
}

void PokerPlayer::ChangeCards(Card* cardsToChange, Card* newCards, int size)
{
    for (int c = 0; c < size; ++c)
    {
        int index = m_hand.GetCardIndex(cardsToChange[c]);
        if (index > -1)
        {
            //swap the card
            m_hand.SwapCard(index, newCards[c]);
        }
    }
}

Card* PokerPlayer::GetCardsToChange(int amount)
{
    return nullptr;
}

int PokerPlayer::GetHowManyToChange()
{
    return 0;
}

int PokerPlayer::GetIndex()
{
    return m_index;
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
    std::srand((unsigned int)std::time(0)); //take current time

    // Generate random value
    int randomValue = std::rand() % 3 + 1;
    return CastActionFromInt(randomValue);
}

int PokerComputerPlayer::GetHowManyToChange()
{
    std::srand((unsigned int)std::time(0)); //take current time
    int randomValue = std::rand() % 5 + 1;
    return randomValue;
}

Card* PokerComputerPlayer::GetCardsToChange(int amount)
{
    
    return nullptr;
}

int PokerHumanPlayer::GetHowManyToChange()
{
    int amount = 0;
    cout << "How many cards would like to change " << endl;
    cin >> amount;
    return amount;
}

Card* PokerHumanPlayer::GetCardsToChange(int amount)
{
    m_hand.ShowCards();
    cout << " Choose cards to change " << endl;

    Card* cards = new Card[amount];

    for (int i = 0; i < amount; ++i) {

        int index = -1;
        cout << "Provide number of card to change: " << endl;
        cin >> index;
        Card card = m_hand.GetCard(index);
        const char* colorChars = Deck::ColorToString(card.color);
        const char* rankChars = Deck::RankToString(card.rank);
        cout << "You have choosen: " << "Color:" << colorChars << " Rank:" << rankChars << endl;
        cards[i] = card;
    }

    return cards;
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
    cout << "Your index is: " << m_index << endl;
    m_hand.ShowCards();
    cout << endl;
}