#include <bits/stdc++.h>
using namespace std;

vector<int> adjMat[1000];
int subtract = 0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;

	vector<int> xpos;
	vector<int> ypos;

	int x; int y;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		xpos.push_back(x);
		ypos.push_back(y);
	}

	for (int i = 0; i < n; i++)
	{
		int lower = 0;
		int higher = 0;
		int right = 0;
		int left = 0;

		for (int j = 0; j < n; j++)
		{
			if (ypos[j] < ypos[i])
			{
				lower++;
			}
			if (ypos[j] > ypos[i])
			{
				higher++;
			}
			if (xpos[j] < xpos[i])
			{
				left++;
			}
			if (xpos[j] > xpos[i])
			{
				right++;
			}
		}
		
		vector<int> all = { lower, higher, left, right };
		subtract += *min_element(all.begin(), all.end());
	}

	cout << pow(2, n) - subtract;
}