#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> boot; //first is depth of snow, second is max step size
int n; int b; 
int visited[250][250];
vector<int> tiles;
vector<boot> boots;
int ans = 251;

void dfs(int loc, int currBoot)
{
	if (visited[loc][currBoot])
	{
		return;
	}
	visited[loc][currBoot] = 1;
	
	//if reached end, compare # discarded
	if (loc == n - 1)
	{
		ans = min(ans, currBoot);
		return;
	}
	//every location
	for (int i = loc + 1; i-loc <= boots[currBoot].second and i < n; i++)
	{
		if (tiles[i] <= boots[currBoot].first)
		{
			dfs(i, currBoot);
		}
	}
	//every possible boot
	for (int i = currBoot+1; i < b; i++)
	{
		if (tiles[loc] <= boots[i].first)
		{
			dfs(loc, i);
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
	cin >> n >> b;
	
	 // fill all the tiles vector
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		tiles.push_back(temp);
	}
	//set up vector in correct order
	for (int i = 0; i < b; i++)
	{
		int s; int d; cin >> s >> d;
		boots.push_back(make_pair(s, d));
	}

	dfs(0, 0);

	cout << ans;

	/*
	int pos = 0;
	int ans = 0;
	while (pos < n - 1)
	{
		boot currBoot = boots.top();
		int ogpos = pos;
		if (pos + currBoot.second > n - 1)
		{
			currBoot.second = n - 1 - pos;
		}
		for (int i = 0; i < currBoot.second; i++)
		{
			if (currBoot.first >= tiles[pos + currBoot.second - i] and currBoot.first >= tiles[pos])
			{
				pos = pos + currBoot.second - i;
				break;
			}
		}
		if (ogpos == pos)
		{
			boots.pop();
			ans++;
		}
	}
	cout << ans;
	*/
}