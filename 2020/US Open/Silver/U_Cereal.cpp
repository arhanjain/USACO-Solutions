#include<bits/stdc++.h>
using namespace std;
/*
pair<int,int> binSearch(int L, int R, int target)
{
	while (L <= R)
	{
		int mid = 
	}
}*/
//STOPPPPPPPPPPPPPPPPPPPPPPPPP
vector<int> cereals;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	freopen("cereal.in", "r", stdin);
	freopen("cereal.out", "w", stdout);

	int n; int m;
	cin >> n >> m;
	vector<int> psum;
	vector<int> firstChoice;
	vector<int> secondChoice;
	for (int i = 0; i < n; i++)
	{
		int a; int b;
		cin >> a >> b;
		firstChoice.push_back(a-1);
		secondChoice.push_back(b-1);
		psum.push_back(0);
	}
	for (int i = 0; i < m; i++)
	{
		cereals.push_back(-1);
	}


	cereals[firstChoice[n - 1]] = n - 1;
	psum[n-1] = 1;
	for (int i = n - 2; i >= 0; i--)
	{
		int first = cereals[firstChoice[i]];
		psum[i] = psum[i+1];
		if (first != -1) // if first choice square is filled
		{
			if (cereals[secondChoice[first]] != -1)
			{
				if (cereals[secondChoice[first]] > first)
				{
					cereals[secondChoice[first]] = first;
				}
				cereals[firstChoice[i]] = i;
			}
			if (cereals[secondChoice[first]] == first)
			{
				cereals[firstChoice[i]] = i;
			}
			else
			{
				cereals[secondChoice[first]] = first;
				cereals[firstChoice[i]] = i;
				psum[i]++;
			}
			
		}
		else
		{
			cereals[firstChoice[i]] = i;
			psum[i]++;
		}
	}

	for (auto i : psum)
	{
		cout << i << "\n";
	}
		
}
	
