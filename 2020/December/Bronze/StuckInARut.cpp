#include<bits/stdc++.h>
using namespace std;

struct cow
{
	int x;
	int y;
	//int stopped = 0;
	int idx;
	int answer = -1;
};

bool sortE(cow a, cow b)
{
	return a.y < b.y;
}

bool sortN(cow a, cow b)
{
	return a.x < b.x;
}

int n;
int main()
{
	cin >> n;
	vector<cow> allCows;
	vector<cow> east;
	vector<cow> north;

	int a; int b; char dir;
	cow temp;
	for (int i = 0; i < n; i++)
	{
		cin >> dir;
		cin >> temp.x >> temp.y;
		temp.idx = i;
		allCows.push_back(temp);
		if (dir == 'E')
		{
			east.push_back(temp);
		}
		else {
			north.push_back(temp);
		}
	}

	sort(east.begin(), east.end(), sortE);
	sort(north.begin(), north.end(), sortN);

	//all at same time
	for (int i = 0; i < east.size(); i++)
	{
		for (int j = 0; j < north.size(); j++)
		{
			if (east[i].y - north[j].y >= 0 and north[j].x - east[i].x >= 0 and allCows[east[i].idx].answer == -1 and allCows[north[j].idx].answer == -1)
			{
				if (east[i].y - north[j].y == north[j].x - east[i].x)
				{
				}
				else if (east[i].y - north[j].y > north[j].x - east[i].x)
				{
					if (allCows[north[j].idx].answer == -1) {
						allCows[north[j].idx].answer = east[i].y - north[j].y;
					}
				}
				else
				{
					if (allCows[east[i].idx].answer == -1) {
						allCows[east[i].idx].answer = north[j].x - east[i].x;
					}
				}
			}
		}
	}

	for (auto cow : allCows)
	{
		if (cow.answer == -1)
		{
			cout << "Infinity" << "\n";
		}
		else
		{
			cout << cow.answer << "\n";
		}
	}

}