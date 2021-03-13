#include<bits/stdc++.h>
using namespace std;

bool decreasing(int a, int b)
{
	return a > b;
}

bool decreasingDif(pair<int,int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	return a.first > b.first;
}
int diff = 0;
int n; int k;
int main()
{
	cin >> n >> k;
	vector<int> ancestors;
	vector<int> ceilings;
	vector<pair<int, int>> differences;

	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		ancestors.push_back(a);
	}
	sort(ancestors.begin(), ancestors.end(), decreasing);

	for (auto x : ancestors) // add to ceilings vector
	{
		ceilings.push_back(ceil(x/12.0));
	}

	for (int i = 0; i < n - 1; i++) //n-1 size difference vector of ancestors
	{
		differences.push_back(make_pair(ancestors[i] - ancestors[i+1],i+1));
	}
	sort(differences.begin(), differences.end(), decreasingDif);

	int minYears = 0;
	int currYear = ceilings[0];
	int visited = 0;
	for (int i = 0; i < k - 2; i++)
	{
		minYears += 12 * abs(currYear - (ancestors[differences[i].second - 1] / 12));
		visited += differences[i].second;
		currYear = ceilings[differences[i].second];
		if (currYear >= ceilings[differences[n-2].second-1])
		{
			break;
		}
	}
	minYears += 12*( currYear - ancestors[n - 1] / 12);

	cout << minYears;
}