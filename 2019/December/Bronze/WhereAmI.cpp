#include <bits/stdc++.h>
#include<vector>
#include<set>
#include<string>
using namespace std;
int N;
string mailboxes;

bool multipleSequences (int length)
{
	set<string> unique;
	for (int i = 0; i <= N - length; i++)
	{
		if (unique.count(mailboxes.substr(i, length)) > 0)
		{
			return true;
		}
		unique.insert(mailboxes.substr(i,length));
	}
	return false;
}

int main()
{
	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);
	
	cin >> N >> mailboxes;


	int pos = 1;
	while (multipleSequences(pos))
	{
		pos++;
	}
	
	cout << pos;
}