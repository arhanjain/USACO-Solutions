#include<bits/stdc++.h>
using namespace std;

int n;
int grid[1002][1002];

int check(int x, int y)
{
	int count = 0;
	if (grid[x - 1][y] == 1) count++;
	if (grid[x + 1][y] == 1) count++;
	if (grid[x][y + 1] == 1) count++;
	if (grid[x][y - 1] == 1) count++;

	return count;
}

int main()
{
	double startpoint = 0;
	double midpoint = 0.5;
	double endpoint = 1;

	while ((endpoint - startpoint) > 0.0001)
	{
		midpoint = ((startpoint + endpoint) / 2);
		if ((midpoint - cos(midpoint)) == 0.0)
			break;
		else if ((midpoint - cos(midpoint))*(startpoint - cos(startpoint)) < 0)
			endpoint = midpoint;
		else
			startpoint = midpoint;
	}

	cout << midpoint;
	/*
	cin >> n;
	vector<int> answers;
	int x; int y;
	
	int lastProb = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y; x++; y++;
		grid[x][y] = 1;
		int nearby = check(x, y);
		if (nearby == 3)
		{
			lastProb++;
		}
			
		int left = check(x - 1, y);
		int right = check(x + 1, y);
		int top = check(x, y+1);
		int down = check(x, y-1);

		if (left == 4) lastProb--;
		if (left == 3) lastProb++;

		if (right == 4) lastProb--;
		if (right == 3) lastProb++;

		if (top == 4) lastProb--;
		if (top == 3) lastProb++;
		
		if (down == 4) lastProb--;
		if (down == 3) lastProb++;

		answers.push_back(lastProb);
	
	}

	for (int i : answers)
	{
		cout << i << "\n";
	}
	*/
}