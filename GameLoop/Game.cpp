#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

void Game::OnInit()
{
	srand(std::time(NULL));
	int randomIndex = rand() % m_wordsPool.size();
	m_word = m_wordsPool[randomIndex];
	m_guessedLetters.resize(m_word.size());
}

void Game::OnInput()
{
	int x = 0;
	std::cin >> x;
	++m_wrongGuessCount;
}

bool Game::OnUpdate(float deltaTime)
{
	m_gameState = GameState::UPDATE;
	return m_wrongGuessCount == 14; //last chance
}

void Game::OnRender()
{
	system("cls");
	//rendering the characters
	for (int i = 0; i < m_word.size(); ++i)
	{
		if (m_guessedLetters[i]) {
			std::cout << m_word[i];
		} else
		{
			std::cout << " _ ";
		}
	}

	std::cout << std::endl;

	//rendering the most important part ;-) 
	
	switch (m_wrongGuessCount)
	{
	case 14:
		std::cout << "  - - -" << std::endl;
		std::cout << " |    | " << std::endl;
		std::cout << " |    0 " << std::endl;
		std::cout << " |  /	| \\" << std::endl;
		std::cout << " |  	| " << std::endl;
		std::cout << " |   / \\" << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 13:
		std::cout << "  - - -" << std::endl;
		std::cout << " |    | " << std::endl;
		std::cout << " |    0 " << std::endl;
		std::cout << " |  / | \\" << std::endl;
		std::cout << " |  	| " << std::endl;
		std::cout << " |   / " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 12:
		std::cout << "  - - -" << std::endl;
		std::cout << " |    | " << std::endl;
		std::cout << " |    0 " << std::endl;
		std::cout << " |  / | \\" << std::endl;
		std::cout << " |    | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 11:
		std::cout << "  - - -" << std::endl;
		std::cout << " |    | " << std::endl;
		std::cout << " |    0 " << std::endl;
		std::cout << " |  / | \\" << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 10:
		std::cout << "  - - -" << std::endl;
		std::cout << " |    | " << std::endl;
		std::cout << " |    0 " << std::endl;
		std::cout << " |  /	  " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 9:
		std::cout << "  - - -" << std::endl;
		std::cout << " |    | " << std::endl;
		std::cout << " |    0 " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 8:
		std::cout << "  - - -" << std::endl;
		std::cout << " |    | " << std::endl;
		std::cout << " |     " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 7:
		std::cout << "  - - -" << std::endl;
	case 6:
		std::cout << " | " << std::endl;
	case 5:
		std::cout << " |  " << std::endl;
	case 4:
		std::cout << " | " << std::endl;
	case 3:
		std::cout << " | " << std::endl;
	case 2:
		std::cout << "/ \\" << std::endl;
		break;
	case 1:
		std::cout << "/" << std::endl;
		break;
	default:
		break;
	}
}

void Game::OnShutdown()
{
	m_guessedLetters.clear();
	m_gameState = GameState::FINISH;
	std::cout << "Gra zostala zakonczona" << std::endl;
}