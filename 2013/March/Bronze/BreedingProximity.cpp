#include<bits/stdc++.h>
using namespace std;

int main()
{

	freopen("proximity.in", "r", stdin);
	freopen("proximity.out", "w", stdout);
	int n; int k; cin >> n >> k;

	vector<int> cows;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		cows.push_back(a);
	}

	vector<int> poss;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (cows[i] == cows[j] and j-i <= k)
			{
				poss.push_back(cows[i]);
			}
		}
	}

	if (poss.size() > 0) cout << *max_element(poss.begin(), poss.end());
	else cout << -1;
}