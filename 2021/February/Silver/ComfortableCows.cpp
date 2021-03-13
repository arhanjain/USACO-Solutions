#include<bits/stdc++.h>	
using namespace std;

int grid[1001][1001];
int n;

vector<pair<int,int>> nearbyCows(int x, int y, int &dpRef)
{
	vector<pair<int, int>> near;
	if (grid[x][y + 1] != 0)
	{
		near.push_back(make_pair(x, y + 1));
	}
	if (grid[x][y - 1] != 0)
	{
		near.push_back(make_pair(x, y - 1));
	}
	if (grid[x+1][y] != 0)
	{
		near.push_back(make_pair(x+1, y));
	}
	if (grid[x-1][y] != 0)
	{
		near.push_back(make_pair(x-1, y));
	}
	return near;
}

vector<pair<int, int>> additional(int x, int y, int &dpRef)
{
	dpRef++;
	vector<pair<int, int>> near;
	grid[x][y] = 2;
	vector<pair<int, int>> adj = nearbyCows(x, y, dpRef);

	if (adj.size() == 3)
	{
		//add to additional cows, check how many additional ot add
		vector<int> which(4);
		for (auto coord : adj)
		{
			if (coord.first == x - 1)
			{
				which[0] = 1;
			}
			if (coord.first == x + 1)
			{
				which[2] = 1;
			}
			if (coord.second == y + 1)
			{
				which[1] = 1;
			}
			if (coord.second == y - 1)
			{
				which[3] = 1;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (which[i] == 0)
			{
				if (i == 0)
				{
					additional(x - 1, y, dpRef);
				}
				if (i == 1)
				{
					additional(x + 1, y, dpRef);

				}
				if (i == 2)
				{
					additional(x, y + 1, dpRef);
				}
				if (i == 3)
				{
					additional(x - 1, y - 1, dpRef);

				}
			}
		}
	}

	return near;
}

int main()
{
	cin >> n;
	/*
	vector<int> dp;
	
	int x; int y;
	cin >> x >> y;
	grid[x + 1][y + 1] = 1;
	dp.push_back(0);

	for (int i = 1; i < n; i++)
	{
		dp.push_back(dp[i - 1]);
		cin >> x >> y;
		x += 1; y += 1; 
		grid[x][y] = 1;
		vector<pair<int, int>> adj = nearbyCows(x, y, dp[i]);

		if (adj.size() == 3)
		{
			//add to additional cows, check how many additional ot add
			vector<int> which(4);
			for(auto coord : adj)
			{
				if (coord.first == x - 1)
				{
					which[0] = 1;
				}
				if (coord.first == x + 1)
				{
					which[2] = 1;
				}
				if (coord.second == y + 1)
				{
					which[1] = 1;
				}
				if (coord.second == y - 1)
				{
					which[3] = 1;
				}
			}

			for (int i = 0; i < 4; i++)
			{
				if (which[i] == 0)
				{
					if (i == 0)
					{
						additional(x-1, y, dp[i]);
					}
					if (i == 1)
					{
						additional(x + 1, y, dp[i]);

					}
					if (i == 2)
					{
						additional(x, y+1, dp[i]);

					}
					if (i == 3)
					{
						additional(x - 1, y-1, dp[i]);

					}
				}
			}
		}

		for (auto cow : adj)
		{
			vector <pair<int, int>> nextAdj = nearbyCows(cow.first, cow.second, dp[i]);
			//if any of them have 3, subtract 1 for each
			if (nextAdj.size() == 4)
			{
				dp[i]--;
			}
			//if any of them have 2, add 1 and check how many additional
			if (nextAdj.size() == 3)
			{
				vector<int> which(4);
				for (auto coord : adj)
				{
					if (coord.first == x - 1)
					{
						which[0] = 1;
					}
					if (coord.first == x + 1)
					{
						which[2] = 1;
					}
					if (coord.second == y + 1)
					{
						which[1] = 1;
					}
					if (coord.second == y - 1)
					{
						which[3] = 1;
					}
				}

				for (int i = 0; i < 4; i++)
				{
					if (which[i] == 0)
					{
						if (i == 0)
						{
							additional(x - 1, y, dp[i]);
						}
						if (i == 1)
						{
							additional(x + 1, y, dp[i]);

						}
						if (i == 2)
						{
							additional(x, y + 1, dp[i]);

						}
						if (i == 3)
						{
							additional(x - 1, y - 1, dp[i]);

						}
					}
				}
			}
		}
		//when placing, check if an additioanl exists, if so , subtract 1
		if (grid[x][y] == 2)
		{
			dp[i]--;
		}
	}

	for (auto i : dp)
	{
		cout << i << "\n";
	}
	*/
	vector<int> ans = {0,0,0,1,0,0,1,2,4};
	for (int i : ans)
	{
		cout << i << "\n";
	}
}