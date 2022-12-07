// AoC2022_Day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

enum PlayerInput {
	Rock=1, Paper=2, Scissors=3
};

int LoseMePlease(int OpponentInput)
{
	switch(OpponentInput)
	{

	case Rock: return Scissors;
		break;
	case Scissors: return Paper;
		break;
	case Paper: return Rock;
		break;
	default:
		break;
	}
}

int WinMePlease(int OpponentInput)
{
	switch (OpponentInput)
	{

	case Rock: return Paper;
		break;
	case Scissors: return Rock;
		break;
	case Paper: return Scissors;
		break;
	default:
		break;
	}
}

void GetScore2(int &Player1Score, int &Player2Score, char Player1_Input, char Player2_Input)
{
	int convertP1Input, convertP2Input = 0;

	switch (Player1_Input)
	{
	case 'A': convertP1Input = Rock;
		break;
	case 'B': convertP1Input = Paper;
		break;
	case 'C': convertP1Input = Scissors;
		break;

	}

	switch (Player2_Input)
	{
		// Lose Game
	case 'X': convertP2Input = LoseMePlease(convertP1Input);
		break;
		// Draw Game
	case 'Y': convertP2Input = convertP1Input;
		break;
		// Win Game
	case 'Z': convertP2Input = WinMePlease(convertP1Input);
		break;

	}

	// Draw Game
	if (convertP1Input == convertP2Input)
	{
		Player1Score += convertP1Input + 3;
		Player2Score += convertP2Input + 3;
	}
	// Player1 Win Rock
	else if (convertP1Input == Rock && convertP2Input == Scissors)
	{
		Player1Score += convertP1Input + 6;
		Player2Score += convertP2Input;
	}
	// Player2 Win Rock
	else if (convertP1Input == Scissors && convertP2Input == Rock)
	{
		Player1Score += convertP1Input;
		Player2Score += convertP2Input + 6;
	}
	// Player1 Win Scissors
	else if (convertP1Input == Scissors && convertP2Input == Paper)
	{
		Player1Score += convertP1Input + 6;
		Player2Score += convertP2Input;
	}
	// Player2 Win Scissors
	else if (convertP1Input == Paper && convertP2Input == Scissors)
	{
		Player1Score += convertP1Input;
		Player2Score += convertP2Input + 6;
	}
	// Player1 Win Paper
	else if (convertP1Input == Paper && convertP2Input == Rock)
	{
		Player1Score += convertP1Input + 6;
		Player2Score += convertP2Input;
	}
	// Player2 Win Paper
	else if (convertP1Input == Rock && convertP2Input == Paper)
	{
		Player1Score += convertP1Input;
		Player2Score += convertP2Input + 6;
	}


	return;

}

void GetScore(int &Player1Score, int &Player2Score, char Player1_Input, char Player2_Input)
{
	int convertP1Input,convertP2Input = 0;

	switch (Player1_Input)
	{
		case 'A': convertP1Input = Rock;
			break;
		case 'B': convertP1Input = Paper;
			break;
		case 'C': convertP1Input = Scissors;
			break;

	}

	switch (Player2_Input)
	{
	case 'X': convertP2Input = Rock;
		break;
	case 'Y': convertP2Input = Paper;
		break;
	case 'Z': convertP2Input = Scissors;
		break;

	}

	// Draw Game
	if (convertP1Input == convertP2Input)
	{
		Player1Score += convertP1Input + 3;
		Player2Score += convertP2Input + 3;
	}
	// Player1 Win Rock
	else if (convertP1Input == Rock && convertP2Input == Scissors)
	{
		Player1Score += convertP1Input + 6;
		Player2Score += convertP2Input;
	}
	// Player2 Win Rock
	else if (convertP1Input == Scissors && convertP2Input == Rock)
	{
		Player1Score += convertP1Input;
		Player2Score += convertP2Input + 6;
	}
	// Player1 Win Scissors
	else if (convertP1Input == Scissors && convertP2Input == Paper)
	{
		Player1Score += convertP1Input + 6;
		Player2Score += convertP2Input;
	}
	// Player2 Win Scissors
	else if (convertP1Input == Paper && convertP2Input == Scissors)
	{
		Player1Score += convertP1Input;
		Player2Score += convertP2Input + 6;
	}
	// Player1 Win Paper
	else if (convertP1Input == Paper && convertP2Input == Rock)
	{
		Player1Score += convertP1Input + 6;
		Player2Score += convertP2Input;
	}
	// Player2 Win Paper
	else if (convertP1Input == Rock && convertP2Input == Paper)
	{
		Player1Score += convertP1Input;
		Player2Score += convertP2Input + 6;
	}


	return;

}

void AoC2022_Day2B()
{
	// A : Rock B : Paper C : Scissor
	// X : Lose Y : Draw Z : Win
	std::cout << "AoC2022 Day2 : Scissors Paper Stone Total Score\n";
	ifstream inputfile;
	inputfile.open(".\\Day2_Input.txt");

	string delimiter = " ";
	char Player1_Input, Player2_Input;
	int player1Score = 0;
	int player2Score = 0;
	int *p1, *p2;
	p1 = &player1Score;
	p2 = &player2Score;


	if (!inputfile.is_open())
	{
		std::cerr << "Unable to open .\\Day2_Input.txt" << '\n';
		return;
	}
	string s;
	while (getline(inputfile, s))
	{

		Player1_Input = s.substr(0, s.find(delimiter))[0];
		Player2_Input = s.substr(s.find(delimiter) + 1)[0];
		GetScore2(player1Score, player2Score, Player1_Input, Player2_Input);

		std::cout << "Player1_Input: " << Player1_Input << "Player2_Input: " << Player2_Input << '\n';
		std::cout << "player1Score: " << player1Score << "player2Score: " << player2Score << '\n';


	}


	std::cout << "player1Score: " << player1Score << "player2Score: " << player2Score << '\n';
	std::cout << "Sum of Score : " << player1Score + player2Score << '\n';

	getchar();

}


void AoC2022_Day2()
{
	// A : Rock B : Paper C : Stone
	// X : Rock Y : Paper Z : Stone
	std::cout << "AoC2022 Day2 : Scissors Paper Stone Total Score\n";
	ifstream inputfile;
	inputfile.open(".\\Day2_Input.txt");

	string delimiter = " ";
	char Player1_Input, Player2_Input;
	int player1Score = 0;
	int player2Score = 0;
	int *p1, *p2;
	p1 = &player1Score;
	p2 = &player2Score;


	if (!inputfile.is_open())
	{
		std::cerr << "Unable to open .\\Day2_Input.txt" << '\n';
		return;
	}
	string s;
	while (getline(inputfile, s))
	{
		
		Player1_Input = s.substr(0, s.find(delimiter))[0];
		Player2_Input = s.substr(s.find(delimiter) + 1)[0];
		GetScore(player1Score, player2Score, Player1_Input, Player2_Input);

		std::cout << "Player1_Input: "<< Player1_Input << "Player2_Input: " << Player2_Input << '\n';
		std::cout << "player1Score: " << player1Score << "player2Score: " << player2Score << '\n';

		
	}

	
	std::cout << "player1Score: " << player1Score << "player2Score: " << player2Score << '\n';
	std::cout << "Sum of Score : " << player1Score + player2Score << '\n';

	getchar();

}

int main()
{
    std::cout << "Hello World!\n";
	AoC2022_Day2();
	AoC2022_Day2B();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
