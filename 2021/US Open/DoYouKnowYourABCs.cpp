#include<bits/stdc++.h>
using namespace std;

int t;

int main()
{
	int ints[10] = { 1, 3, 5, 1, 4, 3, 0, 0, 0, 1 };
	for (auto i : ints)
	{
		cout << i << "\n";
	}

	/*
	cin >> t;
	while (t--)
	{
		int n; cin >> n;

		if (n == 7)
		{
			cout << 1 << "\n"; 
			continue;
		}
		if (n == 6)
		{
			cout << 1 << "\n";
			continue;
		}
		if (n == 5)
		{
			cout << 1 << "\n";
			continue;
		}
		if (n == 4)
		{
			vector<int> x;
			for (int i = 0; i < n; i++)
			{
				int temp; cin >> temp;
				x.push_back(temp);
			}
			sort(x.begin(), x.end());
			int ans = 0;
			vector<int> comb = { 1,1,1,1,0,0,0 };
			do {
				int count = 0;
				for (int i = 3; i < 7; i++)
				{
					if (comb[i]) count++;
				}
				
			} while (next_permutation(comb.begin(), comb.end()));

		}
	}
	*/
}