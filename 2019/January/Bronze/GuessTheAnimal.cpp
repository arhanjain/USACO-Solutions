/*#include<bits/stdc++.h>
using namespace std;

int numOfAnimals;
vector<string> traits;
vector<string> uniqueTraits;

int main()
{
	//freopen("guess.in", "r", stdin);
	//freopen("guess.out", "w", stdout);

	string temp = "";
	int numOfTraits = 0;

	cin >> numOfAnimals;
	
	for (int i = 0; i < numOfAnimals; i++)
	{
		cin >> temp >> numOfTraits;
		for (int j = 0; j < numOfTraits; j++)
		{
			cin >> temp;
			traits.push_back(temp + " ");
		}
	}

	sort(traits.begin(), traits.end(), greater<string>());
	
	int maxYes = 0;
	for (int i = 0; i < traits.size(); i++)
	{
		if (find(uniqueTraits.begin(), uniqueTraits.end(), traits[i]) == uniqueTraits.end())
		{
			uniqueTraits.push_back(traits[i]);
			if (i < traits.size()-1)
			{
				if (traits[i + 1] == traits[i])
				{
					maxYes++;
				}
			}
		}
	}

	for (int i = 0; i < traits.size(); i++)
	{
		if (find(uniqueTraits.begin(), uniqueTraits.end(), traits[i]) == uniqueTraits.end())
		{
			
			if (i < traits.size() - 1)
			{
				if (traits[i + 1] != traits[i])
				{
					uniqueTraits.push_back(traits[i]);
				}
			}
			else
			{
				uniqueTraits.push_back(traits[i]);
			}
		}
	}

	for (int i = 0; i < uniqueTraits.size(); i++)
	{
		int instances = 0;
		for (int j = 0; j < traits.size(); j++)
		{
			if (uniqueTraits[i] == traits[j])
			{
				instances++;
			}
		}
		if (instances < 2)
		{
			maxYes++;
		}
	}

	maxYes--; 
	cout << maxYes;
	for (int i = 0; i < traits.size(); i++)
	{
		cout << traits[i];
	}

	
}*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int N;
vector<string> characteristics[100];

int num_common(int i, int j)
{
	int count = 0;
	vector<string>& v1 = characteristics[i], & v2 = characteristics[j];
	for (int i = 0; i < v1.size(); i++)
		for (int j = 0; j < v2.size(); j++)
			if (v1[i] == v2[j]) count++;
	return count;
}

int main(void)
{
	//ifstream fin("guess.in");
	cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		int K;
		cin >> s >> K;
		for (int j = 0; j < K; j++) {
			cin >> s;
			characteristics[i].push_back(s);
		}
	}

	int largest = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			largest = max(largest, num_common(i, j));

	ofstream fout("guess.out");
	cout << largest + 1 << "\n";
	return 0;
}