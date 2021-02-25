#include<bits/stdc++.h>
using namespace std;

string barn;
int totalStalls;
vector<int> D;


int main()
{
	//freopen("socdist1.in", "r", stdin);
	//freopen("socdist1.out", "w", stdout);

	//1111111

	cin >> totalStalls;
	cin >> barn;

	vector<int> emptyStalls;
	
	int minInitial = 0;
	int maxIntial = 0;
	vector<int> minStart;

	for (int i = 0; i < barn.length(); i++)
	{
		int spaces = 0;
		if (barn[i] == '0')
		{
			bool checkForZeros = true;
			minStart.push_back(i);
			while (checkForZeros)
			{
				spaces++;
				
				if (barn[i] != '0')
				{
					checkForZeros = false;
				}
				else
				{
					i++;
				}
				
			}
		}
		if (i < barn.length() - 1)
		{
			if (minInitial > spaces || minInitial == 0)
			{
				minInitial = spaces;
			}
			if (maxIntial < spaces)
			{
				maxIntial = spaces;
			}
		}
		else
		{
			if (barn[totalStalls - 1] == '1')
			{
				minInitial = spaces;
			}
		}
		
	}

	int count = 0;
	
	for (int j = 0; j < maxIntial; j++)
	{
		 
		for (int i = 0; i < barn.length(); i++)
		{
			int spaces = 0;
			if (barn[i] == '0')
			{
				
				bool checkForZeros = true;
				while (checkForZeros)
				{	
					spaces++;

					if (barn[i] != '0')
					{
						checkForZeros = false;
						if (spaces == maxIntial-j)
						{
							count++;
							if ((maxIntial - j) % 2 != 1)
							{
								D.push_back(((maxIntial - j) / 2)-1);
							}
							else
							{
								D.push_back((maxIntial - j) / 2);
							}
						}
						if (count == 2)
						{
							i = barn.length();
							j = maxIntial;
						}
					}
					else
					{
						i++;
					}

				}
			}

		}
	}

	//D.push_back(minInitial);
	
	int most = 0;
	for (int i = 0; i < 3; i++)
	{
		if ((i == 0 || D[i] > most) && D[i] > 1)
		{
			most = D[i];
		}
	}

	cout << most;

	
}