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
    for (int i = 0; i < s_MaxPlayers; ++i)
    {
        m_poker_players[i] = new PokerPlayer();
    }

    m_deck.Shuffle();
}

void PokerCardGame::CreateComputerPlayer(int index)
{
    Game::CreateComputerPlayer(index);
    Hand hand = CreatePlayerHand();
    delete m_poker_players[index];
    m_poker_players[index] = new PokerComputerPlayer(hand,index);
}

void PokerCardGame::CreateHumanPlayer(int index)
{
    Game::CreateHumanPlayer(index);
    delete m_poker_players[index];
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
        if (!m_poker_players[i]->IsActive()) 
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

            int maxRank = (int)PokerRank::HighCard;
            int winner = i; //assume it's the first one

            int size = m_poker_players[i]->GetHand().GetSize();

            for (int j = 0; j < m_playersAmount; ++j) {
                if (m_poker_players[j]->IsActive())
                {
                    Hand hand = m_poker_players[j]->GetHand();
                    Card* cards = hand.GetCards();
                    int rank = (int) EvaluateCards(cards);
                    if (rank > maxRank)
                    {
                        winner = j;
                    }

                    delete[] cards;
                }
            }

            //declare the winner
            DeclareWinner(winner);
            return;
        } 

        if(action == Action::Change) 
        {
            //Changing call for cards
            //continue the loop
            //1. Choose the amount of cards to change
            //2. get cards add to deck to be the last ones 
            //3. Get cards from the top 
            //4. Distribute them into the hand of the player 
            // Procced with the lop
            Hand cardsToChange = m_poker_players[i]->GetHandToChange();

            Card* cards = cardsToChange.GetCards();
            for (int c = 0; c < s_AmountOfCardsInPlayerHand; ++c)
            {
                m_deck.AddCard(cards[i]); //adding the cards from player hand to the bottom of the deck
            }

            

            
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

    m_finished = true; //TODO delete that litle one
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

bool PokerCardGame::CompareCards(const Card& a, const Card& b)
{
    return static_cast<int>(a.rank) < static_cast<int>(b.rank);
}

void PokerCardGame::SortCards(Card* cards)
{
    for (int i = 0; i < s_AmountOfCardsInPlayerHand-1; ++i) {
        for (int j = 0; j < s_AmountOfCardsInPlayerHand - i - 1; ++j) {
            if (static_cast<int>(cards[j].rank) > static_cast<int>(cards[j + 1].rank)) {
                Card temp = cards[j];
                cards[j] = cards[j + 1];
                cards[j + 1] = temp;
            }
        }
    }
}

PokerRank PokerCardGame::EvaluateCards(const Card* cards)
{
    // Sortowanie kart wzglêdem wartoœci rangi
    Card sortedHand[5];
    for (int i = 0; i < s_AmountOfCardsInPlayerHand; ++i) {
        sortedHand[i] = cards[i];
    }
    SortCards(sortedHand);

    // Sprawdzenie czy karty tworz¹ kolor
    bool isFlush = true;
    Color firstColor = sortedHand[0].color;
    for (int i = 1; i < s_AmountOfCardsInPlayerHand; ++i) {
        if (sortedHand[i].color != firstColor) {
            isFlush = false;
            break;
        }
    }

    // Sprawdzenie czy karty tworz¹ strit
    bool isStraight = true;
    for (int i = 1; i < s_AmountOfCardsInPlayerHand; ++i) {
        if (static_cast<int>(sortedHand[i].rank) != static_cast<int>(sortedHand[i - 1].rank) + 1) {
            isStraight = false;
            break;
        }
    }

    // Inicjalizacja licznika rang kart
    int rankCount[static_cast<int>(Rank::SIZE)] = { 0 };
    for (int i = 0; i < s_AmountOfCardsInPlayerHand; ++i) {
        rankCount[static_cast<int>(sortedHand[i].rank)]++;
    }

    // Sprawdzenie kombinacji kart
    bool hasPair = false;
    bool hasTwoPairs = false;
    bool hasThreeOfAKind = false;
    bool hasFourOfAKind = false;
    bool hasFullHouse = false;

    int pairCount = 0;
    for (int i = 0; i < static_cast<int>(Rank::SIZE); ++i) {
        if (rankCount[i] == 2) {
            pairCount++;
        }
        else if (rankCount[i] == 3) {
            hasThreeOfAKind = true;
        }
        else if (rankCount[i] == 4) {
            hasFourOfAKind = true;
        }
    }

    if (pairCount == 1) {
        hasPair = true;
    }
    else if (pairCount == 2) {
        hasTwoPairs = true;
    }

    if (hasPair && hasThreeOfAKind) {
        hasFullHouse = true;
    }

    // Okreœlenie kombinacji kart na podstawie uzyskanych wyników
    if (isStraight && isFlush) {
        return PokerRank::StraightFlush;
    }
    else if (hasFourOfAKind) {
        return PokerRank::FourOfAKind;
    }
    else if (hasFullHouse) {
        return PokerRank::FullHouse;
    }
    else if (isFlush) {
        return PokerRank::Flush;
    }
    else if (isStraight) {
        return PokerRank::Straight;
    }
    else if (hasThreeOfAKind) {
        return PokerRank::ThreeOfAKind;
    }
    else if (hasTwoPairs) {
        return PokerRank::TwoPairs;
    }
    else if (hasPair) {
        return PokerRank::Pair;
    }
    else {
        return PokerRank::HighCard;
    }
}

void PokerCardGame::DeclareWinner(int winner)
{
    cout << "This turn has been won by player with index:" << winner << endl;
    m_finished = true;
}


