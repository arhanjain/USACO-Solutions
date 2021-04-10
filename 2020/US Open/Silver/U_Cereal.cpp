#include<bits/stdc++.h>
using namespace std;

//typedef pair<int, int> cow; //first choice, second choice

struct cow
{
	int f;
	int s;
	int order;
};

const int maxn = 100001;
cow cereals[maxn];
cow cows[maxn];
vector<int> answers;
vector<int> psum;
int n; int m;

int dfs(cow c)
{
	int delta = 0;
	if (cereals[c.f].f == 0)
	{
		cereals[c.f] = c;
		delta++;
	}
	else 
	{
		if (c.order < cereals[c.f].order)
		{
			delta += dfs(cereals[c.f]);
			cereals[c.f] = c;
		}
		else if (c.order < cereals[c.s].order)
		{
			delta += dfs(cereals[c.s]);
			cereals[c.s] = c;
		}
	}
	return delta;
}

int main()
{
	psum.push_back(0);
	ios_base::sync_with_stdio(0); cin.tie(0);

	//freopen("cereal.in", "r", stdin);
	//freopen("cereal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cow currCow;
		cin >> currCow.f >> currCow.s;
		currCow.order = i;
		cows[i] = currCow;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		psum.push_back(psum[psum.size() - 1] + dfs(cows[i]));
		answers.push_back(psum[psum.size() - 1]);
	}
		
	for (int i = answers.size() - 1; i >= 0; i--)
	{
		cout << answers[i] << "\n";
	}
}
	
