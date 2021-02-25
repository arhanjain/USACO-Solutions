#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> cows;
vector<int> stallHeights;

long long numOfWays;

int main()
{
	cin >> N;

	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		cows.push_back(temp);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		stallHeights.push_back(temp);
	}

	sort(cows.begin(), cows.end());
	sort(stallHeights.begin(), stallHeights.end());

	temp = 0;
	while (stallHeights.size() > 0)
	{
		int eligibleStalls = 0;
		for (int i = stallHeights.size(); i > 0; i--)
		{
			if (stallHeights[i-1] >= cows.back())
			{
				eligibleStalls++;
			}
		}
		stallHeights.erase(stallHeights.end() - 1);
		cows.erase(cows.end() - 1);
		if (temp == 0)
		{
			numOfWays = eligibleStalls;
		}
		else
		{
			numOfWays = numOfWays * eligibleStalls;
		}
		temp++;
	}

	cout << numOfWays;
	
}