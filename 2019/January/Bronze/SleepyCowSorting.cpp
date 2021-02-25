#include<bits/stdc++.h>
using namespace std;

int N = 0;
vector<int> ordered;
vector<int> decSet;

int main()
{
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);

	cin >> N;

	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		ordered.push_back(temp);
	}

	for (int i = N - 1; i >= 0; i--)
	{
		if (i == N - 1)
		{
			decSet.insert(decSet.begin(), ordered[i]);
			ordered.erase(ordered.begin()+i);
		}
		else if (ordered[i] < decSet[0])
		{
			decSet.insert(decSet.begin(), ordered[i]);
			ordered.erase(ordered.begin() + i);
		}
		else
		{
			break;
		}
	}

	//for (int i = 0; i < ordered.size(); i++)

	cout << ordered.size();
	
}