#include<bits/stdc++.h>
using namespace std;

vector<int> adjMat[1001];

struct cow {
	int idx;
	char dir;
	int xpos;
	int ypos;
	pair<int, int> stopped = { 0, 0 };
};

vector<cow> cowsE;
vector<cow> cowsN;

bool cowSorty(cow a, cow b)
{
	return a.ypos < b.ypos;
}

bool cowSortx(cow a, cow b)
{
	return a.xpos < b.xpos;
}

int dfs(int parent)
{
	int extra = 0;
	for(int i = 0; i < adjMat[parent].size(); i++)
	{
		extra += dfs(adjMat[parent][i]);
	}
	return adjMat[parent].size() + extra;
}

int main()
{
	int n; cin >> n;
	char d; int x; int y;
	for (int i = 1; i <= n; i++)
	{
		cin >> d >> x >> y;
		if (d == 'E') // if east cow
		{
			cow temp;
			temp.idx = i;
			temp.dir = d;
			temp.xpos = x;
			temp.ypos = y;
			cowsE.push_back(temp);
		}
		else {
			cow temp;
			temp.idx = i;
			temp.dir = d;
			temp.xpos = x;
			temp.ypos = y;

			cowsN.push_back(temp);
		}
	}

	sort(cowsE.begin(), cowsE.end(), cowSorty);
	sort(cowsN.begin(), cowsN.end(), cowSortx);

	//does East cow block
	for (int i = 0; i < cowsE.size(); i++)
	{
		for (int j = 0; j < cowsN.size(); j++)
		{
			if (cowsE[i].ypos > cowsN[j].ypos)
			{//if north cow is lower than the east cow
				if (abs(cowsE[i].xpos - cowsN[j].xpos) < abs(cowsE[i].ypos - cowsN[j].ypos) and (cowsE[i].stopped.first >= cowsN[j].xpos || cowsE[i].stopped.first == 0) and cowsN[j].stopped.first == 0)
				{
					adjMat[cowsE[i].idx].push_back(cowsN[j].idx);
					cowsN[j].stopped = {cowsN[j].xpos, cowsE[i].ypos};
					//possible break
				}
			}
			if (cowsE[i].xpos < cowsN[j].xpos)
			{//if east cow is left than the north cow
				if (abs(cowsE[i].xpos - cowsN[j].xpos) > abs(cowsE[i].ypos - cowsN[j].ypos) and (cowsN[j].stopped.second >= cowsE[i].ypos || cowsN[j].stopped.second == 0) and cowsE[i].stopped.first == 0)
				{
					adjMat[cowsN[j].idx].push_back(cowsE[i].idx);
					cowsE[i].stopped = { cowsN[j].xpos, cowsE[i].ypos };
					//possible break
				}
			}
			
		}
	}

	vector<int> answers;
	for (int i = 1; i <= n; i++)
	{
		answers.push_back(dfs(i));
	}

	for (auto element : answers)
	{
		cout << element << "\n";
	}

}


