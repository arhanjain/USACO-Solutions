#include<bits/stdc++.h>	
using namespace std;

const int maxn = 100000;

vector<int> psum(maxn);
vector<int> broken(maxn);
vector<int> diffs;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);

	int n; int k; int b;
	cin >> n >> k >> b;

	for (int i = 0; i < b; i++)
	{
		int a; cin >> a; a--;
		broken[a] = 1;
	}

	if (broken[0] == 1)
	{
		psum[0]++;
	}
	for (int i = 1; i < n; i++)
	{
		psum[i] = psum[i - 1];
		if (broken[i] == 1)
		{
			psum[i]++;
		}
	}

	for (int i = 0; i < n-k; i++)
	{
		diffs.push_back(psum[i+k] - psum[i]);
	}

	cout << *min_element(diffs.begin(), diffs.end());
}