#include<bits/stdc++.h>
using namespace std;

struct peak
{
	int start;
	int end;
};

bool sortPeaks(peak a, peak b)
{
	if (a.start == b.start)
	{
		return a.end > b.end;
	}
	return a.start < b.start;
}

vector<peak> peaks;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);

	int n; cin >> n;

	//take in all the peaks
	for (int i = 0; i < n; i++)
	{
		int a; int b;
		cin >> a >> b;

		peak temp;
		temp.start = a - b;
		temp.end = a + b;

		peaks.push_back(temp);
	}

	//sort peaks in descending start coords
	sort(peaks.begin(), peaks.end(), sortPeaks);

	//in descending order, counting visible peaks
	int visible = 1;
	int maxend = peaks[0].end;
	for (int i = 1; i < n; i++)
	{
		if(peaks[i].end > maxend)
		{
			visible++;
			maxend = peaks[i].end;
		}
	}

	cout << visible;
}