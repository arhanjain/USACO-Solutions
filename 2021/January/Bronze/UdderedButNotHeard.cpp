#include<bits/stdc++.h>
using namespace std;

string uddered;
string cowphabet1;

vector<char> cowphabet;
vector<char> heardLetters;

int main()
{
	cin >> cowphabet1 >> uddered;
	int numOfCowphabets = 0;

	for (int i = 0; i < uddered.size(); i++)
	{
		heardLetters.push_back(uddered[i]);
	}
	for (int i = 0; i < cowphabet1.size(); i++)
	{
		cowphabet.push_back(cowphabet1[i]);
	}

	while (heardLetters.size() > 0)
	{
		for (int i = 0; i < cowphabet.size(); i++)
		{
			cout << i;
			if (cowphabet1[i] == heardLetters[0])
			{
				heardLetters.erase(heardLetters.begin());
			}
			if (heardLetters.size() == 0)
			{
				break;
			}
		}
		numOfCowphabets++;
	}

	cout << numOfCowphabets;
}