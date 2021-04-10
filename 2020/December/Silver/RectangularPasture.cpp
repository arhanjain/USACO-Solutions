#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> point;

bool xsort(point a, point b)
{
	return a.first < b.first;
}

bool ysort(point a, point b)
{
	return a.second < b.second;
}
int psum[2501][2501] = { 0 };

int rsum(int x1, int y1, int x2, int y2)
{
	return psum[x2 + 1][y2 + 1] - psum[x1][y2 + 1] - psum[x2 + 1][y1] + psum[x1][y1];
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<pair<int, int>> cows;
	for (int i = 0; i < n; i++)
	{
		int x; int y; cin >> x >> y;
		cows.push_back(make_pair(x, y));
	}
	
	//re number them and have them sorted by y in the end
	sort(cows.begin(), cows.end(), xsort);
	for (int i = 0; i < n; i++)
	{
		cows[i].first = i + 1;
	}
	sort(cows.begin(), cows.end(), ysort);
	for (int i = 0; i < n; i++)
	{
		cows[i].second = i + 1;
	}

	
	for (int i = 0; i < n; i++)
	{
		psum[cows[i].first][cows[i].second] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
		}
	}

	long long ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int l = min(cows[i].first, cows[j].first)-1;
			int r = max(cows[i].first, cows[j].first)-1;
			ans += rsum(0, i, l, j) * rsum(r, i, n - 1, j);
		} 
	}

	cout << ans + 1;
}