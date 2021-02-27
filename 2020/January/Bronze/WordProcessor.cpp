#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("word.in", "r", stdin);
	freopen("word.out", "w", stdout);

	int n; int k;
	cin >> n >> k;
	
	int currPos = 0;
	int currSize = 0;

	vector<string> words;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		words.push_back(s);
	}
	for (int i = 0; i < n; i++)
	{
		if (currSize + words[i].size() > k)
		{
			currPos++;
			currSize = 0;
			cout << "\n";
		}

		currSize += words[i].size();
		cout << words[i];
		if (i != n-1 and words[i+1].size() <= k-currSize)
		{
			cout << " ";
		}
	}
	/*
	vector<vector<string>> answers;

	answers.push_back({});
	

	int currPos = 0;
	int currSize = 0;

	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		if (currSize + s.size() > k)
		{
			currPos++;
			currSize = 0;
			answers.push_back({});
		}

		currSize += s.size();
		answers[currPos].push_back(s);
	}

	for (auto line : answers)
	{
		for (auto word : line)
		{
			cout << word;
			if(!(word == line[line.size()-1]))
			{
				cout << " ";
			}
		}
		cout << "\n";
	} */
}