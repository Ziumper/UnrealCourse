#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void Game::OnInit()
{
	LoadWordsFromFile("words.txt"); // Podaj nazwê pliku z list¹ s³ów
	srand(std::time(NULL));
	int randomIndex = rand() % m_wordsPool.size();
	m_word = m_wordsPool[randomIndex];
	m_guessedLetters.resize(m_word.size());
}

void Game::OnInput()
{
	m_guessCharacter = ' ';
	if (m_gameState != GameState::UPDATE) return;
	std::cin >> m_guessCharacter;
}

bool Game::OnUpdate(float deltaTime)
{
	m_gameState = GameState::UPDATE;

	bool guessed = false;
	for (int i = 0; i < m_word.size(); ++i)
	{
		if (m_word[i] == m_guessCharacter) {
			m_guessedLetters[i] = true;
			guessed = true;
		}
	}

	if (!guessed && m_guessCharacter != ' ') {
		++m_wrongGuessCount;
	}

	
	if (GuessedRightCount() == m_word.size()) return true;

	return m_wrongGuessCount == m_gameChancesLimit;
}

void Game::OnRender()
{
	system("cls");

	std::cout << "Liczba liter pozostalych do odgadniecia:" << m_word.size() - GuessedRightCount() << std::endl;
	std::cout << "Zle odpowiedzi:" << m_wrongGuessCount << std::endl;

	std::cout << std::endl;
	
	switch (m_wrongGuessCount)
	{
	case 15:
		std::cout << std::endl;
		std::cout << "  - - -" << std::endl;
		std::cout << " |    | " << std::endl;
		std::cout << " |    0 " << std::endl;
		std::cout << " |  / | \\" << std::endl;
		std::cout << " |    |" << std::endl;
		std::cout << " |   / \\" << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 14:
		std::cout << std::endl;
		std::cout << "  - - -" << std::endl;
		std::cout << " |    | " << std::endl;
		std::cout << " |    0 " << std::endl;
		std::cout << " |  / | \\" << std::endl;
		std::cout << " |    |" << std::endl;
		std::cout << " |   /" << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 13:
		std::cout << std::endl;
		std::cout << "  - - -" << std::endl;
		std::cout << " |    | " << std::endl;
		std::cout << " |    0 " << std::endl;
		std::cout << " |  / | \\" << std::endl;
		std::cout << " |    |" << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 12:
		std::cout << std::endl;
		std::cout << "  - - -" << std::endl;
		std::cout << " |    | " << std::endl;
		std::cout << " |    0 " << std::endl;
		std::cout << " |  / | \\" << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 11:
		std::cout << std::endl;
		std::cout << "  - - -" << std::endl;
		std::cout << " |    | " << std::endl;
		std::cout << " |    0 " << std::endl;
		std::cout << " |  /   \\" << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 10:
		std::cout << std::endl;
		std::cout << "  - - -" << std::endl;
		std::cout << " |    | " << std::endl;
		std::cout << " |    0 " << std::endl;
		std::cout << " |  /	  " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 9:
		std::cout << std::endl;
		std::cout << "  - - -" << std::endl;
		std::cout << " |    | " << std::endl;
		std::cout << " |    0 " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 8:
		std::cout << std::endl;
		std::cout << "  - - -" << std::endl;
		std::cout << " |    | " << std::endl;
		std::cout << " |     " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 7:
		std::cout << std::endl;
		std::cout << "  - - -" << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " |  " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 6:
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " |  " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 5:
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << " |  " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 4:
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << " | " << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 3:
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << " | " << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 2:
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "/ \\" << std::endl;
		break;
	case 1:
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "/" << std::endl;
		break;
	default:
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		break;
	}

	std::cout << std::endl;


	for (int i = 0; i < m_word.size(); ++i)
	{
		if (m_guessedLetters[i]) {
			std::cout << m_word[i];
		}
		else
		{
			std::cout << " _ ";
		}
	}

	std::cout << std::endl;
	std::cout << std::endl << "Podaj litere:" << std::endl;

	
}

void Game::OnShutdown()
{
	m_guessedLetters.clear();
	m_gameState = GameState::FINISH;

	std::cout << "Gra zostala zakonczona" << std::endl;
}

int Game::GuessedRightCount()
{
	int guessedRight = 0;

	for (int i = 0; i < m_word.size(); ++i)
	{
		if (m_guessedLetters[i]) {
			++guessedRight;
		}
	}

	return guessedRight;
}

void Game::LoadWordsFromFile(const std::string& filename)
{
	std::ifstream file(filename);
	if (file.is_open()) {
		std::string word;
		while (std::getline(file, word)) {
			if (!word.empty()) {
				m_wordsPool.push_back(word);
			}
		}
		file.close();
	}
	else {
		std::cerr << "Nie mo¿na otworzyæ pliku: " << filename << std::endl;
	}
}
