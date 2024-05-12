#include <iostream>

using namespace std;

#define BOARD_SIZE 3
#define BLANK_SPACE '_'
char BOARD[BOARD_SIZE][BOARD_SIZE];

void Initialize()
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			BOARD[i][j] = BLANK_SPACE;
		}
	}
}

void Render()
{
	system("cls");

	cout << "  ";
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		cout << i << ' ';
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			cout << BOARD[i][j] << " ";
		}
		cout << endl;
	}
}

bool HasWon(char playerSymbol, int x, int y)
{
	bool result = true;

	// wiersze
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (BOARD[x][i] != playerSymbol)
		{
			result = false;
			break;
		}
	}

	if (result) return true;

	result = true;

	// kolumny
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (BOARD[i][y] != playerSymbol)
		{
			result = false;
			break;
		}
	}

	if (result) return true;

	result = true;

	//na skos - z lewo na prawo
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (BOARD[i][i] != playerSymbol) {
			result = false;
			break;
		}
	}

	if (result) return true;

	result = true;

	//na skos - z prawo na lewo
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		int column = BOARD_SIZE - i - 1;
		if (BOARD[i][column] != playerSymbol)
		{
			result = false;
			break;
		}
	}

	return result;
}


bool PlayerInput(char playerSymbol)
{
	int x, y;
	cout << "Podaj wiersz: ";
	cin >> x;
	cout << "Podaj kolumne: ";
	cin >> y;

	if (BOARD[x][y] == BLANK_SPACE)
	{
		BOARD[x][y] = playerSymbol;
		return HasWon(playerSymbol, x, y);
	}
	else
	{
		cout << "To pole jest zajete" << endl;
		return PlayerInput(playerSymbol);
	}

	return false;
}

void HotSeats()
{
	Initialize();

	for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i)
	{
		Render();
		char palyerSign = i % 2 == 0 ? 'X' : 'O';
		if (PlayerInput(palyerSign))
		{
			Render();
			cout << "Gracz " << palyerSign << " wygral, gratulacje!";
			return;
		}
	}

	cout << "Remis!" << endl;
}

char GetSign()
{
	system("cls");

	char sign = 'X';

	cout << "Wybierz swoj znak:" << endl
		<< "- X" << endl
		<< "- O" << endl;

	cin >> sign;

	if (sign != 'X' && sign != '0')
	{
		return 'X'; //return default one
	}

	system("cls");

	return sign;
}

bool ComputerInput(char computerSymbol)
{
	int x, y;

	//random strategy
	x = rand() % 3;
	y = rand() % 3;

	if (BOARD[x][y] == BLANK_SPACE)
	{
		BOARD[x][y] = computerSymbol;
		return HasWon(computerSymbol, x, y);
	}
	else
	{
		ComputerInput(computerSymbol);
	}

	return false;
}

void WithComputer()
{
	Initialize();
	char sign = GetSign();

	for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i)
	{
		Render();
		char playerSign = i % 2 == 0 ? 'X' : 'O';

		if (playerSign == sign) {

			if (PlayerInput(playerSign))
			{
				Render();
				cout << "Gra wygrana!, Gratulacje!";
				return;
			}
		}
		else { //computer move
			if (ComputerInput(playerSign)) {
				Render();
				cout << "Komputer wygrał z tobą! Spróbuj ponownie!";
				return;
			}
		}
	}
}




int main()
{
	cout << "Wybierz gre: " << endl
		<< "1. Gra z drugim graczem " << endl
		<< "2. Gra z komputerem " << endl
		<< "3. Wyjscie" << endl;

	int mode = 0;

	cin >> mode;

	switch (mode)
	{
	case 1:
		HotSeats();
		break;
	case 2:
		WithComputer();
		break;
	case 3:
		cout << "Wychodze z gry" << endl;
		break;
	default:
		cout << "Nieprawidłowy tryb rozgrywki, wychodze z gry" << endl;
		break;
	}

	return 0;
}




