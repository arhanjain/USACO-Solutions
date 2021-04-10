#include<bits/stdc++.h>
using namespace std;

const int maxn = 100000;
int n; int k; int l;
vector<int> papers;
vector<int> possible;

bool isPossible(int target)
{
	//int goal = target * target;
	vector<int> diffs;
	for (int i = 0; i < target; i++)
	{
		int diff = target - papers[i];
		if (diff <= 0) diff = 0;
		else diffs.push_back(diff);
	}
	//if (citable < 1) citable = 1;
	int sum = 0;
	for (int i = 0; i < diffs.size(); i++)
	{
		if (diffs[i] > k) return false;
		sum += diffs[i];
	}
	if (sum > l * k) return false;
	return true;
}

int main()
{
	cin >> n >> k >> l;
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		papers.push_back(temp);
	}
	sort(papers.begin(), papers.end());
	reverse(papers.begin(), papers.end());

	//binary search on what is possible
	int mid = -1;;
	int L = 0; int R = n;

	
	while (L < R)
	{
		if (mid == (L + R) / 2)
		{
			mid++;
			bool result = isPossible(mid);
			if (result) break;
			else
			{
				mid--;
				break;
			}
		}
		else mid = (L + R) / 2;

		bool result = isPossible(mid);
		if (result)
		{
			L = mid;
		}
		else
		{
			R = mid;
		}
	}
	
	cout << mid;
}