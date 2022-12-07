// AoC2022_Day1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;


void AoC2022_Day1()
{
	std::cout << "AoC2022 Day1 : Find elves with highest Calories\n";
	ifstream inputfile;
	inputfile.open(".\\Day1_Input.txt");
	int value;
	int highCal = 0;
	int curCal = 0;


	if (!inputfile.is_open())
	{
		std::cerr << "Unable to open .\\Day1_Input.txt" << '\n';
		return ;
	}
	string s;
	while (getline(inputfile, s))
	{
		std::cout << s << '\n';
		if (s.empty())
		{
			if (highCal < curCal)
				highCal = curCal;
			curCal = 0;
			continue;
		}
		value = stoi(s);
		curCal += value;
	}

	std::cout << "HighCal = " << highCal << '\n';


	getchar();

}

void AoC2022_Day1PartB()
{
	std::cout << "AoC2022 Day1 : Find elves with highest Calories\n";
	ifstream inputfile;
	inputfile.open(".\\Day1_Input.txt");
	int value;
	int highCal = 0;
	int curCal = 0;

	if (!inputfile.is_open())
	{
		std::cerr << "Unable to open .\\Day1_Input.txt" << '\n';
		return;
	}

	vector<int> arr;
	string s;
	while (getline(inputfile, s))
	{
		std::cout << s << '\n';
		if (s.empty())
		{
			arr.push_back(curCal);
			curCal = 0;
			continue;
		}
		value = stoi(s);
		curCal += value;
	}

	sort(arr.begin(), arr.end(), greater <>());
	
	std::cout << "Top 3 Elves Total Cal = " << arr[0] + arr[1] + arr[2] << '\n';

	getchar();

	
}


int main()
{
	AoC2022_Day1();
	AoC2022_Day1PartB();
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
