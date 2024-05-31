#include "Game.h"

void Game::End()
{
    cout << "Ending the game!" << endl;
} 

bool Game::IsFinish()
{
    return m_finished;
}

void Game::Start() 
{
    cout << "Starting the game!" << endl;
}

void Game::Update() 
{
    cout << "Updating" << endl;
}
