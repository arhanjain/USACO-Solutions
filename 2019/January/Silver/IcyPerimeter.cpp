#include<bits/stdc++.h>
using namespace std;

int n;
const int maxn = 1000;
char grid[maxn][maxn];
int visited[maxn][maxn];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

pair<int,int> dfs(int x, int y)
{
	pair<int, int> result = make_pair(0, 0);
	if (grid[x][y] == '.') return result;
	if (visited[x][y]) return result;
	visited[x][y] = 1;
	
	result.first++;

	for (int i = 0; i < 4; i++)
	{
		int x1 = x + dx[i]; int y1 = y + dy[i];
		if ((x1 < n and y1 < n) and !visited[x1][y1])
		{
			if (grid[x1][y1] == '#')
			{
				pair<int, int> temp = dfs(x1, y1);
				result.first += temp.first;
				result.second += temp.second;
			}
			if (grid[x1][y1] == '.')
			{
				result.second++;
			}
		}
		 if (x1 >= n or x1 < 0)
		{
			result.second++;
		}
		 if (y1 >= n or y1 < 0)
		{
			result.second++;
		}
	}
	return result;
}

int main()
{
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}

	vector<pair<int,int>> areas;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			pair<int, int> result = dfs(i, j);
			areas.push_back(make_pair(result.first, result.second));
		}
	}
	sort(areas.begin(), areas.end());
	vector<pair<int, int>> perims;
	perims.push_back(areas[areas.size() - 1]);
	for (int i = areas.size() - 2; i >= 0 ; i--)
	{
		if (areas[i].first != areas[i + 1].first)
		{
			break;
		}
		perims.push_back(areas[i]);
	}
	int idx = -1;
	int perim = maxn * maxn + 1;
	for (int i = 0; i < perims.size(); i++)
	{
		if(perims[i].second < perim)
		{
			perim = perims[i].second;
			idx = i;
		}
	}

	cout << perims[idx].first << " " << perims[idx].second;
}