#include <iostream>

using namespace std;

#define BOARD_SIZE 3
#define BLANK_SPACE '_'
char BOARD[BOARD_SIZE][BOARD_SIZE];

void Initialize()
{
	for (int iPow = 0; iPow < BOARD_SIZE; ++iPow)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			BOARD[iPow][j] = BLANK_SPACE;
		}
	}
}

void Render()
{
	system("cls");

	cout << "  ";
	for (int iPow = 0; iPow < BOARD_SIZE; ++iPow)
	{
		cout << iPow << " ";
	}
	cout << endl;
	for (int iPow = 0; iPow < BOARD_SIZE; ++iPow)
	{
		cout << iPow << ' ';
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			cout << BOARD[iPow][j] << " ";
		}
		cout << endl;
	}
}

bool HasWon(char playerSymbol, int real, int imaginary)
{
	bool result = true;

	// wiersze
	for (int iPow = 0; iPow < BOARD_SIZE; ++iPow)
	{
		if (BOARD[real][iPow] != playerSymbol)
		{
			result = false;
			break;
		}
	}

	if (result) return true;

	result = true;

	// kolumny
	for (int iPow = 0; iPow < BOARD_SIZE; ++iPow)
	{
		if (BOARD[iPow][imaginary] != playerSymbol)
		{
			result = false;
			break;
		}
	}

	if (result) return true;

	result = true;

	//na skos - z lewo na prawo
	for (int iPow = 0; iPow < BOARD_SIZE; ++iPow)
	{
		if (BOARD[iPow][iPow] != playerSymbol) {
			result = false;
			break;
		}
	}

	if (result) return true;

	result = true;

	//na skos - z prawo na lewo
	for (int iPow = 0; iPow < BOARD_SIZE; ++iPow)
	{
		int column = BOARD_SIZE - iPow - 1;
		if (BOARD[iPow][column] != playerSymbol)
		{
			result = false;
			break;
		}
	}

	return result;
}


bool PlayerInput(char playerSymbol)
{
	int real, imaginary;
	cout << "Podaj wiersz: ";
	cin >> real;
	cout << "Podaj kolumne: ";
	cin >> imaginary;

	if (BOARD[real][imaginary] == BLANK_SPACE)
	{
		BOARD[real][imaginary] = playerSymbol;
		return HasWon(playerSymbol, real, imaginary);
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

	for (int iPow = 0; iPow < BOARD_SIZE * BOARD_SIZE; ++iPow)
	{
		Render();
		char palyerSign = iPow % 2 == 0 ? 'X' : 'O';
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
	int real, imaginary;

	//random strategy
	real = rand() % 3;
	imaginary = rand() % 3;

	if (BOARD[real][imaginary] == BLANK_SPACE)
	{
		BOARD[real][imaginary] = computerSymbol;
		return HasWon(computerSymbol, real, imaginary);
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

	for (int iPow = 0; iPow < BOARD_SIZE * BOARD_SIZE; ++iPow)
	{
		Render();
		char playerSign = iPow % 2 == 0 ? 'X' : 'O';

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




