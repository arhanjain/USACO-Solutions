#include<bits/stdc++.h>
using namespace std;

int grid[1000][1000];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	
	int a; 
	//construct grid
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a;
			grid[i][j] = a;
		}
	}

	//horizontal maximized sol
	int hsum = 0;
	for (int i = 0; i < n; i++)
	{
		int sum[2] = { 0, 0 };
		for (int j = 0; j < n; j++)
		{
			sum[j % 2] += grid[i][j];
		}
		hsum += max(sum[0], sum[1]);
	}

	//vert max sol
	int vsum = 0;
	for (int j = 0; j < n; j++)
	{
		int sum[2] = { 0, 0 };
		for (int i = 0; i < n; i++)
		{
			sum[i % 2] += grid[i][j];
		}
		vsum += max(sum[0], sum[1]);
	}

	cout << max(hsum, vsum) << "\n";
}