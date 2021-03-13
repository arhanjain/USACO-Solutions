#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	vector<string> answers;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str; cin >> str;
		int turn = 0; // clockwise = 4, ccw = -4
		for (int i = 1; i < str.size(); i++)
		{
			if (str[i] == 'N' and str[i - 1] == 'W') turn++;
			else if (str[i] == 'E' and str[i - 1] == 'N') turn++;
			else if (str[i] == 'S' and str[i - 1] == 'E') turn++;
			else if (str[i] == 'W' and str[i - 1] == 'S') turn++;
			else if (str[i] == str[i - 1]) {}
			else turn--;
		}
		if (turn > 0) answers.push_back("CW");
		else answers.push_back("CCW");
	}
	for (auto i : answers)
	{
		cout << i << "\n";
	}
}