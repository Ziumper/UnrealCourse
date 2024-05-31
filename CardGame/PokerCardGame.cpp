#include "PokerCardGame.h"
#include "PokerPlayer.h"
#include "Card.h"
#include <iostream>

using namespace std;

PokerCardGame::PokerCardGame(Deck deck): m_deck(deck)
{
    m_deck.Shuffle();
}

void PokerCardGame::Update() 
{
    Game::Update(); 

    //start a new round of game turn
    int foldCounter = 0;

    for(int i = 0; i < m_amountOfPlayers; ++i) 
    {
        if (IsFinish()) break; //if game has been finished don't continue iteration

        PokerPlayer* player = dynamic_cast<PokerPlayer*>(m_players[i]);
        //not active players are not taking action in current game
        if (!player->IsActive()) 
        {
            continue;
        }; 

        player->Move();
        Action action =  player->ChooseAction();

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
            int winner = i; //assume it's the first one that is checking

            for (int j = 0; j < m_amountOfPlayers; ++j) {

                PokerPlayer* secondPlayer = dynamic_cast<PokerPlayer*>(m_players[j]);

                if (secondPlayer->IsActive())
                {
                    Hand hand = secondPlayer->GetHand();
                    Card* cards = hand.GetCards();
                    PokerRank rank = EvaluateCards(cards);
                    cout << "Player with index " << secondPlayer->GetIndex() << " have poker rank: " << PokerRankToString(rank) << endl;
                    hand.ShowCards();
                    if ((int)rank > maxRank)
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
            int amount = player->GetHowManyToChange();
            Card* cardsToChange = player->GetCardsToChange(amount);

            Card* newCards = new Card[amount];
            for (int c = 0; c < amount; ++c)
            {
                newCards[c] = m_deck.GetCard();
            }
            
            player->ChangeCards(cardsToChange, newCards, amount);
            delete[] cardsToChange;
            delete[] newCards;
            continue;
        }

        if(action == Action::Fold) 
        {
            //set player not active since he is not inside
            player->SetActive(false);
            ++foldCounter;

            if (foldCounter == m_amountOfPlayers-1) 
            {
                //finish the game
                //declare the winner
                m_finished = true;
                //get the last man standing and declare the winner
                DeclareWinner(foldCounter);
            }
        }
    }
}

void PokerCardGame::Start()
{
    CreatePlayers();
}

const char* PokerCardGame::PokerRankToString(PokerRank rank)
{
    switch (rank)
    {
    case PokerRank::HighCard:
        return "HighCard";
        break;
    case PokerRank::Pair:
        return "Pair";
        break;
    case PokerRank::TwoPairs:
        return "TwoPairs";
        break;
    case PokerRank::ThreeOfAKind:
        return "ThreeOfAKind";
        break;
    case PokerRank::Straight:
        return "Straight";
        break;
    case PokerRank::Flush:
        return "Flush";
        break;
    case PokerRank::FullHouse:
        return "FullHouse";
        break;
    case PokerRank::FourOfAKind:
        return "FourOfAKind";
        break;
    case PokerRank::StraightFlush:
        return "StraightFlush";
        break;
    case PokerRank::SIZE:
        break;
    default:
        break;
    }

    return "RankNotFound";
}

bool PokerCardGame::CompareCards(const Card& a, const Card& b)
{
    return static_cast<int>(a.rank) < static_cast<int>(b.rank);
}

void PokerCardGame::SortCards(Card* cards)
{
    for (int i = 0; i < s_CardsInHandMax-1; ++i) {
        for (int j = 0; j < s_CardsInHandMax - i - 1; ++j) {
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
    for (int i = 0; i < s_CardsInHandMax; ++i) {
        sortedHand[i] = cards[i];
    }
    SortCards(sortedHand);

    // Sprawdzenie czy karty tworz¹ kolor
    bool isFlush = true;
    Color firstColor = sortedHand[0].color;
    for (int i = 1; i < s_CardsInHandMax; ++i) {
        if (sortedHand[i].color != firstColor) {
            isFlush = false;
            break;
        }
    }

    // Sprawdzenie czy karty tworz¹ strit
    bool isStraight = true;
    for (int i = 1; i < s_CardsInHandMax; ++i) {
        if (static_cast<int>(sortedHand[i].rank) != static_cast<int>(sortedHand[i - 1].rank) + 1) {
            isStraight = false;
            break;
        }
    }

    // Inicjalizacja licznika rang kart
    int rankCount[static_cast<int>(Rank::SIZE)] = { 0 };
    for (int i = 0; i < s_CardsInHandMax; ++i) {
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

void PokerCardGame::CreatePlayers()
{
    cout << "Please proivde number of players:" << endl;
    cin >> m_amountOfPlayers;

    //validate 
    if (m_amountOfPlayers < 2)
    {
        cout << "There should be at least two players" << endl;
        cout << "Ending the game" << endl;
        m_finished = true;
        return;
    }

    if (m_amountOfPlayers > 4)
    {
        cout << "Too many players to play this game. Only " << 4 << "allowed! " << endl
            << "Players amount: " << m_amountOfPlayers << endl;

        cout << "Ending the game" << endl;
        m_finished = true;
        return;
    }

    //initalize and allocate memory for array
    m_players = new Player* [m_amountOfPlayers];
    
    //distribute the cards for player
    Hand hand(m_deck.Distribute(s_CardsInHandMax), s_CardsInHandMax);
    
    m_players[0] = new PokerHumanPlayer(hand,0);
    
    for (int i = 1; i < m_amountOfPlayers; ++i)
    {
        hand = Hand(m_deck.Distribute(s_CardsInHandMax), s_CardsInHandMax);
        m_players[i] = new PokerComputerPlayer(hand,i);
    }
}


