#pragma once
#include <string>
#include <vector>


class Game
{
	enum class GameState
	{
		START,
		UPDATE,
		FINISH
	};

public:
	void OnInit();
	void OnInput();
	bool OnUpdate(float deltaTime);
	void OnRender();
	void OnShutdown();

private:
	std::string m_word;
	std::vector<std::string> m_wordsPool;
	std::vector<bool> m_guessedLetters;
	int m_wrongGuessCount;
	GameState m_gameState = GameState::START;
	const int m_gameChancesLimit = 15;
	char m_guessCharacter;
	int GuessedRightCount();
	void LoadWordsFromFile(const std::string& filename);

};