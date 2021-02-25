#include<bits/stdc++.h>
using namespace std;

std::vector<string> cows;
std::vector<string> cows1;
std::vector<string> a_cows;
std::vector<string> b_cows;
std::vector<string> ordered_cows;

std::vector<string> numOfRestrictions(int cowIndex, int n)
{
	std:vector<string> instances;

	if(find(a_cows.begin(),a_cows.end(), cows1[cowIndex]) == a_cows.end() && find(b_cows.begin(), b_cows.end(), cows1[cowIndex]) == b_cows.end())
	{
		return instances;
	}
	else
	{
		for (int j = 0; j < n; j++)
		{
			if (a_cows[j].compare(cows1[cowIndex]) == 0 && std::find(ordered_cows.begin(), ordered_cows.end(), a_cows[j]) == ordered_cows.end())
			{
				instances.push_back(b_cows[j]);
			}
			if (b_cows[j].compare(cows1[cowIndex]) == 0 && std::find(ordered_cows.begin(), ordered_cows.end(), a_cows[j]) == ordered_cows.end())
			{
				instances.push_back(a_cows[j]);
			}
		}
	}
	return instances;
}






int main()
{
	

	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	

	cows.push_back("Beatrice");
	cows.push_back("Belinda");
	cows.push_back("Bella");
	cows.push_back("Bessie");
	cows.push_back("Betsy");
	cows.push_back("Blue");
	cows.push_back("Buttercup");
	cows.push_back("Sue");
	cows1 = cows;
	int n;
	cin >> n;

	string placeholder;

	

	for (int i = 0; i < n; i++)
	{
		cin >> placeholder;
		a_cows.push_back(placeholder);
		cin >> placeholder;
		cin >> placeholder;
		cin >> placeholder;
		cin >> placeholder;
		cin >> placeholder;
		b_cows.push_back(placeholder);
	}
	int comparedIndex = 0;
	vector<int> groupStarters;

	while(cows.size()>0)
	{
		// if we are on current streak or new cow from queue
		std::vector<string> pairedCows = numOfRestrictions(comparedIndex,n);

		if (pairedCows.size() == 1)
		{
			ordered_cows.push_back(cows1[comparedIndex]);
			groupStarters.push_back(ordered_cows.size()-1);
			cows.erase(find(cows.begin(), cows.end(), cows1[comparedIndex]));
			ordered_cows.push_back(pairedCows[0]); 
			for (int i = 0; i < cows1.size(); i++)
			{
				if (cows1[i].compare(pairedCows[0]) == 0) comparedIndex = i;
			}
			cows.erase(find(cows.begin(), cows.end(), cows1[comparedIndex]));
			//comparedIndex = std::find(cows.begin(), cows.end(), pairedCows[0]);
		}
		else if(pairedCows.size() == 2)
		{
			if (pairedCows[0] < pairedCows[1])
			{
				ordered_cows.push_back(pairedCows[0]);
				groupStarters.push_back(ordered_cows.size() - 1);
				for (int i = 0; i < cows.size(); i++)
				{
					if (cows[i].compare(pairedCows[0]) == 0) cows.erase(cows.begin() + i);
				}
				ordered_cows.push_back(cows1[comparedIndex]);
				cows.erase(find(cows.begin(), cows.end(), cows1[comparedIndex]));
				ordered_cows.push_back(pairedCows[1]);
				for (int i = 0; i < cows1.size(); i++)
				{
					if (cows1[i].compare(pairedCows[1]) == 0) comparedIndex = i;
				}
				cows.erase(find(cows.begin(), cows.end(), cows1[comparedIndex]));
			
				//comparedIndex = std::find(cows.begin(), cows.end(), pairedCows[1]);
			}
			if (pairedCows[0] > pairedCows[1])
			{
				ordered_cows.push_back(pairedCows[1]);
				groupStarters.push_back(ordered_cows.size() - 1);
				for (int i = 0; i < cows.size(); i++)
				{
					if (cows[i].compare(pairedCows[1]) == 0) cows.erase(cows.begin() + i);
				}
				ordered_cows.push_back(cows1[comparedIndex]);
				cows.erase(find(cows.begin(), cows.end(), cows1[comparedIndex]));
				ordered_cows.push_back(pairedCows[0]);
				for (int i = 0; i < cows1.size(); i++)
				{
					if (cows1[i].compare(pairedCows[0]) == 0) comparedIndex = i;
				}
				cows.erase(find(cows.begin(), cows.end(), cows1[comparedIndex]));
		
				//comparedIndex = std::find(cows.begin(), cows.end(), pairedCows[0]);
			}
		}
		else
		{
			if (find(ordered_cows.begin(), ordered_cows.end(), cows1[comparedIndex]) == ordered_cows.end())
			{
				ordered_cows.push_back(cows1[comparedIndex]);
				groupStarters.push_back(ordered_cows.size() - 1);
				cows.erase(find(cows.begin(), cows.end(), cows1[comparedIndex]));
		

			}
			if (cows.size() > 0)
			{
				for (int p = 0; p < cows1.size(); p++)
				{
					if (cows1[p].compare(cows[0]) == 0)
					{
						comparedIndex = p;
						break;
					}	
				}
			}
			
		}
	}

	vector<int> starter2 = groupStarters;
	vector<string> finalOrdered;
	int temp5;
	int hasHappened = 0;
	for (int i = 0; i < groupStarters.size(); i++)
	{
		for (int j = i + 1; j < groupStarters.size(); j++)
		{
			if (ordered_cows[groupStarters[i]] > ordered_cows[groupStarters[j]])
			{
				temp5 = groupStarters[i];
				starter2[i+hasHappened] = groupStarters[j];
				starter2[j] = temp5;
				hasHappened++;
			}
		}
	}

	int translation = 0;


	for (int i = 0; i < starter2.size(); i++)
	{
		for (int p = 0; p < groupStarters.size(); p++)
		{
			if (groupStarters[p] == starter2[i])
			{
				translation = p;
				break;
			}
		}
		if (translation + 1 < groupStarters.size())
		{
			for (int j = 0; j < groupStarters[translation + 1] - groupStarters[translation]; j++)
			{
				finalOrdered.push_back(ordered_cows[groupStarters[translation] + j]);
			}
		}
		else
		{
			finalOrdered.push_back(ordered_cows[groupStarters[translation]]);
		}
			
	}



	for (int i = 0; i < 8; i++)
	{
		cout << finalOrdered[i] << "\n";
	}


	
}
