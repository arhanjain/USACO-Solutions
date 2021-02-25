#include <bits/stdc++.h>
using namespace std;

const int maxn = 100001;

vector<int> p_sum(maxn);
vector<int> s_sum(maxn);
string s; int n;

void solve(vector<int> &p)
{
	stack<char> colors;
	
	for (int i = 0; i < n; i++)
	{
		p[i + 1] = p[i];
		while (!colors.empty() and colors.top() > s[i])
		{
			colors.pop();
		}
		if (colors.empty() or colors.top() < s[i])
		{
			colors.push(s[i]);
			p[i + 1]++;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> n >> q >> s;

	solve(p_sum);
	reverse(s.begin(), s.end());
	solve(s_sum);
		
	for (int i = 0; i < q; i++)
	{
		int a; int b;
		cin >> a >> b;
		
		cout << p_sum[a - 1] + s_sum[n - b] << "\n";
	}

}