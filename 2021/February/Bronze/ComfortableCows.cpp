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
}