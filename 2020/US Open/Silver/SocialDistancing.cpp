#include <bits/stdc++.h>
using namespace std;

int n; int m;
vector<pair<long long, long long>> grass;
vector<int> placements[61];

bool sortIntervals(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

bool distWorks(long long dist)
{
	long long lastPlaced = 0-dist;
	int cowsPlaced = 0;
	for (auto i : grass)
	{
		while (max(lastPlaced + dist, i.first) <= i.second) {
			lastPlaced = max(lastPlaced + dist, i.first);
			cowsPlaced++;
			if (cowsPlaced >= n) return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		pair<int, int> temp;
		cin >> temp.first >> temp.second;
		grass.push_back(temp);
	}
	
	//sort grass intervals
	sort(grass.begin(), grass.end(), sortIntervals);

	//long long L = grass[0].first; long long R = grass[m - 1].second;

	long long L = 0; long long R = 1000000000000000000;
	long long workingDist = 1;
	while (L <= R)
	{
		long long mid = L + (R - L) / 2;
		if (distWorks(mid))
		{
			L = mid + 1;
			workingDist = mid;
		}
		else
		{
			R = mid - 1;
		}
	}

	cout << workingDist;
}