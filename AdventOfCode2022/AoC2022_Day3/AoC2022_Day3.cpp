// AoC2022_Day3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void AoC2022_Day3B()
{
	// A : Rock B : Paper C : Stone
	// X : Rock Y : Paper Z : Stone
	std::cout << "AoC2022 Day3 : Char Sorting\n";
	ifstream inputfile;
	inputfile.open(".\\Day3_Input.txt");

	string compar1, compar2, samechar;
	string line1, line2, line3;
	int sum = 0;


	if (!inputfile.is_open())
	{
		std::cerr << "Unable to open .\\Day3_Input.txt" << '\n';
		return;
	}
	string s;
	while (!inputfile.eof())
	{
		getline(inputfile, line1);
		getline(inputfile, line2);
		getline(inputfile, line3);
		// Assuming there is only 1 common type per sack
		for (int i = 0; i < (int)line1.length(); i++)
		{
			for (int j = 0; j < (int)line2.length(); j++)
			{
				if (line1[i] == line2[j])
				{
					for (int k = 0; k < (int)line3.length(); k++)
					{
						if (line1[i] == line3[k])
						{
							samechar += line1[i];
							goto NextLine;
						}

					}
				}
			}
		}


	NextLine:
		//GetScore(player1Score, player2Score, Player1_Input, Player2_Input);

		std::cout << "Total Chars: " << samechar << '\n';


	}
	for (int i = 0; i < (int)samechar.length(); i++)
	{
		// A to Z (ascii value 65 to 90) 
		// Convert to ( 27 - 52 )
		if (isupper(samechar[i]))
		{
			sum += static_cast<int>(samechar[i]) - 65 + 27;
		}
		else // a to z (ascii value 97 - 122) Convert to (1-26)
		{
			sum += static_cast<int>(samechar[i]) - 97 + 1;
		}
	}



	//std::cout << "player1Score: " << player1Score << "player2Score: " << player2Score << '\n';
	std::cout << "Sum of Score : " << sum << '\n';

	getchar();

}

void AoC2022_Day3()
{
	// A : Rock B : Paper C : Stone
	// X : Rock Y : Paper Z : Stone
	std::cout << "AoC2022 Day3 : Char Sorting\n";
	ifstream inputfile;
	inputfile.open(".\\Day3_Input.txt");

	string compar1, compar2, samechar;
	int sum = 0;


	if (!inputfile.is_open())
	{
		std::cerr << "Unable to open .\\Day3_Input.txt" << '\n';
		return;
	}
	string s;
	while (getline(inputfile, s))
	{
		int s_mid_loc = s.length() / 2;
		compar1 = s.substr(0, s_mid_loc);
		compar2 = s.substr(s_mid_loc);
		
		// Assuming there is only 1 common type per sack
		for (int i = 0; i < (int)compar1.length(); i++)
		{
			for (int j = 0; j < (int)compar2.length(); j++)
			{
				if (compar1[i] == compar2[j])
				{
					samechar += compar1[i];
					goto NextLine;
				}
			}
		}
		
		
		NextLine: 
		//GetScore(player1Score, player2Score, Player1_Input, Player2_Input);

		std::cout << "Total Chars: " << samechar <<  '\n';


	}
	for (int i = 0; i < (int)samechar.length(); i++)
	{
		// A to Z (ascii value 65 to 90) 
		// Convert to ( 27 - 52 )
		if (isupper(samechar[i]))
		{
			sum += static_cast<int>(samechar[i]) - 65 + 27;
		}
		else // a to z (ascii value 97 - 122) Convert to (1-26)
		{
			sum += static_cast<int>(samechar[i]) - 97 + 1;
		}
	}



	//std::cout << "player1Score: " << player1Score << "player2Score: " << player2Score << '\n';
	std::cout << "Sum of Score : " << sum << '\n';

	getchar();

}

int main()
{
	std::cout << "Hello World!\n";
	AoC2022_Day3();
	AoC2022_Day3B();
}
