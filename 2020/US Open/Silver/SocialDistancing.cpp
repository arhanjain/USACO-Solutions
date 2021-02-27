#include <bits/stdc++.h>
using namespace std;

int n; int m;

int main()
{


	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
	
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	if (n > m)
	{
		int totGrass = 0;
		for (int i = 0; i < m; i++)
		{
			int a; int b;
			cin >> a >> b;

			totGrass += b - a + 1;
		}

		cout << (totGrass / n) + 1;
	}
	else
	{

	}
	
}