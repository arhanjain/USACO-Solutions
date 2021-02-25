#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> breedIDs;
vector<int> groups;
int amountOfGroups = 0;

int main()
{
	cin >> N;
	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		breedIDs.push_back(temp);
	}


	for (int i = 0; i < breedIDs.size(); i++)
	{
		if (breedIDs[i] % 2 == 0)
		{
			groups.push_back(breedIDs[i]);
			breedIDs.erase(breedIDs.begin() + i);
			break;
		}
	}
	if (groups.size() == 0)
	{
		groups.push_back(breedIDs[0] + breedIDs[1]);
		breedIDs.erase(breedIDs.begin());
		breedIDs.erase(breedIDs.begin());

	}

	char state = 'o';
	int place = 0;
	bool keepRunning = true;

	while (breedIDs.size() > 2 && keepRunning)
	{
		int currentSize = breedIDs.size();
		if (state == 'o')
		{
			state = 'e';
			for (int i = 0; i < breedIDs.size(); i++)
			{
				if (breedIDs[i] % 2 == 1)
				{
					groups.push_back(breedIDs[i]);
					breedIDs.erase(breedIDs.begin() + i);
					break;
				}
			}
			if (currentSize == breedIDs.size())
			{
				keepRunning = false; 
				//amountOfGroups = breedIDs.size();
				cout << groups.size();
				return 0;
			}
		} 
		else if (state == 'e')
		{
			state = 'o';
			for (int i = 0; i < breedIDs.size(); i++)
			{
				if (breedIDs[i] % 2 == 0)
				{
					groups.push_back(breedIDs[i]);
					breedIDs.erase(breedIDs.begin() + i);
					break;
				}
			}
			if (currentSize == breedIDs.size())
			{
				vector<int> evens;
				for (int i = 0; i < breedIDs.size(); i++)
				{
					if (breedIDs[i] % 2 == 1)
					{
						evens.push_back(breedIDs[i]);
						breedIDs.erase(breedIDs.begin() + i);
					}
					if (evens.size() == 2)
					{
						break;
					}
				}
				groups.push_back(evens[0] + evens[1]);
			}
		}
	}

	if (breedIDs.size() == 2)
	{
		//if ((breedIDs[0] % 2 == 1 && breedIDs[1] % 2 == 1) && state == 'e')
		if ((breedIDs[0] % 2 == 1 && breedIDs[1] % 2 == 1) && state == 'e')
		{
			cout << groups.size()+1;
		} 
		else if ((breedIDs[0] % 2 == 1 || breedIDs[1] % 2 == 1) && state == 'e')
		{
			cout << groups.size() + 2;
		}
		else if (((breedIDs[0] % 2 == 1 && breedIDs[1] % 2 == 0) && state == 'o') || ((breedIDs[0] % 2 == 0 && breedIDs[1] % 2 == 1) && state == 'o'))
		{
			cout << groups.size() + 2;
		}
		else
		{
			cout << groups.size();
		}
	}
	else if (breedIDs.size() == 1)
	{
		if (state == 'e' && breedIDs[0] % 2 == 0)
		{
			cout << groups.size() + 1;
		}
		else if (state == 'o' && breedIDs[0] % 2 == 1)
		{
			cout << groups.size() + 1;
		}
		else if (state == 'o' && breedIDs[0] % 2 == 0)
		{
			cout << groups.size();
		}
		else
		{
			//cout << groups.size() - 1;
			cout << groups.size() - 2;
		}
	}
	else
	{
		cout << groups.size();
	} 

	
}