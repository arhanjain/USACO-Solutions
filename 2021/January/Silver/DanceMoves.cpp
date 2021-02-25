#include <bits/stdc++.h>
using namespace std;

vector<int> adjMat[100001];
vector<int> visited(100001);
vector<int> adj[100001];
vector<vector<int>> components(1);

vector<set<int>> answers;

void dfs(int parent)
{
	visited[parent] = components.size() - 1;
	components[components.size() - 1].push_back(parent);

	for (auto i : adj[parent])
	{
		if (!visited[i])
		{
			dfs(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; int k;
	cin >> n >> k;

	vector<int> places;
	for (int i = 0; i < n; i++)
	{
		places.push_back(i);
		adjMat[i].push_back(i);
	}

	for (int i = 0; i < k; i++)
	{
		int a; int b;
		cin >> a >> b;
		a--; b--;
		//a switch
		int temp = places[a];
		adjMat[places[a]].push_back(b );
		places[a] = places[b];

		//b switch
		adjMat[places[b]].push_back(a );
		places[b] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		adj[places[i]].push_back(i);
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			components.resize(components.size() + 1);
			dfs(i);
		}
	}

	
	answers.resize(components.size());

	for (int i = 1; i < components.size(); i++)
	{
		for (auto cow : components[i])
		{
			for (auto pos : adjMat[cow])
			{
				answers[i].insert(pos);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << answers[visited[i]].size() << "\n";
	}
}