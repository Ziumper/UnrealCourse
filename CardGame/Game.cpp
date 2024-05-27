#include "Game.h"

void Game::End()
{
    cout << "Ending the game!" << endl;

    m_humanPlayers = 0;
    m_computerPlayers = 0;
    m_playersAmount = 0;
} 

bool Game::IsFinish()
{
    return m_finished;
}

void Game::CreateHumanPlayer(int index) 
{
    cout << "Creating Human Player with index: " << index << endl;
}

void Game::CreateComputerPlayer(int index)
{
    cout << "Creating Computer Player with index: " << index << endl;
}

void Game::CreatePlayers() 
{
    cout << "Please proivde number of human players:" << endl;
    cin >> m_humanPlayers;

    cout << "Please provide number of computer players" << endl;
    cin >> m_computerPlayers;
    
    m_playersAmount = m_humanPlayers + m_computerPlayers;


    //validate 
    if (m_playersAmount < 2) 
    {
        cout << "There should be at least two players" << endl;
        cout << "Ending the game" << endl;
        m_finished = true;
        return;
    }

    if(m_playersAmount > 4) 
    {
        cout << "To many players to play this game." << endl 
        << "Players amount: " << m_playersAmount << endl;

        cout << "Ending the game" << endl;
        m_finished = true;
        return;
    }

    for(int i = 0; i < m_humanPlayers; ++i) 
    {
        CreateHumanPlayer(i);
    }

    for(int i =  m_humanPlayers; i < m_playersAmount; ++i) 
    {
        CreateComputerPlayer(i);
    }
}

void Game::Start() 
{
    cout << "Starting the game!" << endl;
    CreatePlayers();
}

void Game::Update() 
{
    cout << "Updating" << endl;
}
