#include<bits/stdc++.h>
using namespace std;

int n;

vector<int> adjMat[100001];
vector<int> infCows(100001);

vector<int> visited(100001);

int minDays = 0;

void dfs(int parent)
{
	visited[parent] = 1;
	if (adjMat[parent].size() > infCows[parent]) { //make enough infCowz
		
		minDays += ceil(log2(double(adjMat[parent].size()) / infCows[parent]));

	}
	if (infCows[parent]*pow(2, ceil(log2(double(adjMat[parent].size()) / infCows[parent]))) == adjMat[parent].size() and adjMat[parent].size() > 0)
	{
		minDays++;
	}
		
	for (int i = 0; i < adjMat[parent].size(); i++) //go to children of farm
	{
		if (!visited[adjMat[parent][i]])
		{
			minDays++;
			infCows[adjMat[parent][i]]++;
			adjMat[adjMat[parent][i]].erase(find(adjMat[adjMat[parent][i]].begin(), adjMat[adjMat[parent][i]].end(), parent));
			dfs(adjMat[parent][i]);
		}
	}

}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	int a;
	int b;
	for (int i = 1; i <= n - 1; i++) // add each farm to each other's adjMat
	{
		cin >> a >> b;
		adjMat[a].push_back(b);
		adjMat[b].push_back(a);
	}

	infCows[1] = 1;
	dfs(1);

	cout << minDays;

	//cout << ceil(log2(17 / 4)) << "\n";

	//cout << ceil(log2(double(17 )/ 4) )<< "\n";
	//cout << ceil(log2(double(12) / 4));
}

/*
10
1 2
1 3
1 4
2 5
2 6
3 7
3 8
4 9
4 10 
*/

/*
10
1 2
1 3
1 4
2 5
2 6
3 7
3 8
4 9
4 10
*/